#include "ResultScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define RESULT_BACK "Resource/Result/UI_result.png"
#define RESULT_CUSTOM "Resource/Result/UI_result_custom.png"
#define RESULT_SELECT "Resource/Result/UI_result_serect.png"

//----------------------------
// リザルトシーン初期化
void ResultScene::Init() {
	state_id = SS_UPDATE;

	//UIの登録
	UIManager& mng = UIManager::GetInstance();
	mng.Register(BT_RS_CUSUTOM, 935, 780, RESULT_CUSTOM);
	mng.Register(BT_RS_SELECT, 1195, 780, RESULT_SELECT);
	
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

	UIManager::GetInstance().Update();
}

//----------------------------
// リザルトシーン終了
SceneID ResultScene::End() {
	state_id = SS_INIT;

	//UIをリストから削除
	UIManager::GetInstance().Delete(BT_RS_CUSUTOM);
	UIManager::GetInstance().Delete(BT_RS_SELECT);

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
		RESULT_BACK,
		0, 0
	);

	UIManager::GetInstance().Draw();
}
