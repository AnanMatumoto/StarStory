#include "CustomScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	state_id = SS_UPDATE;
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}
}

//----------------------------
// 　カスタムシーン更新
SceneID CustomScene::End() {

	state_id = SS_INIT;
	return SC_SELECT;
}

//----------------------------
//	カスタムシーン状態管理
SceneID CustomScene::Control() {

	switch (state_id)
	{
	case SS_INIT:
		Init();
		break;

	case SS_UPDATE:
		Update();
		Draw();
		break;

	case SS_END:
		return End();
		break;
	}
	return SC_CUSTOM;
}

//----------------------------
//　カスタムシーン描画
void CustomScene::Draw() {
	
	// 描画順に書いていく
	// 橋本君のラフを元に置いてます(全て仮画像)

	// 「背景」
	Lib::DrawBox2D(
		"Resource/test_image/samp_custom.png",
		0, 0
	);

	// 「星の後ろの白枠」
	Lib::DrawBox2D(
		"Resource/Custom/星の後ろの白枠.png",
		100, 100
	);

	// 「ひし形」
	Lib::DrawBox2D(
		"Resource/Custom/player_1_normal.png",
		500, 500
	);

	// 「カスタム」
	Lib::DrawBox2D(
		"Resource/Custom/カスタム.png",
		50, 50
	);

	// 「総スキル」
	Lib::DrawBox2D(
		"Resource/Custom/総スキル.png",
		1200, 300
	);

	// 「スキル各種」
	Lib::DrawBox2D(
		"Resource/Custom/スキル各種.png",
		1200, 500
	);

	// 「マップ確認」
	Lib::DrawBox2D(
		"Resource/Custom/マップ確認.png",
		1200, 700
	);

	// 「セレクトへ」
	Lib::DrawBox2D(
		"Resource/Custom/セレクトへ.png",
		1200, 800
	);

	//「プレイ画面へ」
	Lib::DrawBox2D(
		"Resource/Custom/プレイ画面へ.png",
		1600, 700
	);
}

