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

	StageObjectBase() {
		pos.m_x = 0;
		pos.m_y = 0;

		rot = 0;
	}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void Delete() {
		
		delete this;
	}

protected:

	t_Float2 pos; // 座標
	float rot;    // 回転角度

private:

	virtual ~StageObjectBase() {}

};

