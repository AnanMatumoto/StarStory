#include "CustomScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define CUSTOM_WINDOW	"Resource/Custom/UI_custom_window.png"		// 背景
#define CUSTOM_DECISION "Resource/Custom/UI_custom_decision.png"	// 決定ボタン
#define CUSTOM_MAP		"Resource/Custom/UI_custom_map.png"			// マップ確認ボタン
#define CUSTOM_SERECT	"Resource/Custom/UI_custom_serect.png"		// セレクトへ戻るボタン

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	m_state_id = SS_UPDATE;

	UIManager & UImng = UIManager::GetInstance();

	// UI生成
	UImng.Register(BT_CT_DECISION, 1445, 787, CUSTOM_DECISION);		// 決定ボタン
	UImng.Register(BT_CT_MAP, 1115, 787, CUSTOM_MAP);				// マップ確認ボタン
	UImng.Register(BT_CT_TOSELECT, 1115, 887, CUSTOM_SERECT);		// セレクト画面へ戻るボタン
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	// UI更新
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	//決定ボタンが押されたら
	if (ui_mng.FindClickedUI()==BT_CT_DECISION) {

		m_state_id = SS_END;
	}

	//// マウス座標取得
	//Lib::GetMousePoint(&mouse_x, &mouse_y);

	//// マウス情報をカスタムシーンからカスタムスターに移す
 // 	custom_star.SetMousePos(mouse_x, mouse_y);

	//// 星型の更新
	//custom_star.Update();	
}

//----------------------------
// 　カスタムシーン終了
SceneID CustomScene::End() {

	m_state_id = SS_INIT;

	// UIをリストから削除
	UIManager::GetInstance().Delete(BT_CT_DECISION);
	UIManager::GetInstance().Delete(BT_CT_MAP);
	UIManager::GetInstance().Delete(BT_CT_TOSELECT);

	return SC_GAME;
}

//----------------------------
//	カスタムシーン状態管理
SceneID CustomScene::Control() {

	switch (m_state_id)
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

	// 「背景」
	Lib::DrawBox2D(CUSTOM_WINDOW,0, -20);

	// UI描画
	UIManager::GetInstance().Draw();

	//// 「星型の描画」
	//custom_star.Draw();
}

