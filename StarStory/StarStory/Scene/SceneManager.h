﻿#pragma once
#include "Scene.h"
#include <unordered_map>

//=================================
// シーンマネージャークラス
//=================================

class SceneManager {

public:

	/*
	このクラスはシングルトンで構成されています。
	呼び出し方：
		1.SceneManager& sm = SceneManager::GetInstance();
		2.SceneManager::GetInstance().Init();
	*/
	static SceneManager& GetInstance();
	/*
	 Init：
		初期化処理。各シーンをリストに登録。
		初めにタイトルシーンをセットする。
	*/
	void Init();

	/*
  	  Update:
		更新処理。シーン間の遷移を管理する。
	*/
	void Update();

	/*
	 ChangeScene:
		現在のシーンの終わりをnow_sceneで取得し、
		シーンの切り替えを行う。
	*/
	void ChangeScene(SceneID scene_id);
	~SceneManager();

private:

	std::unordered_map<SceneID, SceneBase*> scene_list; //  シーンリスト
	SceneBase* m_scene;		// 現行シーン格納用
	SceneID    m_now_id;	// 更新されるシーンID格納用

};