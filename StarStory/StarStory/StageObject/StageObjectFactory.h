#pragma once

#include "Factory.h"

//===================================
//　ステージオブジェクト生成クラス
//===================================

class StageObjectFactory:public Factory{

public:
	StageObjectFactory(){}
	~StageObjectFactory(){}

	// オブジェクト生成処理
	ObjectBase* Create(int id)override;
	// クローン生成処理
	ObjectBase* Clone(int id)override;

};

