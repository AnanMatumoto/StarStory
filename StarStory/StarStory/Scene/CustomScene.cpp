#include "CustomScene.h"
#include "SceneManager.h"
#include "Lib.h"

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	state_id = SS_UPDATE;
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	if (Lib::KeyPress(VK_SPACE)) {
		state_id = SS_END;
	}
}

//----------------------------
// 　カスタムシーン更新
SceneID CustomScene::End() {

	state_id = SS_INIT;
	return SC_SELECT;
}

//----------------------------
//	カスタムシーン状態管理
SceneID CustomScene::Control() {

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
	return SC_CUSTOM;
}

//----------------------------
//　カスタムシーン描画
void CustomScene::Draw() {
	
	Lib::DrawBox2D(
		"Resource/test_image/samp_custom.png",
		0, 0
	);
}