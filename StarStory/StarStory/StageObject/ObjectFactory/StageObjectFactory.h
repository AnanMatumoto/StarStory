#pragma once

#include "../Factory.h"
#include "../../Sound/SoundManager/SoundManager.h"
#include <string>

//===================================
//　ステージオブジェクト生成クラス
//===================================

class StageObjectFactory :public Factory {

public:
	StageObjectFactory() {}
	~StageObjectFactory() {}


	/*
	   星オブジェクトの生成を行う

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
		SoundResourceID se_name = STAR_NORMAL_SE,
		Skill skill = NORMAL,
		float rotate = 0.f
	)override;

	ObjectBase* CreateMap(
		int id,
		float x,
		float y,
		bool has_goal = false,
		std::string tex_name = "none"
	);
};
