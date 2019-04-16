#include "TitleScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include"../UI/ButtonUI.h"
#include "../StageObject/ObjectManager.h"
#include "../UI/UIObjectFactory.h"
//-----------------------------
//　タイトルシーン初期化
void TitleScene::Init() {
	
	state_id = SS_UPDATE;
}

//-----------------------------
//　タイトルシーン更新
void TitleScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}
}

//-----------------------------
//  タイトルシーン終了
SceneID TitleScene::End() {

	state_id = SS_INIT;
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
		"Resource/title/stage1_background_３_png.jpg",
		x, y,1920,1080
	);

}

