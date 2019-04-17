#include "StarObject.h"
#include "StarChild.h"
#include "ObjectManager.h"
#include "../Lib/Lib.h"

const float GRAVITY = 1.3f;

//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x, y, rot)
{
	m_speed = 1.f;
	m_width = 128;
	m_height = 128;
	m_vel.x = 0;

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

	++m_rot;
	m_vel.x = m_speed;
	m_pos.x += m_vel.x;
	m_vel.y = GRAVITY;

	for (auto it : m_childs) {
		it->IsHitToObject();
		StarChild* child = it;
		//オブジェクトと各頂点があたっているか
		if (child->GetHit()) {
			//頂点が当たった
			m_vel.y = 0;
		}
	}
	m_pos.y += m_vel.y;
}

