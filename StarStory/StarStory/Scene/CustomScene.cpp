#include "CustomScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define CUSTOM_BASE	"Resource/Custom/UI_custom_base.png"			// 背景
#define CUSTOM_DECISION "Resource/Custom/UI_custom_decision.png"	// 決定ボタン
#define CUSTOM_SERECT	"Resource/Custom/UI_custom_serect.png"		// セレクトへ戻るボタン

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	m_state_id = SS_UPDATE;

	UIManager & UImng = UIManager::GetInstance();

	// スキル情報の初期化(最初はすべてNORMAL)
	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		m_skill_data[i] = { NORMAL,"hoge","skill_data_01.dat" };
	}

	// UI生成
	UImng.Register(CT_BASE, 0, 0, CUSTOM_BASE);						// 背景
	UImng.Register(BT_CT_DECISION, 1445, 787, CUSTOM_DECISION);		// 決定ボタン
	UImng.Register(BT_CT_TOSELECT, 1115, 887, CUSTOM_SERECT);		// セレクト画面へ戻るボタン
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	// UI更新
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	// 決定ボタンが押されたら
	if (ui_mng.FindClickedUI() == BT_CT_DECISION) {

		// ゲーム画面へ進むに変更
		m_scene_id = SC_GAME;

		// カスタムシーン終了に行く
		m_state_id = SS_END;
	}

	// セレクト確認ボタンが押されたら
	if (ui_mng.FindClickedUI() == BT_CT_TOSELECT) {

		// セレクト画面へ戻るに変更
		m_scene_id = SC_SELECT;

		// カスタムシーン終了に行く
		m_state_id = SS_END;
	}

	// 星の更新
	m_custom_star.Update();
}

//----------------------------
// 　カスタムシーン終了
SceneID CustomScene::End() {

	m_state_id = SS_INIT;

	// UIをリストから削除
	UIManager::GetInstance().Delete(CT_BASE);
	UIManager::GetInstance().Delete(BT_CT_DECISION);
	UIManager::GetInstance().Delete(BT_CT_TOSELECT);

	return m_scene_id;
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

	// UI描画
	UIManager::GetInstance().Draw();

	// 星の描画
	m_custom_star.Draw();
}

