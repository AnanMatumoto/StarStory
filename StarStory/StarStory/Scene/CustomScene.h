#pragma once
#include "Scene.h"

//=================================
//  カスタム画面クラス
//=================================

class CustomScene :public SceneBase {

private:

	void Init()override;
	void Update() override;
	void End() override;
	void Control() override;
	void Draw() override;
	~CustomScene() {}

};

