#include "StarObject.h"
#include "StarChild.h"
#include "../Map/MapObject.h"
#include "../ObjectManager.h"
#include "../../Skill.h"
#include "../../Scene/SceneManager.h"

#include <cmath>
namespace {

	const float GRAVITY        = 0.2f;	//重力
	const int   BOOST          = 3;		//倍速
	const int   MAX_CHILDS     = 5;		//子の最大数
	const float JUMP_POINT	   = 128.f;	//ジャンプ基準値
	const float LOW_JUMP_POWER = -1.2f;  //最低ジャンプ力
}

//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x, y, rot)
{
	m_speed      = 2.8f;
	m_width      = 64;
	m_height     = 64;
	m_vel.x      = 0;
	m_jump_power = -6.5f;
	m_interval   = 60.f;
	m_is_active  = false;
	m_cur_child  = nullptr;
	m_map_obj    = nullptr;
	m_is_fall	 = false;
	m_cur_y		 = 0.f;
	m_gravity    = 0.f;
	m_rot_speed = 1.3f;
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
		/*AddForce(0, 0, 0);
		RefPosition();*/
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
}

//-----------------------------------
// 頂点座標の設定
void StarObject::SetVertex(DWORD color) {

	float ox = 0.f;
	float oy = 0.f;
	m_vtx[0].pos = { m_pos.x - m_width , m_pos.y - m_height, 0.f,1.f };
	m_vtx[1].pos = { m_pos.x + m_width, m_pos.y-m_height, 0.f,1.f };
	m_vtx[2].pos = { m_pos.x + m_width, m_pos.y + m_height,0.f, 1.f };
	m_vtx[3].pos = { m_pos.x -m_width,  m_pos.y + m_height, 0.f, 1.f };
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
		RefPosition();
	}
	else{
		m_gravity = 0.f;
		//子供からもらったスキルを発動する
		m_cur_skill = m_cur_child->GetSkill();
		CauseToSkill(m_cur_skill);
	}

	for (auto child : m_childs) {
		
		if (child->GetHit()) {
			m_is_fall = false;
			m_jump_power = -6.5f;
			m_cur_y = m_pos.y;	 //スキル発動前のY座標を保存
			m_cur_child	= child; //子オブジェクト取得
			m_map_obj=(MapObject*)m_cur_child->GetMapObj(); //マップオブジェクト取得

			if (m_map_obj->GetGoal()) {
				return;
			}
		}
	}

	if (m_map_obj != nullptr&& m_cur_child != nullptr) {
		CheckOutSideTheMapObject(m_map_obj, m_cur_child);
	}
}

//------------------------------------
//　マップオブジェクトを超えた場合の処理
void StarObject::CheckOutSideTheMapObject(
	MapObject* map_,
	StarChild* hit_child
) {
	
	MapObject* map = map_;

	if (map != nullptr) {
		float left   = map->GetVertex(0).pos.x;
		float right  = map->GetVertex(1).pos.x;
		float height = map->GetVertex(0).pos.y;
		float p      = hit_child->GetVertex(1).pos.x; //頂点

		if ( p > right || m_pos.y > height) {
			//頂点がオブジェクトの外にいる場合
			m_is_active = false;
		
		}
		else if ( p > left && p < right) {
			//頂点がオブジェクトの範囲内にいる場合
			m_is_active = true;

			if (m_cur_skill != JUMP) {
				//ジャンプ以外の場合はめり込みを修正する
				m_pos.y += m_cur_child->DistanceToCeiling();
			}
		}
	}
}

//------------------------------------
// スキル発動処理
void StarObject::CauseToSkill(int skill_id) {

	switch (skill_id)
	{
	case NORMAL:
		AddForce(m_speed,0.f,2.5f);
		RefPosition();
		m_interval = 60.f;
		m_is_fall = false;
		break;

	case SPEED:
		AddForce(m_speed* BOOST);
		RefPosition();
		break;

	case JUMP:
		if (m_is_fall == false) {
			JumpMotion();
		}
		else {
			FallMotion();
		}
		break;

	case STOP:
		StopMotion();
		break;

	case LIGHT://未実装
		m_vel.y = 0.f;
		break;
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
void StarObject::RefPosition() {

	m_pos.x += m_vel.x;
	m_pos.y += m_vel.y;
}

//--------------------------------
// ジャンプモーション
void StarObject::JumpMotion(){

	float max_y = 0.f;
	max_y = m_cur_y - JUMP_POINT;
	
	if (max_y < m_pos.y) {
		//ジャンプ最高点に達するまで
		AddForce(0.8f, m_jump_power,0.f);
		RefPosition();
		m_jump_power += 0.2f;

		if (m_jump_power >= LOW_JUMP_POWER) {
			m_jump_power =  LOW_JUMP_POWER;
		}
	}
	else {
		m_is_fall = true;
	}
}

void StarObject::FallMotion() {
		
	m_jump_power += 0.2f;
	AddForce(m_speed, m_jump_power);
	RefPosition();
}

void StarObject::StopMotion() {

	if (m_cur_child != nullptr) {
		
		if (m_cur_child->GetHit()) {
			--m_interval;
		}
		else {
			m_interval = 60.f;
			AddForce(m_speed, 0, m_rot_speed);
			RefPosition();
		}
	}

	//頂点が当たっている間の処理
	if (m_interval > 0) {
		AddForce(0, 0, 0);
		RefPosition();
	}
	else {
		AddForce(m_speed, 0, m_rot_speed);
		RefPosition();
	}
}

