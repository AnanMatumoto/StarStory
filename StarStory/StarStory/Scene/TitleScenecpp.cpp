#include "TitleScene.h"
#include "SceneManager.h"
#include "../StageObject/ObjectManager.h"
#include "../UI/UIManager.h"

#define TITLE_BACK "Resource/Title/ui_title_base.png"
#define TITLE_START "Resource/Title/ui_title_start.png"
#define TITLE_END	"Resource/Title/ui_title_end.png"


//-----------------------------
//　タイトルシーン初期化
void TitleScene::Init() {
	
	m_state_id = SS_UPDATE;
	has_end = false;

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_TT_START, 1000, 800, TITLE_START);
	mng.Register(BT_TT_END,    300, 800, TITLE_END);

	HWND hwnd = Lib::hWnd;


	//サウンド再生サンプル（直書き）
	Lib::AudioClip& audio = Lib::AudioClip::GetInterface(Lib::hWnd);
	audio.LoadWaveFile("Resource/Audio/BGM/title_bgm.wav");
	sound = new Lib::AudioPlayer();
	sound->Play("Resource/Audio/BGM/title_bgm.wav");
}

//-----------------------------
//　タイトルシーン更新
void TitleScene::Update() {

	UIManager& mng = UIManager::GetInstance();
	mng.Update();
	//スタートボタンが押されたら
	if (mng.FindClickedUI() == BT_TT_START) {
		sound->Stop();
		m_state_id = SS_END;
	}
	else if (mng.FindClickedUI() == BT_TT_END) {
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

	//タイトル描画（仮）
	Lib::DrawPx2D(
		TITLE_BACK,
		x, y,1920,1080
	);
	UIManager::GetInstance().Draw();
}

//-------------------------------
//　デストラクタ
TitleScene::~TitleScene() {

}