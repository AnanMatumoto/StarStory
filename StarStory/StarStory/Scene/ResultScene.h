#pragma once
#include "Scene.h"

//=================================
// リザルト画面クラス
//=================================

class ResultScene : public SceneBase {

private:
	void Init() override;
	void Update() override;
	void End() override;
	void Control() override;
	void Draw() override;
	~ResultScene() override{}

};

