#include "StarObject.h"
#include "StarChild.h"
#include "MapObject.h"
#include "ObjectManager.h"
#include "../Skill.h"
#include "../Scene/SceneManager.h"

#include <cmath>
namespace {

	/* Todo:　Gravity
	　　落ちるタイプのステージオブジェクトがあれば
		ObjectBaseへ移動する
	*/
	const float GRAVITY  = 0.98f;
	const int   BOOST = 3;
	const int MAX_CHILDS = 5;
	const float JUMP_POINT= 128.f;//ジャンプ基準値
}


//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x, y, rot)
{
	m_speed  = 2.8f;
	m_width  = 64;
	m_height = 64;
	m_vel.x  = 0;
	m_jump_power = -6.5f;
	m_interval   = 60.f;
	m_is_active  = false;
	m_cur_child  = nullptr;
	m_map_obj    = nullptr;
	is_fall		 = false;
	m_inset_y    = 0.f;
	cur_y		 = 0.f;
	vertex		 = 0.f;
	gravity		 = 0.f;
}

//-----------------------------------
//　更新処理
void StarObject::Update() {
	
	auto mng = ObjectManager::GetInstance();
	//子オブジェクトを一度だけ取得する
	if (m_childs.size() < MAX_CHILDS) {
		m_childs = mng.GetGameObjects<StarChild>();
	}

	//自動操縦
	AutomaticMove();

	SceneBase* gc = SceneManager::GetInstance().GetScene();

	float out_w = m_pos.x + m_width;
	float out_h = m_pos.y + m_height;

	if (out_h > WINDOW_H || out_w> WINDOW_W) {
		gc->SetResult(FAILD);
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

	if (!m_is_active) {
		gravity += 0.1f;
		//スキルが発動していない場合
		AddMoveAmount(m_speed, gravity);
		RefPosition();
	}
	else{
		//子供からもらったスキルを発動する
		CauseToSkill(m_cur_child->GetSkill());
	}

	for (auto child : m_childs) {
		
		if (child->GetHit()) {
			m_cur_child	= child; //子オブジェクト取得
			m_map_obj=(MapObject*)m_cur_child->GetMapObj(); //マップオブジェクト取得
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
	StarChild* child
) {
	
	MapObject* map = map_;

	if (map != nullptr) {
		float left   = map->GetVertex(0).pos.x;
		float right  = map->GetVertex(1).pos.x;
		float height = map->GetVertex(0).pos.y;
		float p      = child->GetVertex(1).pos.x;

		if ( p > right || m_pos.y > height) {
			//頂点がオブジェクトの外にいる場合
			m_is_active = false;
		}
		else if ( p > left && p < right) {
			//頂点がオブジェクトの範囲内にいる場合
			m_is_active = true;
		}
	}
}

//------------------------------------
// スキル発動処理
void StarObject::CauseToSkill(int skill_id) {

	switch (skill_id)
	{
	case NORMAL:
		AddMoveAmount(m_speed,0.f,2.5f);
		RefPosition();
		m_interval = 60.f;
		cur_y = m_pos.y;
		is_fall = false;
		break;

	case SPEED:
		AddMoveAmount(m_speed* BOOST);
		RefPosition();
		break;

	case JUMP:
		if (is_fall == false) {
			JumpMotion();
		}
		else {
			FallMotion(is_fall);
		}
		break;

	case STOP:
		StopMotion();
		break;

	case LIGHT:
		m_vel.y = 0.f;
		break;
	}	
}

//--------------------------------
// 移動量を追加する
void StarObject::AddMoveAmount(
	float x, float y,
	float rot
) {
	m_vel.x = x;
	m_vel.y = y;
	m_rot += rot;
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
	max_y = cur_y - JUMP_POINT;
	
	if (max_y < m_pos.y) {
		//ジャンプ最高点に達していない
		AddMoveAmount(0, m_jump_power,0.f);
		RefPosition();
		m_jump_power += 0.2f;
		if (m_jump_power >= -1.2f) {
			m_jump_power = -1.2f;
		}
	}
	else {
		is_fall = true;
	}
	
}

void StarObject::FallMotion(bool is_fall) {
		
	m_jump_power += 0.2f;
	AddMoveAmount(m_speed, m_jump_power);
	RefPosition();
	CheckOutSideTheMapObject(m_map_obj, m_cur_child);

}

void StarObject::StopMotion() {

	if (--m_interval > 0) {
		AddMoveAmount(0.f, 0.f, 0.f);
		RefPosition();
	}

}

