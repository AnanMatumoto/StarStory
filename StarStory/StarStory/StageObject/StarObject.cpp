#include "StarObject.h"
#include "StarChild.h"
#include "MapObject.h"
#include "ObjectManager.h"
#include "../Lib/Lib.h"
#include "../Skill.h"

#include <cmath>
namespace {

	/* Todo:　Gravity
	　　落ちるタイプのステージオブジェクトがあれば
		ObjectBaseへ移動する
	*/
	const float GRAVITY  = 1.6f;
	const int   BOOST = 3;
	const int MAX_CHILDS = 5;
	const float JUMP_POINT= 50.f;//ジャンプ基準値
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
	m_interval = 60.f;
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

	//ステージオブジェクトを一度だけ取得する
	if (m_map_obj.size() < MAX_OBJ_NUM) {
		m_map_obj = mng.GetGameObjects<MapObject>();
	}

	//自動操縦
	AutomaticMove();

	if (m_cur_child != nullptr) {
		//子供からもらったスキルを発動する
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
		//スキルが発動していない場合
		AddMoveAmount(m_speed, GRAVITY);
		RefPosition();
	}

	float hit_obj_w = 0;
	
	for (auto child : m_childs) {

		//オブジェクトと各頂点があたっている
		if (child->GetHit()) {
			m_cur_child = child;
			//オブジェクトの幅を取得
			hit_obj_w = child->GetHitObjWidth();
			m_is_active = true;
		}
	}

	//オブジェクトの幅を超えたらスキルを非アクティブにする
	if (m_pos.x >= hit_obj_w) {
		m_is_active = false;
	}
	
}

//------------------------------------

void StarObject::SkillActive(int skill_id) {

	switch (skill_id)
	{
	case NORMAL://スキルセットなし
		AddMoveAmount(m_speed);
		RefPosition();
		m_interval = 60.f;
		break;

	case SPEED://加速スキル
		AddMoveAmount(m_speed* BOOST);
		RefPosition();
		break;

	case JUMP://ジャンプスキル
		JumpMotion();
		break;
	case STOP://停止スキル

		m_vel.y = 0.f;
		break;
	case LIGHT://光るスキル
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


	if (--m_interval > 0) {
		//ジャンプ時間内である
		AddMoveAmount(m_speed, m_jump_power,0.f);
		RefPosition();
	}
	else {
		AddMoveAmount(0.f, GRAVITY, 0.f);
		RefPosition();
	}

}
