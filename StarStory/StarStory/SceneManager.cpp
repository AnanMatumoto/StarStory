#include "SceneManager.h"
#include "Scene.h"


//--------------------------------
//  シーン初期化
void SceneManager::Init() {

	scene = new SceneBase;
}

//---------------------------------
//　シーン更新
void SceneManager::Update() {

	scene->Draw();
	scene->Control();
}

//--------------------------------
//　ゲームオブジェクトの追加
void SceneManager::AddGameObject() {

}