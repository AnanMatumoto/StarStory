#include "TitleScene.h"
#include "../SceneManager/SceneManager.h"
#include "../../UI/UIManager/UIManager.h"
#include "../../Sound/SoundManager/SoundManager.h"
#include "../../StageObject/ObjectManager/ObjectManager.h"

#include "../../ResourceNameLoader/ResourceNameLoader.h"

//-----------------------------
//　タイトルシーン初期化
void TitleScene::Init() {
	
	m_state_id = SS_UPDATE;
	has_end = false;
	auto res = ResourceNameLoader::GetInstance();

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_TITLE_START, 347, 818, res.GetName(PNG_TITLE_START));
	mng.Register(BT_TITLE_END,   1120, 844, res.GetName(PNG_TITLE_END));

	// BGM再生
	SoundManager::GetInstanse().SoundPlayer(TITLE_BGM, SoundManager::PLAY);
}

//-----------------------------
//　タイトルシーン更新
void TitleScene::Update() {

	UIManager& mng = UIManager::GetInstance();
	mng.Update();
	//スタートボタンが押されたら
	if (mng.FindClickedUI() == BT_TITLE_START) {
		//sound->Stop();
		m_state_id = SS_END;
	}
	else if (mng.FindClickedUI() == BT_TITLE_END) {
		m_state_id = SS_END;
		has_end = true;
	}
}

//-----------------------------
//  タイトルシーン終了
SceneID TitleScene::End() {

	m_state_id = SS_INIT;


	//UIをリストから削除する
	UIManager::GetInstance().AllDelete();

	// BGM停止
	SoundManager::GetInstanse().SoundPlayer(TITLE_BGM, SoundManager::STOP);

	if (has_end) {
		SceneManager::GetInstance().SetQuit(true);
	}
	
	return SC_SELECT;
}

//-----------------------------
//　状態管理
SceneID TitleScene::Control() {

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

	return SC_TITLE;
}

//------------------------------
//　タイトルシーン描画
void TitleScene::Draw() {

	float x = 0, y = 0;
	auto res = ResourceNameLoader::GetInstance();

	//タイトル描画（仮）
	Lib::DrawPx2D(
		res.GetName(PNG_TITLE_BACK_GROUND),
		x, y,1920,1080
	);
	UIManager::GetInstance().Draw();
}

//-------------------------------
//　デストラクタ
TitleScene::~TitleScene() {

}