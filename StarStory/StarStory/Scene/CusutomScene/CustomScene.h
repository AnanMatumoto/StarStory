#pragma once
#include "../Scene.h"
#include"../../Custom/CustomObjectManager/CustomObjectManager.h"
#include"../../Skill.h"

//=================================
//  カスタム画面クラス
//=================================

class CustomScene :public SceneBase {

private:

	//　初期化処理
	void Init()override;

	//　更新処理
	void Update() override;

	//　終了処理
	SceneID End() override;

	//　状態遷移
	SceneID Control() override;

	//　描画処理
	void Draw() override;

	// デストラクタ
	~CustomScene()override {}

	// カスタムオブジェクトのインスタンス
	CustomObjectManager *m_custom_object_manager;

	/*----enum----*/
	// シーンID管理用
	SceneID m_scene_id;
	/*----enum----*/
};

