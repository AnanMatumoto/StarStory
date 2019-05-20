#include"SelectScene.h"
#include"SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define STAGE_IMG "Resource/StageSelect/stage_1_cover.png"
#define BACK_IMG "Resource/StageSelect/ui_select_base.png"
#define BT_STAGE1 "Resource/StageSelect/ui_select_ep1.png"
#define BT_BACK "Resource/StageSelect/ui_select_title.png"

//--------------------------
//　セレクトシーン初期化
void SelectScene::Init() {

	m_state_id = SS_UPDATE;
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Register(BT_SL_STAGE, 1057, 632, BT_STAGE1);
	ui_mng.Register(BT_SL_BACK, 1354, 64, BT_BACK);
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
		BACK_IMG,
		0, 0
	);

	Lib::DrawPx2D(
		STAGE_IMG,
		510, 220,
		1210,742
	);
	UIManager::GetInstance().Draw();
}
