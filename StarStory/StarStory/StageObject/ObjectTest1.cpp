#include "ObjectTest1.h"
#include "../Lib/Lib.h"

//---------------------------------
//　コンストラクタ
ObjectTest1::ObjectTest1() {

	pos = { 500,500 };
	rot = 0;
	is_delete = false;
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
		pos.m_x, pos.m_y,
		100, 100
	);
}

//---------------------------------
//  解放状態であるかを返す
const bool ObjectTest1::IsDelete() const{
	
	return is_delete;
}

