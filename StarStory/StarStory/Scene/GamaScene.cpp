#include "GameScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../StageObject/ObjectManager.h"
#include "../StageObject/StarObject.h"

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	state_id = SS_UPDATE;
	//stage = new StageBase();


//ステージオブジェクトの登録
	ObjectManager::GetInstance().Register(OBJ_TEST1, 0, 700);
	ObjectManager::GetInstance().Register(STAR_OBJ, 90, 600);
	ObjectManager::GetInstance().Register(STAR_CHILD1, 0, 0, "hoge0", 0);
	ObjectManager::GetInstance().Register(STAR_CHILD2, 30, 23, "hoge1", 72);
	ObjectManager::GetInstance().Register(STAR_CHILD3, 19, 60, "hoge2", 144);
	ObjectManager::GetInstance().Register(STAR_CHILD4, -19, 60, "hoge3", 216);
	ObjectManager::GetInstance().Register(STAR_CHILD5, -30, 23, "hoge4", 288);
}

//------------------------------------------
//　ゲームシーン更新
void GameScene::Update() {
	
	if (Lib::KeyPress(VK_SPACE))
	{
		state_id = SS_END;
	}

	// ステージオブジェクト更新
	ObjectManager& om = ObjectManager::GetInstance();

	if (Lib::KeyPress('A')) {
		om.Delete(OBJ_TEST1);
	}

	if (Lib::KeyPress('D')) {
		om.Create(OBJ_TEST1, OBJ_CLONE1, 500,500);
		//※※改良の余地あり（new_id）※※
	}

	om.Update();


}

//------------------------------------------
//　ゲームシーン終了
SceneID GameScene::End() {

	/*if (stage->IsClear()) {
		is_clear = true;
	}*/
	state_id = SS_INIT;
	return SC_RESULT;
}

//-----------------------------------------
//　ゲームシーン状態更新
SceneID GameScene::Control() {

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
	return SC_GAME;
}

//-----------------------------------------
//　ゲームシーン描画
void GameScene::Draw() {

	
	Lib::DrawPx2D(
		"Resource/test_image/stage1_background_1 .png",
		0, 0,
		1920, 1080
	);
	
	// ステージオブジェクト描画
	ObjectManager::GetInstance().Draw();

}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

	// オブジェクトの削除
	ObjectManager::GetInstance().AllDelete();
	
}