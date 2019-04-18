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

	// キー情報更新
	Lib::KeyUpdate();

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}

	// マウス座標取得
	Lib::GetMousePoint(&mouse_x, &mouse_y);

	// マウス情報をカスタムシーンからカスタムスターに移す
  	custom_star.SetMousePos(mouse_x, mouse_y);

	// 星型の更新
	custom_star.Update();
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
	// 仮画像なので後で変更します

	// 「星の後ろの白枠」
	/*Lib::DrawBox2D(
		"Resource/Custom/星の後ろの白枠.png",
		100, 100
	);*/

	// 「背景」

	// 「ひし形」
	// 星型の描画(今はひし形のみ)
	custom_star.Draw();

	// 「カスタム」
	Lib::DrawBox2D(
		"Resource/Custom/カスタム.png",
		10, 10
	);

	// 「総スキル」
	Lib::DrawBox2D(
		"Resource/Custom/総スキル.png",
		1200, 100
	);

	float skill_pos_count = 0;
	// 「スキル各種」
	for (int i = 0; i < 5; ++i) {
		skill_pos_count += 100;
		Lib::DrawBox2D(
			"Resource/Custom/スキル各種.png",
			1200, 120 + skill_pos_count
		);
	}

	// 「マップ確認」
	Lib::DrawBox2D(
		"Resource/Custom/マップ確認.png",
		1200, 800
	);

	// 「セレクトへ」
	Lib::DrawBox2D(
		"Resource/Custom/セレクトへ.png",
		1200, 900
	);

	//「プレイ画面へ」
	Lib::DrawBox2D(
		"Resource/Custom/プレイ画面へ.png",
		1600, 800
	);
}

