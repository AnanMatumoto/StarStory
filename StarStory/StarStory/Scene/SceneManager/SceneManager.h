#pragma once
#include "../Scene.h"
#include <unordered_map>

//=================================
// シーンマネージャークラス
//=================================

class SceneManager {

public:

	/*
	このクラスはシングルトンで構成されています。
	呼び出し方：
		SceneManager& sm = SceneManager::GetInstance();
	*/
	static SceneManager& GetInstance();
	/*
	初期化処理
		各シーンをリストに登録。
		初めにタイトルシーンをセットする。
	*/
	void Init(SceneID scene_id);

	/*
  	更新処理
		シーン間の遷移を管理する。
	*/
	void Update();

	/*
	シーン切り替え処理	
		現在のシーンの終わりをnow_sceneで取得し、
		シーンの切り替えを行う。
	引数：
	　　　Scene_ID(現在のシーンID)
	*/
	void ChangeScene(SceneID scene_id);

	/*
	現行シーンを取得する
	*/
	SceneBase* GetScene();

	/*
	  終了状態をセットする
	引数：
	　　has_quit(終了状態フラグ)
	*/
	void SetQuit(bool has_quit);

	/*
	   終了状態に入ったフラグを取得する
	*/
	 bool GetQuitWindow();

	

	~SceneManager();

private:

	std::unordered_map<SceneID, SceneBase*> scene_list; //  シーンリスト
	SceneBase* m_scene;		// 現行シーン格納用
	SceneID    m_now_id;	// 更新されるシーンID格納用
	bool m_is_quit;			//終了処理
};