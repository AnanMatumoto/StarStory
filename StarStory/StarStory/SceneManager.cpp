#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager() {

	scene = new SceneBase;
}

//--------------------------------
//  シーン初期化
void SceneManager::Init() {

	Scene::g_StateID = SS_INIT;
	Scene::g_SceneID = SC_TITLE;
}

//---------------------------------
//　シーン更新
void SceneManager::Update() {


	switch (Scene::g_SceneID)
	{
	case SC_TITLE:
		scene = new TitleScene;
		scene->Control();
		scene->Draw();
		break;

	case SC_CUSTOM:
		scene = new CustomScene();
		scene->Control();
		break;
	
	case SC_SELECT:
		scene = new SelectScene();
		scene->Control();
		scene->Draw();
		break;

	case SC_GAME:
		scene = new GameScene;
		scene->Control();
		scene->Draw();
		break;

	case SC_RESULT:
		scene = new GameScene;
		scene->Control();
		scene->Draw();
		break;
	}

}


//--------------------------------
//　ゲームオブジェクトの追加
void SceneManager::AddGameObject() {

}