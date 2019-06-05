#pragma once
#include "../Scene.h"
#include <string>

//=================================
// リザルト画面クラス
//=================================

class ResultScene : public SceneBase {

private:

	//　初期化処理
	void Init() override;
	//	更新処理
	void Update() override;
	//　終了処理
	SceneID End() override;
	//　状態遷移
	SceneID Control() override;
	//　描画処理
	void Draw() override;

	~ResultScene() override{}

private:
	SceneID     m_scene_id;  //シーン遷移保存用変数
	std::string m_tex_name;    //ロゴ画像保存要変数
};

