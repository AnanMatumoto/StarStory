#pragma once
#include "../Lib/Lib.h"

//===================================
//　ステージオブジェクト基底クラス
//===================================

/*
	ステージに置かれるオブジェクトは
	以下を継承する。

	Update：更新処理
	Draw　：描画処理

*/

class StageObjectBase {
	
public:

	StageObjectBase(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual ~StageObjectBase(){}

protected:

	t_Float2 pos; // 座標
	float rot;    // 回転角度
};

