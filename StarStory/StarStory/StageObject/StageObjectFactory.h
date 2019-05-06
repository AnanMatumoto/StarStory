#pragma once

#include "Factory.h"
#include <string>

//===================================
//　ステージオブジェクト生成クラス
//===================================

class StageObjectFactory :public Factory {

public:
	StageObjectFactory() {}
	~StageObjectFactory() {}


	/*
	   オブジェクトの生成を行う

	   第1:　オブジェクトID
	   第2:  X座標
	   第3:  Y座標
	   第4:  使用する画像
	   第5:  回転角度（デフォルトは０度）
	*/
	ObjectBase* Create(
		int id,
		float x,
		float y,
		std::string tex_name = "none",
		std::string se_name = "none",
		Skill skill = NORMAL,
		float rotate = 0.f
	)override;

};
