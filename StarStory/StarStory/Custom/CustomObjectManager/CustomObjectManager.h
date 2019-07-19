#pragma once

#include "../DiamondBase/DiamondBase.h"
#include "../Diamond/Diamond.h"
#include "../SkillTable/SkillTable.h"

#include<vector>

// カスタムのオブジェクトマネージャー
class CustomObjectManager {
public:
	// コンストラクタ
	CustomObjectManager();
	// 更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~CustomObjectManager();
private:
	/*----変数----*/
	// バイナリファイル読み込み用
	std::fstream m_file;
	/*----変数----*/
private:
	/*----配列----*/
	// ひし形の実体化
	std::vector<DiamondBase*> m_diamond_list;
	// スキルベースの実体化
	std::vector<SkillTable*> m_skill_table;
	/*----配列----*/
private:
	/*----enum----*/
	// ひし形の各位置
	Diamond::DiamondPart m_diamond_part;
	// スキル表の各画像
	SkillTable::ObjectID m_skill_table_object_id;
	/*----enum----*/
};

