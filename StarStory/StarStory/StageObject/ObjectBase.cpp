#include "ObjectBase.h"

//==================================
// オブジェクト基底クラス
//==================================

//----------------------------------
// コンストラクタ
ObjectBase::ObjectBase(float x, float y) {
	m_pos = { x, y };
	m_rot = 0;
	is_delete = false;
}

//---------------------------------
//　フラグを削除状態にセットする
void ObjectBase::Delete() {
	is_delete = true;
}

const bool ObjectBase::IsDelete() const {
	return is_delete;
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

