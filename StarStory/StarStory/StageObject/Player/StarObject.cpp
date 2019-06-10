#include "StarObject.h"
#include "StarChild.h"
#include "../../Skill.h"
#include "../Map/MapObject.h"
#include "../ObjectManager/ObjectManager.h"
#include "../../Scene/SceneManager/SceneManager.h"
#include <cmath>

#define STOP_EFFECT  "Resource/Player/stop_effect.png"
#define SPEED_EFFECT "Resource/Player/speed_effect.png"
#define JUMP_EFFECT  "Resource/Player/jump_effect.png"

int speed = 0;

namespace {

	const float GRAVITY        = 0.2f;	//重力
	const int   BOOST          = 3;		//倍速
	const int   MAX_CHILDS     = 5;		//子の最大数
	const float JUMP_POINT	   = 128.f;	//ジャンプ基準値
}

//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x, y, rot)
{
	m_speed       = 2.8f;
	m_width       = 64;
	m_height      = 64;
	m_vel.x       = 0;
	m_jump_power  = -3.5f;
	m_interval    = 60.f;
	m_cur_y       = 0.f;
	m_gravity     = 0.f;
	m_rot_speed   = 1.3f;
	m_is_fall     = false;
	m_is_active   = false;
	m_cur_child   = nullptr;
	m_map_obj     = nullptr;
	m_effect_anim = AnimationParameter();
}

//-----------------------------------
//　更新処理
void StarObject::Update() {
	
	//子オブジェクトを一度だけ取得する
	if (m_childs.size() < MAX_CHILDS) {
		m_childs = ObjectManager::GetInstance().GetGameObjects<StarChild>();
	}

	float out_w = m_pos.x + m_width;
	float out_h = m_pos.y + m_height;
	
	if (out_h > WINDOW_H || out_w> WINDOW_W) {
		
		//画面外に入った場合はFAILDを通知
		SceneManager::GetInstance().GetScene()->SetResult(FAILD);
	}
	else if(m_map_obj!= nullptr && m_map_obj->GetGoal()){
		
		//ゴール地点で移動終了、CLEARを通知
		m_pos.x = m_map_obj->GetVertex(0).pos.x+m_width;
		m_pos.y = m_cur_y;
		SceneManager::GetInstance().GetScene()->SetResult(CLEAR);
	}
	else {
		AutomaticMove();
	}
}

//------------------------------------
//　描画処理
void StarObject::Draw() {

	SetVertex();
	BoxLocalTransform(m_vtx, m_width, m_height);
	

	
	if (speed >= 0&&m_is_active) {

		Lib::AnimationUV(
			m_effect_anim,
			0.1f,
			128, 128
		);
		++speed;
	}
	else if(speed >m_effect_anim.length){
		speed = 0;
	}

}

//-----------------------------------
// 頂点座標の設定
void StarObject::SetVertex(DWORD color) {

	float ox = 0.f;
	float oy = 0.f;
	m_vtx[0].pos = { m_pos.x - m_width
		, m_pos.y - m_height, 0.3f,1.f };
	m_vtx[1].pos = { m_pos.x + m_width,  m_pos.y-m_height, 0.3f,1.f };
	m_vtx[2].pos = { m_pos.x + m_width,  m_pos.y + m_height,0.3f, 1.f };
	m_vtx[3].pos = { m_pos.x -m_width,   m_pos.y + m_height, 0.3f, 1.f };
}

//-----------------------------------
// 自動操作
void StarObject::AutomaticMove() {

	float hit_obj_w = 0;
	float hit_obj_h = 0;
	float dis = 0.f;

	if (m_is_active==false) {
		//スキルが発動していない場合
		m_gravity += GRAVITY;
		AddForce(m_speed, m_gravity);
		ReflectPosition();
	}
	else{
		m_gravity = 0.f;
		//子供からもらったスキルを発動する
		m_cur_skill = m_cur_child->GetSkill();
		CauseToSkill(m_cur_skill);
	}

	for (auto child : m_childs) {

		if (child->GetHit()) {

			StarChild* hit_child;
			hit_child = child;

			if (hit_child == nullptr) {
				return;
			}
			m_map_obj = (MapObject*)child->GetMapObj();

			ChangeHitChild(hit_child);
		}
	}

	if (m_map_obj != nullptr&& m_cur_child != nullptr) {
		CheckOutSideTheMapObject(m_map_obj, m_cur_child);
	}
}

