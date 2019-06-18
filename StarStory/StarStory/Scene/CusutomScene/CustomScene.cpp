#include "CustomScene.h"
#include "../SceneManager/SceneManager.h"
#include "../../UI/UIManager/UIManager.h"

/*----画像----*/
// 背景
const char CUSTOM_BASE_TEX[256]			= "Resource/Custom/ui_custom_base_ver2.png";
// 決定ボタン
const char CUSTOM_DECISION_TEX[256]		= "Resource/Custom/ui_custom_nextpage.png";
// セレクトへ戻るボタン
const char CUSTOM_SERECT_TEX[256]		= "Resource/Custom/ui_custom_stageselect.png";
// ステージ1のマップ
const char CUSTOM_STAGE1_MAP_TEX[256]	= "Resource/Custom/stage1_map.png";
/*----画像----*/

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	m_state_id = SS_UPDATE;

	/*----UI生成----*/
	UIManager & UImng = UIManager::GetInstance();
	// 決定ボタン
	UImng.Register(BT_CUSTOM_BACK, 1015, 792, CUSTOM_SERECT_TEX);
	// セレクト画面へ戻るボタン
	UImng.Register(BT_CUSTOM_DECISION, 1309, 876, CUSTOM_DECISION_TEX);
	/*----UI生成----*/

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
	if (ui_mng.FindClickedUI() == BT_CUSTOM_DECISION) {

		// ゲーム画面へ進むに変更
		m_scene_id = SC_GAME;

		// カスタムシーン終了に行く
		m_state_id = SS_END;
	}

	// セレクト確認ボタンが押されたら
	if (ui_mng.FindClickedUI() == BT_CUSTOM_BACK) {

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
	UIManager::GetInstance().Delete(BT_CUSTOM_BACK);		// セレクト画面へ戻るボタン
	UIManager::GetInstance().Delete(BT_CUSTOM_DECISION);	// 決定ボタン

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

	// 背景
	Lib::DrawBox2D(CUSTOM_BASE_TEX,0,0);

	// UI描画
	UIManager::GetInstance().Draw();

	// カスタムオブジェクト描画
	m_custom_object_manager->Draw();

	// ステージ1のマップ描画
	Lib::DrawBox2D(CUSTOM_STAGE1_MAP_TEX, 320, 580, 0.3341f, 0.37f);
}

