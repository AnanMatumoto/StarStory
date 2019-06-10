#include "ObjectBase.h"

//==================================
// オブジェクト基底クラス
//==================================

//---------------------------------
//　フラグを削除状態にセットする
void ObjectBase::Delete() {
	m_is_delete = true;
}

const bool ObjectBase::IsDelete() const {
	return m_is_delete;
}

//---------------------------------
//　X座標ゲッター
const float ObjectBase::GetX() const {
	return m_pos.x;
}

//----------------------------------
// Y座標ゲッター
const float ObjectBase::GetY() const {
	return m_pos.y;
}

const float ObjectBase::GetRot()const {
	return m_rot;
}

//-----------------------------------
//　頂点情報ゲッター（オーバーロード）
const Vertex ObjectBase::GetVertex(int prim_num)const {
	return m_vtx[prim_num];
}

//-----------------------------------
//　矩形用ローカル座標変換
void ObjectBase::BoxLocalTransform(
	Vertex vtx[4],
	float width, float height
) {
	float w_half = width / 2.f;
	float h_half = height / 2.f;

	float pos_x = m_pos.x;
	float pos_y = m_pos.y;

	float sin = sinf(D3DXToRadian(m_rot));
	float cos = cosf(D3DXToRadian(m_rot));

	float vtx_pos_x = 0.f;
	float vtx_pos_y = 0.f;

	for (int i = 0; i < 4; ++i) {

		//各頂点の幅高さの設定
		vtx_pos_x = (i % 3 == 0) ? -w_half : w_half;
		vtx_pos_y = (i < 2) ? -h_half : h_half;

		//回転を合成した新座標を設定
		float new_x = (vtx_pos_x * cos) + (vtx_pos_y*-sin);
		float new_y = (vtx_pos_x * sin) + (vtx_pos_y*cos);

		//ローカル座標を設定する
		vtx[i].pos.x = new_x + pos_x + w_half;
		vtx[i].pos.y = new_y + pos_y + h_half;
	}
}

//-------------------------------------
//　菱形用ローカル座標変換
void ObjectBase::DiamondLocalTransform(
	Vertex vtx[4],
	float width, float height
) {
	float w_half = width / 2.f;
	float h_half = height/ 2.f;

	float pos_x = m_pos.x;
	float pos_y = m_pos.y;

	float sin = sinf(D3DXToRadian(m_rot));
	float cos = cosf(D3DXToRadian(m_rot));

	Vec2 v[4] = {};
	memset(v, 0, sizeof(v));
	
	v[0].x = -w_half;
	v[1].y = -h_half;
	v[2].x = w_half;
	v[3].y = h_half;

	for (int i = 0; i < 4; ++i) {

		float new_x = (v[i].x*cos) + (v[i].y*-sin);
		float new_y = (v[i].x*sin) + (v[i].y*cos);
		
		vtx[i].pos.x = new_x + pos_x;
		vtx[i].pos.y = new_y + pos_y;
		vtx[i].pos.z - 0.2f;
	}
}


//--------------------------------------------
//　オブジェクトと頂点の当たり判定
bool ObjectBase::IsHitToUpper(Vec2 point, ObjectBase* obj) {
	
	//各頂点から線分を作成する
	Vec2 v1(obj->GetVertex(0).pos.x, obj->GetVertex(0).pos.y);
	Vec2 v2(obj->GetVertex(1).pos.x, obj->GetVertex(1).pos.y);
	
	//オブジェクトの頂点と線分との外積判定
	float ans = point.Cross(v1, v2, point);
	if (ans > 0) {
		return true;
	}
	return false;
}

