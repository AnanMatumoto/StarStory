#include "StarObject.h"
#include "../Lib/Lib.h"

const int  GRAVITY = 1.3f;

//-----------------------------------
//　コンストラクタ
StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x,y, rot
){
	m_speed = 1.f;
	m_width   = 1;
	m_height  = 1;
	m_vel.x   = 0;
}

//-----------------------------------
//　更新処理
void StarObject::Update() {

	AutomaticMove();
	
}

//------------------------------------
//　描画処理
void StarObject::Draw() {

	
	SetVertex();
	BoxLocalTransform(vtx, m_width, m_height);
}

//-----------------------------------
// 頂点座標の設定
void StarObject::SetVertex(DWORD color) {

	float ox = 0.f;
	float oy = 0.f;

	vtx[0].pos = { ox, oy,0.f,1.f };
	vtx[1].pos = { ox + m_width, oy, 0.f,1.f };
	vtx[2].pos = { ox + m_width, oy + m_height,0.f, 1.f };
	vtx[3].pos = { ox, oy + m_height, 0.f, 1.f };
}

//-----------------------------------
// 自動操作
void StarObject::AutomaticMove(){

	++m_rot;
	m_vel.x = m_speed;
	m_vel.y = GRAVITY;

	/*Todo:
	ストップスキルによる停止の処理がある場合は
	vel.xに移動量を入れるかの判定が必要
	*/
	m_pos.x += m_vel.x;
	m_pos.y += m_vel.y;

}