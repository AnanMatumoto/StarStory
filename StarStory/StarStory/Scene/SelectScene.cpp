#include"SelectScene.h"
#include"SceneManager.h"
#include "Lib.h"

//--------------------------
//　セレクトシーン初期化
void SelectScene::Init() {

	state_id = SS_UPDATE;
}

//---------------------------
//　セレクトシーン更新
void SelectScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}
}

//---------------------------
//　セレクトシーン終了
void SelectScene::End() {

	state_id = SS_INIT;
	SceneManager& sm = SceneManager::GetInstance();
	sm.ChangeScene(SC_GAME);

}

//----------------------------
//　セレクトシーン状態管理
void SelectScene::Control() {

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
		End();
		break;
	}
}

//----------------------------
//　セレクトシーン描画
void SelectScene::Draw() {

	Lib::DrawBox2D(
		"Resource/test_image/select_samp.png",
		0, 0
	);

}
