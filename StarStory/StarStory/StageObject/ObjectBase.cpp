﻿#include "ObjectBase.h"

//==================================
// オブジェクト基底クラス
//==================================

//----------------------------------
// コンストラクタ
ObjectBase::ObjectBase() {
	m_pos = { 0,0 };
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

