#include"SelectScene.h"
#include"SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define BT_STAGE1 "Resource/StageSelect/Stage1_sample.png"
#define BT_BACK "Resource/StageSelect/title_back_sample.png"

//--------------------------
//　セレクトシーン初期化
void SelectScene::Init() {

	m_state_id = SS_UPDATE;
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Register(BT_SL_STAGE, 500, 500, BT_STAGE1);
	ui_mng.Register(BT_SL_BACK, 200, 700, BT_BACK);
}

//---------------------------
//　セレクトシーン更新
void SelectScene::Update() {
	
	UIManager& ui_mng =UIManager::GetInstance();
	
	if (ui_mng.FindClickedUI() == BT_SL_STAGE) {
		m_state_id = SS_END;
		m_scene_id = SC_CUSTOM;
	}
	else if(ui_mng.FindClickedUI()==BT_SL_BACK) {
		m_state_id = SS_END;
		m_scene_id = SC_TITLE;
	}

	ui_mng.Update();

}

//---------------------------
//　セレクトシーン終了
SceneID SelectScene::End() {

	m_state_id = SS_INIT;
	UIManager::GetInstance().AllDelete();

	return m_scene_id;
}

//----------------------------
//　セレクトシーン状態管理
SceneID SelectScene::Control() {

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
	return SC_SELECT;
}

//----------------------------
//　セレクトシーン描画
void SelectScene::Draw() {

	Lib::DrawBox2D(
		"Resource/test_image/select_samp.png",
		0, 0
	);
	UIManager::GetInstance().Draw();
}
