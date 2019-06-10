#include"SelectScene.h"
#include"../SceneManager/SceneManager.h"
#include "../../Lib/Lib.h"
#include "../../UI/UIManager/UIManager.h"
#include "../../ResourceNameLoader/ResourceNameLoader.h"

//--------------------------
//　セレクトシーン初期化
void SelectScene::Init() {

	auto res =ResourceNameLoader::GetInstance();

	m_state_id = SS_UPDATE;
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Register(BT_SELECT_STAGE, 1057, 632, res.GetName(PNG_SELECT_STAGE1));
	ui_mng.Register(BT_SELECT_BACK, 1354, 64, res.GetName(PNG_SELECT_BACK));
}

//---------------------------
//　セレクトシーン更新
void SelectScene::Update() {
	
	UIManager& ui_mng =UIManager::GetInstance();
	
	if (ui_mng.FindClickedUI() == BT_SELECT_STAGE) {
		m_state_id = SS_END;
		m_select_id = SC_CUSTOM;
	}
	else if(ui_mng.FindClickedUI()==BT_SELECT_BACK) {
		m_state_id = SS_END;
		m_select_id = SC_TITLE;
	}

	ui_mng.Update();

}

//---------------------------
//　セレクトシーン終了
SceneID SelectScene::End() {

	m_state_id = SS_INIT;
	UIManager::GetInstance().AllDelete();

	return m_select_id;
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

	auto res = ResourceNameLoader::GetInstance();

	Lib::DrawBox2D(
		res.GetName(PNG_SELECT_BOOK),
		0, 0
	);

	Lib::DrawPx2D(
		res.GetName(PNG_SELECT_BACK_GROUND),
		510, 220,
		1210,742
	);
	UIManager::GetInstance().Draw();
}
