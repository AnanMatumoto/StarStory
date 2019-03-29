#pragma once

#include "Factory.h"
#include "Cloneable.h"

//===================================
//　ステージオブジェクト生成クラス
//===================================

class StageObjectFactory:public Factory,public Cloneable{

public:
	StageObjectFactory(){}
	~StageObjectFactory(){}

	// オブジェクト生成処理
	ObjectBase* Create(int id)override;
};

