#pragma once

#include "../../StageObject/Factory.h"
#include <string>


class UIObjectFactory :public Factory{

public:
	UIObjectFactory() {}
	~UIObjectFactory()override{}
	
	/*
		オブジェクト生成処理

		第1：オブジェクトのID
		第2：X座標
		第3：Y座標
		第4：画像名
		第5：回転角度（デフォルトは０度）

	*/
	ObjectBase * Create(
		int id,
		float x,
		float y,
		std::string tex_name,
		float rot = 0.f
	)override;

};