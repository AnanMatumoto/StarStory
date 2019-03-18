#pragma once
#include "Scene.h"

//==================================
//	ステージセレクト画面クラス
//==================================


class SelectScene : public SceneBase {

private:

	void Init()override;
	void Update()override;
	void End()override;
	void Control()override;
	void Draw() override;
	~SelectScene() {}
};

