#pragma once
#include "Scene.h"
#include <unordered_map>

/*
	＜シーンマネージャークラス＞

	このクラスはシングルトンで構成されています。
	
	呼び出し方：
		SceneManager& sm = SceneManager::GetInstance();

	その他メソッド：
	・Init
		初期化処理。各シーンをリストに登録。
		初めにタイトルシーンをセットする。

	・Update
	　	更新処理。シーン間の遷移を管理する。

	・ChangeScene
		現在のシーンの終わりをnow_sceneで取得し、
		シーンの切り替えを行う。
*/
class SceneManager {

public:

	static SceneManager& GetInstance();
	void Init();
	void Update();
	void ChangeScene();
	~SceneManager();

private:

	std::unordered_map<SceneID, SceneBase*> scene_list; //	シーンリスト
	SceneBase* m_scene;		//　リスト内シーン格納用
	SceneID    m_now_scene; //	更新されるシーンID格納用

};