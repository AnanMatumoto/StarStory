#pragma once
#include "Scene.h"

//=================================
//　ゲーム画面クラス
//=================================

class GameScene : public SceneBase {

private:
	void Init() override;
	void Update()override;
	void End()override;
	void Control() override;
	void Draw() override;
	~GameScene() {}
	//StageBase* stage;
};
