#pragma once

#include "Factory.h"

enum StageObjectID {

	OBJ_TEST1,
};

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

