#include "TitleScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"


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

	Lib::DrawBox2D(
		"Resource/test_image/samp_title.png",
		0, 0
	);
}

