#pragma once
#include "Scene.h"

//=================================
//  カスタム画面クラス
//=================================

class CustomScene :public SceneBase {

private:

	//　初期化処理
	void Init()override;
	//　更新処理
	void Update() override;
	//　終了処理
	SceneID End() override;
	//　状態遷移
	SceneID Control() override;
	//　描画処理
	void Draw() override;
	~CustomScene()override {}

};

