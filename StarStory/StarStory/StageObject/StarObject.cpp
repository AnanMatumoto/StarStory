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
	m_jump_power = -2.5f;
	m_interval   = 60.f;
	m_is_active  = false;
	m_cur_child  = nullptr;
	m_cur_obj    = nullptr;
	m_inset_y    = 0.f;
}

//-----------------------------------
//　更新処理
void StarObject::Update() {
	
	auto mng = ObjectManager::GetInstance();
	//子オブジェクトを一度だけ取得する
	if (m_childs.size() < MAX_CHILDS) {
		m_childs = mng.GetGameObjects<StarChild>();
	}

	if (m_cur_child != nullptr) {
		//子供からもらったスキルを発動する
		SkillActive(m_cur_child->GetSkill());
	}

	//自動操縦
	AutomaticMove();



	SceneBase* gc = SceneManager::GetInstance().GetScene();
	//AdjustPosY();

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
	m_vtx[0].pos = { ox , oy,0.f,1.f };
	m_vtx[1].pos = { ox + m_width, oy, 0.f,1.f };
	m_vtx[2].pos = { ox + m_width, oy + m_height,0.f, 1.f };
	m_vtx[3].pos = { ox, oy + m_height, 0.f, 1.f };
}

//-----------------------------------
// 自動操作
void StarObject::AutomaticMove() {

	float hit_obj_w = 0;
	float hit_obj_h = 0;
	ObjectBase* obj = nullptr;
	float dis = 0.f;

	if (!m_is_active) {
		//スキルが発動していない場合
		AddMoveAmount(m_speed, GRAVITY);
		RefPosition();
	}

	for (auto child : m_childs) {

		//オブジェクトと各頂点があたっている
		if (child->GetHit()) {
			m_cur_child = child;
			//オブジェクト取得
			obj = m_cur_child->GetMapObj();
			hit_obj_w = obj->GetVertex(1).pos.x;
			hit_obj_h = obj->GetVertex(0).pos.y;
			
			m_pos.y += m_cur_child->DistanceToCeiling()+0.5;
			m_is_active = true;
		}
	}
	//オブジェクトの幅を超えた、またはオブジェクトより下にいる場合
	if (m_pos.x > hit_obj_w||m_pos.y > hit_obj_h) {
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
		m_is_active = false;
		break;
	case STOP://停止スキル
		StopMotion();
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
	m_is_active = false;
}

//--------------------------------
// ジャンプモーション
void StarObject::JumpMotion(){


	if (--m_interval > 0) {
		//ジャンプ時間内である
		AddMoveAmount(0, m_jump_power,0.f);
		RefPosition();
	}
}

void StarObject::StopMotion() {

	if (--m_interval > 0) {
		AddMoveAmount(0.f, 0.f, 0.f);
		RefPosition();
	}
	m_is_active = false;
}

void StarObject::AdjustPosY() {

	float dis = m_pos.y + m_inset_y;

	if (m_is_active) {
		if (dis >m_inset_y) {
			m_pos.y += 1.f;
		}

	}

}