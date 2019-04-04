#include "StarChild.h"
#include "StarObject.h"

//------------------------------------
//　コンストラクタ
StarChild::StarChild(float x, float y) {

}

void StarChild::Update() {

}

void StarChild::Draw() {

}

//-------------------------------------
//親の座標を自身に反映する
void StarChild::RefParentVertex(Vertex vtx[4]) {

	//親の座標を取得
	float pos_x = m_parent->GetX();
	float pos_y = m_parent->GetY();

	//親の回転角を取得
	float sin = sinf(D3DXToRadian(m_parent->GetRot()));
	float cos = cosf(D3DXToRadian(m_parent->GetRot()));

	float vtx_pos_x = 0.f;
	float vtx_pos_y = 0.f;

	for (int i = 0; i < 4; ++i) {

		//ローカル座標XYを保存
		vtx_pos_x = vtx[i].pos.x;
		vtx_pos_y = vtx[i].pos.y;

		//回転を合成した新座標を設定
		float new_x = (vtx_pos_x * cos) + (vtx_pos_y * -sin);
		float new_y = (vtx_pos_x * cos) + (vtx_pos_y * sin);
	
		//相対座標を設定する
		vtx[i].pos.x = new_x + pos_x;
		vtx[i].pos.y = new_y + pos_y;
	}

}