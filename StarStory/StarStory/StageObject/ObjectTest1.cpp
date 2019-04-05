#include "ObjectTest1.h"
#include "../Lib/Lib.h"

//---------------------------------
//　コンストラクタ
ObjectTest1::ObjectTest1(float x, float y):ObjectBase(x,y) {
	m_width = 100;
	m_height = 100;
}

//--------------------------------
//　更新処理
void ObjectTest1::Update() {


}

//---------------------------------
//　描画処理
void ObjectTest1::Draw() {

	Lib::DrawPx2D(
		"HogeHoge",
		m_pos.x, m_pos.y,
		m_width, m_height
	);
}


