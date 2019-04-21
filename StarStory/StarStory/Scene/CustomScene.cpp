#include "CustomScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"

#include "../UI/UIManager.h"
#define CUSTOM_DEC "Resource/Custom/UI_custom_decision.png"

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	state_id = SS_UPDATE;
	UIManager::GetInstance().Register(BT_CT_DEC, 1445, 787, CUSTOM_DEC);
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	//決定ボタンが押されたら
	if (ui_mng.FindClickedUI()==BT_CT_DEC) {
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
	UIManager::GetInstance().Delete(BT_CT_DEC);

	return SC_GAME;
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

	// 「背景」
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_window.png",
		0, -20
	);

	// 「星型の描画」
	custom_star.Draw();

	// 「◀」
	float left = 205;
	for (int i = 0; i < 5; ++i) {
		Lib::DrawBox2D(
			"Resource/Custom/UI_custom_left.png",
			1220, left
		);
		left += 117;
	}

	/* --「スキル」--*/
	// 無
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_normal.png",
		1270, 190
	);

	// ジャンプ
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_jump.png",
		1270, 310
	);

	// 加速
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_accel.png",
		1270, 430
	);

	// ライト
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_light.png",
		1270, 547
	);

	// 停止
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_stop.png",
		1270, 665
	);
	/* --「スキル」--*/

	// 「▶」
	float right = 205;
	for (int i = 0; i < 5; ++i) {
		Lib::DrawBox2D(
			"Resource/Custom/UI_custom_right.png",
			1550, right
		);
		right += 117;
	}

	// 「強弱」(今は弱のみ)
	float weak = 190;
	for (int i = 0; i < 5; ++i) {
		Lib::DrawBox2D(
			"Resource/Custom/UI_custom_weak.png",
			1600, weak
		);
		weak += 118;
	}

	// 「コスト」(今は1のみ)
	float cost = 180;
	for (int i = 0; i < 5; ++i) {
		Lib::DrawBox2D(
			"Resource/Custom/UI_custom_cost1.png",
			1670, cost
		);
		cost += 119;
	}

	// 「マップ確認」
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_map.png",
		1115, 787
	);

	// 「セレクトへ」
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_serect.png",
		1115, 887
	);

	UIManager::GetInstance().Draw();

	/*「決定」
	Lib::DrawBox2D(
		"Resource/Custom/UI_custom_decision.png",
		1445, 787
	);*/
}

