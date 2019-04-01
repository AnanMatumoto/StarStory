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
	ObjectManager::GetInstance().Register(OBJ_TEST1);
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
		om.Create(OBJ_TEST1, OBJ_CLONE1);
		//※※改良の余地あり（new_id）※※
	}


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

	StarObject star;

	Lib::DrawPx2D(
		"Resource/test_image/back_sample.jpg",
		0, 0,
		1920, 1080
	);
	
	// ステージオブジェクト描画
	ObjectManager::GetInstance().Draw();

	star.Update();
	star.Draw();
}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

	// オブジェクトの削除
	ObjectManager::GetInstance().AllDelete();
	
}