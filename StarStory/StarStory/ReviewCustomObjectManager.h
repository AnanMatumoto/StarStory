#pragma once

#include"../DiamondBase/DiamondBase.h"
#include"../Diamond/Diamond.h"
#include"../SkillTable/SkillTable.h"

#include<vector>

// カスタムのオブジェクトマネージャー
class CustomObjectManager {

public:

	CustomObjectManager();		// コンストラクタ

	~CustomObjectManager();		// デストラクタ

	void Update();		// 更新

	void Draw();		// 描画

private:

	std::vector<DiamondBase*> m_diamond_base;		// ひし形の実体化
	std::vector<SkillTable*> m_skill_table;			// スキルベースの実体化

	/*----enum----*/
	Diamond::DiamondPart m_diamond_part;		// ひし形の各位置
	SkillTable::TexID skill_table_tex_id;		// スキル表の各画像
	/*----enum----*/
};