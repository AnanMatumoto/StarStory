#include "ResultScene.h"
#include "../../Lib/Lib.h"
#include "../../UI/UIManager/UIManager.h"
#include "../SceneManager/SceneManager.h"

#define RESULT_BACKIMG "Resource/Result/ui_result_base.png"
#define RESULT_CUSTOM "Resource/Result/ui_result_custom.png"
#define RESULT_SELECT "Resource/Result/ui_result_select.png"
#define RESULT_CLEAR "Resource/Result/GameClear .png"
#define RESULT_FAILD "Resource/Result/GameOver.png"

//----------------------------
// リザルトシーン初期化
void ResultScene::Init() {

	m_state_id = SS_UPDATE;

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_RESULT_BACK_CUSTOM, 888, 809,   RESULT_CUSTOM);
	mng.Register(BT_RESULT_BACK_SELECT, 1176, 809,   RESULT_SELECT);

}

//----------------------------
//　リザルトシーン更新
void ResultScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	
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

	Lib::DrawPx2D(
		"hoge",
		0,0,
		1920,1080,
		0x00ffffff
	);

	Lib::DrawBox2D(
		RESULT_BACKIMG,
		463, 193
	);

	if (GetResult() == CLEAR) {
		m_tex_name = RESULT_CLEAR;
	}
	else {
		m_tex_name = RESULT_FAILD;
	}
	Lib::DrawBox2D(
		m_tex_name.c_str(),
		500, 400
	);
	UIManager::GetInstance().Draw();
}
