#include "Scene.h"
#include "Lib.h"

//----------------------------
// リザルトシーン初期化
void ResultScene::Init() {
	Scene::g_StateID = SS_UPDATE;
}

//----------------------------
//　リザルトシーン更新
void ResultScene::Update() {
	//if (is_clear) {
		/* ゲームクリア処理 */
		//is_clear = false;
	//}
	//else {
		/* ゲームオーバー処理 */
	//}
	if (Lib::KeyPress(VK_SPACE)) {
		Scene::g_StateID = SS_END;
	}
}

//----------------------------
// リザルトシーン終了
void ResultScene::End() {
	Scene::g_StateID = SS_INIT;
	Scene::g_SceneID = SC_TITLE;
}

//----------------------------
//　リザルトシーン状態管理
void ResultScene::Control() {
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

//-----------------------------
//　リザルトシーン描画
void ResultScene::Draw() {

	Lib::DrawBox2D(
		"Resource/test_image/result_samp.png",
		0, 0
	);
}
