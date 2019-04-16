#pragma once
#include "Scene.h"

//==================================
// タイトル画面クラス
//==================================

class TitleScene : public SceneBase {

private:

	//	初期化処理
	void Init()override;
	//　更新処理
	void Update()override;
	//　終了処理
	SceneID End()override;
	//	状態遷移
	SceneID Control() override;
	//　描画処理
	void Draw()override;

	~TitleScene()override {}

private:
	//次のシーンへ行く為のフラグ
	bool is_next;
};
