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
		m_pos.m_x = 0;
		m_pos.m_y = 0;

		m_rot = 0;
	}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Delete() {
		
		delete this;
	}

protected:

	t_Float2 m_pos; // 座標
	float m_rot;    // 回転角度

private:

	virtual ~StageObjectBase() {}

};

