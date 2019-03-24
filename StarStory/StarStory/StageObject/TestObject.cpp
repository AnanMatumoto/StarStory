#include "TestObject.h"
#include "../Lib/Lib.h"

TestObject::TestObject() {

	pos.m_x = 500;
	pos.m_y = 500;

}

//------------------------------
// 更新処理
void TestObject::Update() {


}

//------------------------------
//　描画処理
void TestObject::Draw() {

	Lib::DrawBox2D(
		"Resource/test_image/object_sample.png",
		pos.m_x, pos.m_y
	);

}

