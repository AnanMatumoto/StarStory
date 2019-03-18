#pragma once
#include "Scene.h"

//==================================
// タイトル画面クラス
//==================================

class TitleScene : public SceneBase {

private:

	void Init()override;
	void Update()override;
	void End()override;
	void Control() override;
	void Draw()override;
	~TitleScene() {}
};
