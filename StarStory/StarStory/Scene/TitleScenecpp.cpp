#include "TitleScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../StageObject/ObjectManager.h"
#include "../UI/UIManager.h"

#define TITLE_BACK "Resource/Title/UI_title_bg.png"
#define TITLE_START "Resource/Title/UI_title_start.png"
#define TITLE_END	"Resource/Title/UI_title_end.png"

//-----------------------------
//　タイトルシーン初期化
void TitleScene::Init() {
	
	state_id = SS_UPDATE;

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_TT_START, 1000, 800, TITLE_START);
	mng.Register(BT_TT_END,    300, 800, TITLE_END);
}

//-----------------------------
//　タイトルシーン更新
void TitleScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}

	UIManager::GetInstance().Update();
}

//-----------------------------
//  タイトルシーン終了
SceneID TitleScene::End() {

	state_id = SS_INIT;

	//UIをリストから削除する
	UIManager::GetInstance().Delete(BT_TT_START);
	UIManager::GetInstance().Delete(BT_TT_END);

	return SC_CUSTOM;
}

//-----------------------------
//　状態管理
SceneID TitleScene::Control() {

	switch (state_id)
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