#include "ResultScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"

//----------------------------
// リザルトシーン初期化
void ResultScene::Init() {
	state_id = SS_UPDATE;
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
		state_id = SS_END;
	}
}

//----------------------------
// リザルトシーン終了
SceneID ResultScene::End() {
	state_id = SS_INIT;
	return SC_TITLE;
}

//----------------------------
//　リザルトシーン状態管理
SceneID ResultScene::Control() {

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
	return SC_RESULT;
}

//-----------------------------
//　リザルトシーン描画
void ResultScene::Draw() {

	Lib::DrawBox2D(
		"Resource/test_image/result_samp.png",
		0, 0
	);
}
