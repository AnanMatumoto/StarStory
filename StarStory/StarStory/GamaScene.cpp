#include "Scene.h"

//-----------------------------
//　ゲームシーン初期化
void GameScene::Init() {

	Scene::g_StateID = SS_UPDATE;
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

	Scene::g_StateID = SS_END;
}

//-------------------------------
//　ゲームシーン終了
void GameScene::End() {

	/*if (stage->IsClear()) {
		is_clear = true;
	}*/
	Scene::g_StateID = SS_INIT;
	Scene::g_SceneID = SC_RESULT;
}

//------------------------------
//　ゲームシーン状態更新
void GameScene::Control() {

	switch (Scene::g_StateID)
	{
	case SS_INIT:
		Init(); break;

	case SS_UPDATE:
		Update(); break;

	case SS_END:
		End(); break;
	}
}

//-------------------------------
//　ゲームシーン描画
void GameScene::Draw() {

}