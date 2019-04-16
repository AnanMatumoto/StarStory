#pragma once

#include "Factory.h"
#include <string>
//===================================
//　ステージオブジェクト生成クラス
//===================================

class ObjectFactory:public Factory {

public:
	ObjectFactory(){}
	~ObjectFactory(){}

	// オブジェクト生成処理
	ObjectBase* Create(
		int id,
		float x,
		float y,
		std::string tex_name = "none",
		float rotate = 0.f
	)override;

};

