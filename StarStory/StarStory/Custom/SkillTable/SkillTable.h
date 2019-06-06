#pragma once

#include"../../Lib/Lib.h"
#include"../../Skill.h"

#include<vector>

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
		ACCEL_SKILL,	// 加速スキル
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

	void ClickSkillSet();

private:
	/*----変数----*/
	Vec2 m_pos;				// 描画用座標
	Lib::Texture m_tex;		// 描画画像用
	D3DXCOLOR m_brightness;		// 透明度変更用
	/*----変数----*/

	/*----関数----*/
	void InitTexID(TexID tex_id);	// テクスチャIDの初期化
	/*----関数----*/

	/*----enum----*/
	Skill m_skill;		// スキルID保管用
	TexID m_tex_id;		// スキル表の画像ID保管用
	/*----enum----*/

private:
	/*----スキル横の数字----*/
	static const char *NUM1_TEX;
	static const char *NUM2_TEX;
	static const char *NUM3_TEX;
	static const char *NUM4_TEX;
	static const char *NUM5_TEX;
	/*----スキル横の数字----*/

	static const char *BASE_TEX;				// スキル表の基礎
	static const char *NORAML_SKILL_TEX;		// スキル表のノーマルスキル
	static const char *ACCEL_SKILL_TEX;		// スキル表の加速スキル
	static const char *JUMP_SKILL_TEX;		// スキル表のジャンプスキル
	static const char *STOP_SKILL_TEX;		// スキル表の停止スキル
	static const char *WEAK_TEX;				// スキルの弱
	/*----画像----*/

	/*----定数----*/
	static const float SHIFT_VALUE;		// スキル表の画像をずらす値

	// 画像の初期位置
	static const Vec2 BASE_POS;
	static const Vec2 SKILL_POS;
	static const Vec2 NUM_POS;
	static const Vec2 STRENGTH_POS;
	/*----定数----*/
};

