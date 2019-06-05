#pragma once

#include "../Scene.h"
#include "../../Lib/Lib.h"
//=================================
//　ゲーム画面クラス
//=================================

class GameScene : public SceneBase {

private:

	//　初期化処理
	void Init() override;
	//　更新処理
	void Update()override;
	//　終了処理
	SceneID End()override;
	//　状態遷移
	SceneID Control() override;
	//　描画処理
	void Draw() override;

	//リザルト結果描画処理
	void DrawResult();

	~GameScene() override;
	//StageBase* stage;

private:
	SceneID m_scene_id; //遷移先保存用変数
	//Lib::AudioPlayer* m_sound;
};
