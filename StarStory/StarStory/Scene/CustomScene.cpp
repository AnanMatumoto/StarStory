#include "CustomScene.h"
#include "SceneManager.h"
#include "../UI/UIManager.h"

/*----画像----*/
const char CUSTOM_BASE_TEX[256]			= "Resource/Custom/UI_custom_base.png";				// 背景
const char CUSTOM_DECISION_TEX[256]		= "Resource/Custom/ui_custom_nextpage.png";			// 決定ボタン
const char CUSTOM_SERECT_TEX[256]		= "Resource/Custom/ui_custom_stageselect.png";		// セレクトへ戻るボタン
const char CUSTOM_STAGE1_MAP_TEX[256]	= "Resource/Custom/stage1_map.png";					// ステージ1のマップ
/*----画像----*/

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	m_state_id = SS_UPDATE;

	UIManager & UImng = UIManager::GetInstance();

	// UI生成
	UImng.Register(CT_BASE, 0, 0, CUSTOM_BASE_TEX);						// 背景
	UImng.Register(BT_CT_TOSELECT, 1015, 792, CUSTOM_SERECT_TEX);		// 決定ボタン
	UImng.Register(BT_CT_DECISION, 1309, 876, CUSTOM_DECISION_TEX);		// セレクト画面へ戻るボタン
	//UImng.Register(CT_STAGE1_MAP, 320, 580, CUSTOM_STAGE1_MAP);		// ステージ1のマップ

	// カスタムオブジェクト生成
	m_custom_object_manager = new CustomObjectManager();
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

	// カスタムオブジェクト更新
	m_custom_object_manager->Update();
}

//----------------------------
// 　カスタムシーン終了
SceneID CustomScene::End() {

	m_state_id = SS_INIT;

	// UIをリストから削除
	UIManager::GetInstance().Delete(BT_CT_TOSELECT);	// セレクト画面へ戻るボタン
	UIManager::GetInstance().Delete(BT_CT_DECISION);	// 決定ボタン
	UIManager::GetInstance().Delete(CT_BASE);			// 背景
	//UIManager::GetInstance().Delete(CT_STAGE1_MAP);	// ステージ1のマップ

	// カスタムオブジェクト削除
	delete m_custom_object_manager;

	// シーンIDを返す
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

	// カスタムオブジェクト描画
	m_custom_object_manager->Draw();

	// ステージ1のマップ描画
	Lib::DrawBox2D(CUSTOM_STAGE1_MAP_TEX, 320, 580, 0.337f, 0.37f);
}

