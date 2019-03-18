#include "GameScene.h"
#include "SceneManager.h"
#include "Lib.h"

//-----------------------------
//　ゲームシーン初期化
void GameScene::Init() {

	state_id = SS_UPDATE;
	//stage = new StageBase();
}

//------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	/*
	switch (ステージのID番号)
	{
	case STAGE_1:
		stage = new Stage::Stage1;
		stage->GameControl();
		break;

	case STAGE_2:
		stage = new Stage::Stage2;
		stage->GameControl();
		break;
	}
	if (stage->GetStageID() == STAGE_END) {
		Scene::Scene::g_StateID = SS_END;
	}*/
	if (Lib::KeyPress(VK_SPACE))
	{
		state_id = SS_END;
	}
}

//-------------------------------
//　ゲームシーン終了
void GameScene::End() {

	/*if (stage->IsClear()) {
		is_clear = true;
	}*/
	state_id = SS_INIT;
	SceneManager& sm = SceneManager::GetInstance();
	sm.CreateNextScene(SC_RESULT);
}

//------------------------------
//　ゲームシーン状態更新
void GameScene::Control() {

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

//-------------------------------
//　ゲームシーン描画
void GameScene::Draw() {

	Lib::DrawPx2D(
		"Resource/test_image/back_sample.jpg",
		0, 0,
		1920,1080
	);
	
}