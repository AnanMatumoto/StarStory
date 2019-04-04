#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject(float x, float y){

	


}

void StarObject::Update() {

}


void StarObject::Draw() {


}

void StarObject::LocalTransform(
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

		//ワールド座標を設定する
		vtx[i].pos.x = new_x + pos_x + w_half;
		vtx[i].pos.y = new_y + pos_y + h_half;
	}



}