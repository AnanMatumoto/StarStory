#pragma once

#include<vector>

#include"../../Lib/Lib.h"
#include"../../Skill.h"

// スキル表クラス
class SkillTable {

public:
	/*----enum----*/
	// スキル表に使う画像のID
	enum TexID {

		/*----スキル表の基礎----*/
		BASE1,
		BASE2,
		BASE3,
		BASE4,
		BASE5,
		/*----スキル表の基礎----*/

		/*----スキル横の数字----*/
		CUSTOM_NUM1,
		CUSTOM_NUM2,
		CUSTOM_NUM3,
		CUSTOM_NUM4,
		CUSTOM_NUM5,
		/*----スキル横の数字----*/

		NORMAL_SKILL,	// ノーマルスキル
		ACCEL_SKIL,		// 加速スキル
		JUMP_SKILL,		// ジャンプスキル
		STOP_SKILL,		// 停止スキル

		/*----強弱----*/
		STRENGTH1,
		STRENGTH2,
		STRENGTH3,
		STRENGTH4,
		STRENGTH5,
		/*----強弱----*/

		MAX_TEX_NUM
	};
	/*----enum----*/

public:
	// コンストラクタ
	SkillTable(TexID skill_table_tex_id);

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
	void InitTexID(TexID tex_id);
	/*----関数----*/

	/*----enum----*/
	Skill m_skill;						// スキルID保管用
	TexID m_tex_id;	// スキル表の画像ID保管用
	/*----enum----*/
};

