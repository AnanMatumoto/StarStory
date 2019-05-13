#pragma once

#include"../../Lib/Lib.h"
#include"../../Skill.h"
#include"../CustomStar/CustomStar.h"

#include<vector>

/*----enum----*/
// スキル表に使う画像のID
enum SkillTableTexID {

	SKILL_TABLE_BASE,		// スキル表の基礎

	/*----スキル横の数字----*/
	CUSTOM_NUM1,
	CUSTOM_NUM2,
	CUSTOM_NUM3,
	CUSTOM_NUM4,
	CUSTOM_NUM5,
	/*----スキル横の数字----*/

	SKILL_TABLE_NORAML,		// ノーマルスキル
	SKILL_TABLE_ACCEL,		// 加速スキル
	SKILL_TABLE_JUMP,		// ジャンプスキル
	SKILL_TABLE_STOP,		// 停止スキル
	SKILL_WEAK,				// 弱

	MAX_TEX_NUM
};
/*----enum----*/

// スキル表クラス
class SkillTable {

public:
	// コンストラクタ
	SkillTable(SkillTableTexID m_skill_table_tex_id);

	// デストラクタ
	~SkillTable();

	void Update();	// 更新
	void Draw();	// 描画

private:
	/*----変数----*/
	Vec2 m_pos;				// 描画用座標
	Lib::Texture m_tex;		// 描画画像用
	/*----変数----*/

	/*----関数----*/
	void InitSkillTableID();
	/*----関数----*/

	/*----enum----*/
	Skill m_skill;						// スキルID保管用
	SkillTableTexID m_skill_table_tex_id;	// スキル表の画像ID保管用
	/*----enum----*/
};

