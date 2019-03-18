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
	SceneRegister(SC_TITLE,  new TitleScene());
	SceneRegister(SC_CUSTOM, new CustomScene());
	SceneRegister(SC_SELECT, new SelectScene());
	SceneRegister(SC_GAME,   new GameScene());
	SceneRegister(SC_RESULT, new ResultScene());

	auto it = scene_list.find(SC_TITLE);
	scene = it->second;
}

//---------------------------------
//　シーン更新
void SceneManager::Update() {


	switch (scene_id)
	{
	case SC_TITLE:
		scene->Control();
		break;

	case SC_CUSTOM:
		scene->Control();
		break;
	
	case SC_SELECT:
		scene->Control();
		break;

	case SC_GAME:
		scene->Control();
		break;

	case SC_RESULT:
		scene->Control();
		break;
	}
}

//------------------------------------
//　シーンの登録
void SceneManager::SceneRegister(
	SceneID id,
	SceneBase* sb
) {
	scene_list.emplace(id, sb);
}

//-------------------------------------
//　シーン遷移
void SceneManager::CreateNextScene(SceneID scene_id) {
	auto itr = scene_list.find(scene_id);
	scene = itr->second;
}

//--------------------------------------
//　シーンIDのセッター
void SceneManager::SetSceneID(SceneID sc_id) {
	scene_id = sc_id;
}


//--------------------------------------
//　デストラクタ
SceneManager::~SceneManager() {

	//リスト内の破棄
	for (auto & it : scene_list) {
		it.second->~SceneBase();
	}
}


