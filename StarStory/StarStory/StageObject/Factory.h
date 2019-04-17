#pragma once
#include "ObjectBase.h"
#include <string>

//================================
//　ファクトリ抽象クラス
//================================


class Factory {

public:
	Factory() {}

	/*
	   オブジェクトの生成を行う

	   第1:　オブジェクトID
	   第2:  X座標
	   第3:  Y座標
	   第4:  使用する画像
	   第5:  回転角度（デフォルトは０度）
	*/
	virtual ObjectBase* Create(
		int id,
		float x,
		float y,
		std::string tex_name,
		float rotate
	) = 0;

	~Factory() {}

};

