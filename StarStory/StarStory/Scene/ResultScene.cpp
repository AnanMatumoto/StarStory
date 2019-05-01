#include "ResultScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define RESULT_BACKIMG "Resource/Result/UI_result.png"
#define RESULT_CUSTOM "Resource/Result/UI_result_custom.png"
#define RESULT_SELECT "Resource/Result/UI_result_serect.png"
#define RESULT_TITLEBACK "Resource/Result/title_back_sample.png"

//----------------------------
// リザルトシーン初期化
void ResultScene::Init() {

	m_state_id = SS_UPDATE;

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_RS_CUSUTOM, 935, 780, RESULT_CUSTOM);
	mng.Register(BT_RS_SELECT, 1195, 780, RESULT_SELECT);
	mng.Register(BT_RS_TITLEBACK, 435, 780, RESULT_TITLEBACK);

}

//----------------------------
//　リザルトシーン更新
void ResultScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	//タイトルボタンがクリックされたら

	if (ui_mng.FindClickedUI() == BT_RS_TITLEBACK) {
		m_state_id = SS_END;
		m_scene_id = SC_TITLE;
	}

	if (ui_mng.FindClickedUI() == BT_RS_CUSUTOM) {
		m_state_id = SS_END;
		m_scene_id = SC_CUSTOM;
	}
}

//----------------------------
// リザルトシーン終了
SceneID ResultScene::End() {

	m_state_id = SS_INIT;

	//UIをリストから削除
	UIManager::GetInstance().AllDelete();

	return m_scene_id;
}

//----------------------------
//　リザルトシーン状態管理
SceneID ResultScene::Control() {

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
	return SC_RESULT;
}

//-----------------------------
//　リザルトシーン描画
void ResultScene::Draw() {

	Lib::DrawBox2D(
		RESULT_BACKIMG,
		0, 0
	);

	UIManager::GetInstance().Draw();
}
