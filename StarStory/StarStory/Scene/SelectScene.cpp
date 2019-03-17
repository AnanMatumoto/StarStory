#include "Scene.h"
#include "Lib.h"
//--------------------------
//　セレクトシーン初期化
void SelectScene::Init() {

	Scene::g_StateID = SS_UPDATE;
}

//---------------------------
//　セレクトシーン更新
void SelectScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		Scene::g_StateID = SS_END;
	}
}

//---------------------------
//　セレクトシーン終了
void SelectScene::End() {

	Scene::g_StateID = SS_INIT;
	Scene::g_SceneID = SC_GAME;

}

//----------------------------
//　セレクトシーン状態管理
void SelectScene::Control() {

	switch (Scene::g_StateID)
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
