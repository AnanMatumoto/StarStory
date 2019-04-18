#include "StarObject.h"
#include "StarChild.h"
#include "ObjectManager.h"
#include "../Lib/Lib.h"
#include "../Skill.h"

namespace {

	/* Todo:　Gravity
	　　落ちるタイプのステージオブジェクトがあれば
		ObjectBaseへ移動する
	*/
	const float GRAVITY  = 1.6f;
	const int   TWICE_UP = 2;
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
}

//-----------------------------------
//　更新処理
void StarObject::Update() {
	AutomaticMove();
	SetVertex();
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
	m_vtx[0].pos = { ox, oy,0.f,1.f };
	m_vtx[1].pos = { ox + m_width, oy, 0.f,1.f };
	m_vtx[2].pos = { ox + m_width, oy + m_height,0.f, 1.f };
	m_vtx[3].pos = { ox, oy + m_height, 0.f, 1.f };
}

//-----------------------------------
// 自動操作
void StarObject::AutomaticMove() {

	auto mng = ObjectManager::GetInstance();
	m_childs = mng.GetGameObjects<StarChild>();
	
	
	m_vel.x = m_speed;
	m_pos.x += m_vel.x;
	m_vel.y = GRAVITY;
	++m_rot;

	for (auto it : m_childs) {
		it->IsHitToObject();
		StarChild* child = it;
		//オブジェクトと各頂点があたっているか
		if (child->GetHit()) {
			//頂点が当たった
			//SkillActive(child->GetSkill());
			m_vel.y = 0.f;
		}
	}

	m_pos.y += m_vel.y;

}

void StarObject::SkillActive(int skill_id) {

	switch (skill_id)
	{
	case NORMAL:
		//何も発動しない
		m_vel.y = 0.f;
		break;
	case SPEED:
		//X移動量を倍にする
		m_vel.y = 0.f;
		m_vel.x = m_speed * TWICE_UP;
		break;
	case JUMP:
		//Y移動量を追加する
		if (--m_jump_interval <= 0.f) {
			m_vel.y =- m_jump_power;
			m_vel.x = m_speed;
		}
		break;
	case STOP:

		m_vel.y = 0.f;
		break;
	case LIGHT:
		m_vel.y = 0.f;
		break;
	}

}
