#include "SceneManager.h"
#include "TitleScene.h"
#include "CustomScene.h"
#include "SelectScene.h"
#include "GameScene.h"
#include "ResultScene.h"

//---------------------------------
//インスタンス取得
SceneManager& SceneManager::GetInstance() {
	static SceneManager sm;
	return sm;
}

//--------------------------------
//  シーン初期化
void SceneManager::Init() {

	//シーンの登録
	scene_list.emplace(SC_TITLE,  new TitleScene());
	scene_list.emplace(SC_CUSTOM, new CustomScene());
	scene_list.emplace(SC_SELECT, new SelectScene());
	scene_list.emplace(SC_GAME,   new GameScene());
	scene_list.emplace(SC_RESULT, new ResultScene());

	auto it = scene_list.find(SC_TITLE);
	scene = it->second;
}

//---------------------------------
//　シーン更新
void SceneManager::Update() {

	scene->Control();
}

//-------------------------------------
//　シーン遷移
void SceneManager::ChangeScene(SceneID scene_id) {
	auto itr = scene_list.find(scene_id);
	scene = itr->second;
}

//--------------------------------------
//　デストラクタ
SceneManager::~SceneManager() {

	//リスト内の破棄
	for (auto & it : scene_list) {
		delete it.second;
	}
	delete scene;
}


