#include "MapObject.h"
#include "../Lib/Lib.h"

//---------------------------------
//　コンストラクタ
MapObject::MapObject(float x, float y):ObjectBase(x,y) {
	m_width = 400;
	m_height = 50;


}

//--------------------------------
//　更新処理
void MapObject::Update() {

	SetVertex();
}

//---------------------------------
//　描画処理
void MapObject::Draw() {

	Lib::DrawPx2D(
		"HogeHoge",
		m_pos.x, m_pos.y,
		m_width, m_height
	);
}

//　頂点座標をセットする
void MapObject::SetVertex(DWORD color) {

	m_vtx[0].pos = { m_pos.x,  m_pos.y, 0.f,1.f };
	m_vtx[1].pos = { m_pos.x + m_width, m_pos.y, 0.f,1.f };
	m_vtx[2].pos = { m_pos.x + m_width, m_pos.y + m_height, 0.f,1.f };
	m_vtx[3].pos = { m_pos.x,  m_pos.y + m_height, 0.f,1.f };
}