void StarObject::ChangeHitChild(StarChild* child) {

	if (child!= m_cur_child) {
		ResetParameter();
		m_cur_child = child;
	}


}

void StarObject::ResetParameter() {

	m_is_fall = false;
	m_jump_power = -3.5f;
	m_interval = 60.f;
	m_cur_y = m_pos.y;
}

//------------------------------------
//　マップオブジェクトを超えた場合の処理
void StarObject::CheckOutSideTheMapObject(
	MapObject* map_,
	StarChild* hit_child
) {
	
	MapObject* map = map_;
	if (map == nullptr) {
		return;
	}

	if (hit_child == nullptr) {
		return;
	}

	float left   = map->GetVertex(0).pos.x;
	float right  = map->GetVertex(1).pos.x;
	float top = map->GetVertex(0).pos.y;
	float point  = hit_child->GetVertex(1).pos.x; 

	if ( point > right || m_pos.y > top) {
		//頂点がオブジェクトの外にいる場合
		m_is_active = false;
		if (m_cur_skill == JUMP) {
			m_is_active = true;
		}
	
	}
	else if ( point > left && point < right) {
		//頂点がオブジェクトの範囲内にいる場合
		m_is_active = true;
		
		if (m_cur_skill != JUMP) {
			//ジャンプ以外の場合はめり込みを修正する
			m_pos.y += m_cur_child->GetDistanceToCeiling();
		}
	}
}

//------------------------------------
// スキル発動処理
void StarObject::CauseToSkill(int skill_id) {

	switch (skill_id)
	{
	case NORMAL:
		AddForce(m_speed, 0.f, 2.5f);
		ReflectPosition();
		m_interval = 60.f;
		m_is_fall = false;
		m_effect_anim.SetParameter( 0, 0,{ 0,0 },"none");
		break;

	case SPEED:
		AddForce(m_speed* BOOST);
		ReflectPosition();
		m_effect_anim.SetParameter(
			9, speed/3.f,
			{ m_pos.x-70, m_pos.y-m_height },
			SPEED_EFFECT);
		break;

	case JUMP:
		if (m_is_fall == false) {
			JumpMotion();
			m_effect_anim.SetParameter(
				8, speed,
				{ m_pos.x-m_width, m_pos.y + 23 },
				JUMP_EFFECT);
		}
		else {
			FallMotion();
		}
		
		break;

	case STOP:
		StopMotion();
		m_effect_anim.SetParameter(
			11, speed,
			{ m_pos.x -m_width,m_pos.y-m_height }, STOP_EFFECT);
		break;

	//case LIGHT://未実装
	//	m_vel.y = 0.f;
	//	break;
	}	
}

//--------------------------------
// 移動量を追加する
void StarObject::AddForce(
	float vel_x, float vel_y,
	float rot_speed
) {
	m_vel.x = vel_x;
	m_vel.y = vel_y;
	m_rot += rot_speed;
}

//--------------------------------
// 移動量を座標に反映する
void StarObject::ReflectPosition() {

	m_pos.x += m_vel.x;
	m_pos.y += m_vel.y;
}

//--------------------------------
// ジャンプモーション
void StarObject::JumpMotion(){

	float max_y = 0.f;
	max_y = m_cur_y - JUMP_POINT;
	
	if (max_y <= m_pos.y) {
		//ジャンプ最高点に達するまで
		AddForce(1.4f, m_jump_power,0.f);
		ReflectPosition();
	}
	else {
		m_is_fall = true;
	}
}

void StarObject::FallMotion() {
		
	m_jump_power += 0.2f;
	AddForce(1.4f, m_jump_power);
	ReflectPosition();
}

void StarObject::StopMotion() {

	//頂点が当たっている間の処理
	if (--m_interval > 0) {
		AddForce(0, 0, 0);
		ReflectPosition();
	}
	else {
		AddForce(m_speed, 0, m_rot_speed);
		ReflectPosition();
	}
}

