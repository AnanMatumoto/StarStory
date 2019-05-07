#pragma once
#include "Scene.h"
#include"../Lib/Lib.h"
#include"../Custom/CustomStar/CustomStar.h"
#include"../Custom/SkillTable/SkillTable.h"
#include"../Skill.h"

// スキルデータ
struct SkillData {

	// スキルID
	Skill skill_id;

	// スキルのリソース(char型)
	char  tex_name[50];

	// SEのリソース(char型)
	char  se_name[50];
};

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

	// カスタムスターの実体化
	CustomStar m_custom_star;

	// シーンID管理用
	SceneID m_scene_id;

	// スキルデータ保管用
	SkillData m_skill_data[MAX_DIAMOND_NUM];
};

