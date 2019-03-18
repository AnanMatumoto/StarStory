#pragma once
#include "Scene.h"
#include <unordered_map>

/*
	＜シーンマネージャークラス＞
	Init　		   ：初期化処理
	Update		   ：更新処理
	CreateNextScene:シーン遷移処理
	SetSceneID     ：シーンIDセット
	SceneRegister  ：シーン登録処理

*/
class SceneManager {

public:

	//シングルトン
	static SceneManager& GetInstance();
	void Init();
	void Update();
	void ChangeScene(SceneID);
	//void AddGameObject();
	~SceneManager();

private:
	
	
	std::unordered_map<SceneID, SceneBase*> scene_list;
	SceneBase* scene;
	SceneID    scene_id;
};