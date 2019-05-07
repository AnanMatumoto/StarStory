#pragma once
#include "Scene.h"
#include"../Lib/Lib.h"
#include"../Custom/CustomStar/CustomStar.h"
#include"../Skill.h"

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
	~CustomScene()override {}

	// カスタムスターの実体化
	CustomStar custom_star;
};

struct SkillInfo {

	Skill skill_id;
};
