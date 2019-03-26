#include "GameScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../StageObject/StageObjectFactory.h"

//-----------------------------
//　ゲームシーン初期化
void GameScene::Init() {

	state_id = SS_UPDATE;
	//stage = new StageBase();

	m_factory = new StageObjectFactory();
	obj_list.emplace(GM_TEST1, m_factory->Create(OBJ_TEST1));
}

//------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	
	if (Lib::KeyPress(VK_SPACE))
	{
		state_id = SS_END;
	}

	//ステージオブジェクト更新
	for (auto &it : obj_list) {
		it.second->Update();
	}

	// ＊＊＊問題の箇所＊＊＊
	if (Lib::KeyOn('A')) {
	/*	auto itr =obj_list.find(GM_TEST1);
		itr->second->Delete();*/
	} 

}

//-------------------------------
//　ゲームシーン終了
SceneID GameScene::End() {

	/*if (stage->IsClear()) {
		is_clear = true;
	}*/
	state_id = SS_INIT;
	return SC_RESULT;
}

//------------------------------
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

//-------------------------------
//　ゲームシーン描画
void GameScene::Draw() {

	Lib::DrawPx2D(
		"Resource/test_image/back_sample.jpg",
		0, 0,
		1920, 1080
	);
	
	for (auto &it : obj_list) {
		it.second->Draw();
	}
}

GameScene::~GameScene() {

	for (auto& it : obj_list) {
		it.second->Delete();
	}
}