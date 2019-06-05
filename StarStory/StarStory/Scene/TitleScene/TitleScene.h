#pragma once

#include "../Scene.h"
#include <vector>
#include "../../Lib/Lib.h"

class ObjectBase;

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

	~TitleScene()override;

private:
	
	bool has_end;	//終了状態フラグ
	//Lib::AudioPlayer* sound;

	
};
