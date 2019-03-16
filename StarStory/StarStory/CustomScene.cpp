#include "Scene.h"

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	Scene::g_StateID = SS_UPDATE;
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	Scene::g_StateID = SS_END;
}

//----------------------------
// 　カスタムシーン更新
void CustomScene::End() {

	Scene::g_StateID = SS_INIT;
	Scene::g_SceneID = SC_SELECT;
}

//----------------------------
//	カスタムシーン状態管理
void CustomScene::Control() {

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

//----------------------------
//　カスタムシーン描画
void CustomScene::Draw() {

}