#include "StarObject.h"
#include "StarChild.h"
#include "MapObject.h"
#include "ObjectManager.h"
#include "../Lib/Lib.h"
#include "../Skill.h"

namespace {

	/* Todo:　Gravity
	　　落ちるタイプのステージオブジェクトがあれば
		ObjectBaseへ移動する
	*/
	const float GRAVITY  = 1.6f;
	const int   BOOST = 3;
	const int MAX_CHILDS = 5;
}
//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x, y, rot)
{
	m_speed  = 1.3f;
	m_width  = 128;
	m_height = 128;
	m_vel.x  = 0;
	m_jump_power    = -3.f;
	m_jump_interval = 60.f;
	m_is_active = false;
	m_cur_child = nullptr;
	m_cur_obj   = nullptr;
}

//-----------------------------------
//　更新処理
void StarObject::Update() {
	
	auto mng = ObjectManager::GetInstance();
	//子オブジェクトを一度だけ取得する
	if (m_childs.size() < MAX_CHILDS) {
		m_childs = mng.GetGameObjects<StarChild>();
	}

	if (m_map_obj.size() < MAX_OBJ_NUM) {
		m_map_obj = mng.GetGameObjects<MapObject>();
	}

	AutomaticMove();
	if (m_cur_child != nullptr) {
		SkillActive(m_cur_child->GetSkill());
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
	m_vtx[0].pos = { ox , oy,0.f,1.f };
	m_vtx[1].pos = { ox + m_width, oy, 0.f,1.f };
	m_vtx[2].pos = { ox + m_width, oy + m_height,0.f, 1.f };
	m_vtx[3].pos = { ox, oy + m_height, 0.f, 1.f };
}

//-----------------------------------
// 自動操作
void StarObject::AutomaticMove() {

	

	if (!m_is_active) {

		m_vel.x = m_speed;
		m_pos.x += m_vel.x;
		m_vel.y = GRAVITY;
		++m_rot;
		m_pos.y += m_vel.y;
	}
	
	float hit_obj_w = 0;
	
	for (auto child : m_childs) {
		
		//オブジェクトと各頂点があたっているか
		if (child->GetHit()) {
			m_cur_child = child;
			hit_obj_w = child->GetHitObjWidth();
			//頂点が当たった
			m_is_active = true;
		}
	}

	if (m_pos.x >= hit_obj_w) {
		m_is_active = false;
	}
}

//------------------------------------

void StarObject::SkillActive(int skill_id) {

	switch (skill_id)
	{
	case NORMAL:
		//何も発動しない
		m_vel.x = m_speed;
		m_vel.y = 0.f;
		++m_rot;

		m_pos.x += m_vel.x;
		m_pos.y += m_vel.y;

		break;
	case SPEED:
		//X移動量を倍にする
		m_vel.y = 0.f;
		m_vel.x = m_speed * BOOST;

		m_pos.x += m_vel.x;
		m_pos.y += m_vel.y;;
		++m_rot;
		break;
	case JUMP:
		//Y移動量を追加する
		Jump();
		break;
	case STOP:

		m_vel.y = 0.f;
		break;
	case LIGHT:
		m_vel.y = 0.f;
		break;
	}
}

void StarObject::Jump(){


	if (--m_jump_interval > 0) {
		m_vel.y = m_jump_power;
		m_vel.x = m_speed;
		m_pos.y += m_vel.y;
		m_pos.x += m_vel.x;
	}
	else {
		m_vel.x = m_speed;
		m_vel.y = GRAVITY;
		++m_rot;
		m_pos.x += m_vel.x;
		m_pos.y += m_vel.y;
	}

	

}
