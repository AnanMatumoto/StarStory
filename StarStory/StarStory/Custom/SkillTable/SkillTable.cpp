#include"SkillTable.h"

/*----画像----*/

/*----スキル横の数字----*/
const char CUSTOM_NUM1_TEX[256] = "Resource/Custom/ui_custom_num1.png";
const char CUSTOM_NUM2_TEX[256] = "Resource/Custom/ui_custom_num2.png";
const char CUSTOM_NUM3_TEX[256] = "Resource/Custom/ui_custom_num3.png";
const char CUSTOM_NUM4_TEX[256] = "Resource/Custom/ui_custom_num4.png";
const char CUSTOM_NUM5_TEX[256] = "Resource/Custom/ui_custom_num5.png";
/*----スキル横の数字----*/

const char SKILL_TABLE_BASE_TEX[256]	= "Resource/Custom/ui_custom_skillbase.png";	// スキル表の基礎
const char SKILL_TABLE_NORAML_TEX[256]	= "Resource/Custom/UI_custom_normal.png";		// スキル表のノーマルスキル
const char SKILL_TABLE_ACCEL_TEX[256]	= "Resource/Custom/UI_custom_accel.png";		// スキル表の加速スキル
const char SKILL_TABLE_JUMP_TEX[256]	= "Resource/Custom/UI_custom_jump.png";			// スキル表のジャンプスキル
const char SKILL_TABLE_STOP_TEX[256]	= "Resource/Custom/UI_custom_stop.png";			// スキル表の停止スキル
const char SKILL_WEAK_TEX[256]			= "Resource/Custom/UI_custom_weak.png";			// スキルの弱
/*----画像----*/

/*----定数----*/
const Vec2 SKILL_TABLE_BASE_POS = {};
/*----定数----*/

/*----enum----*/
// スキル表に使う素材
enum SkillTableTex {

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

// コンストラクタ
SkillTable::SkillTable() {
	

}

// デストラクタ
SkillTable::~SkillTable() {


}

// 更新
void SkillTable::Update() {


}

// 描画
void SkillTable::Draw() {

	m_pos = SKILL_TABLE_BASE_POS;

	*m_tex = *SKILL_TABLE_BASE_TEX;

	Lib::DrawBox2D(SKILL_TABLE_BASE_TEX, m_pos.x, m_pos.y);
}

/*----初期化関数----*/
// スキル表の画像代入


// スキル表の画像代入

/*----初期化関数----*/

