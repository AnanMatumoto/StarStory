#include"SkillTable.h"
#include"../../Collision/Collision.h"
#include"../../Skill.h"

// スキル表に必要なもの
namespace SKILL_TABLE {
	/*----画像----*/

	/*----スキル横の数字----*/
	const char NUM1_TEX[256] = "Resource/Custom/ui_custom_num1.png";
	const char NUM2_TEX[256] = "Resource/Custom/ui_custom_num2.png";
	const char NUM3_TEX[256] = "Resource/Custom/ui_custom_num3.png";
	const char NUM4_TEX[256] = "Resource/Custom/ui_custom_num4.png";
	const char NUM5_TEX[256] = "Resource/Custom/ui_custom_num5.png";
	/*----スキル横の数字----*/

	const char BASE_TEX[256] = "Resource/Custom/ui_custom_skillbase.png";			// スキル表の基礎
	const char NORAML_SKILL_TEX[256] = "Resource/Custom/UI_custom_normal.png";		// スキル表のノーマルスキル
	const char ACCEL_SKILL_TEX[256] = "Resource/Custom/UI_custom_accel.png";		// スキル表の加速スキル
	const char JUMP_SKILL_TEX[256] = "Resource/Custom/UI_custom_jump.png";			// スキル表のジャンプスキル
	const char STOP_SKILL_TEX[256] = "Resource/Custom/UI_custom_stop.png";			// スキル表の停止スキル
	const char WEAK_TEX[256] = "Resource/Custom/UI_custom_weak.png";				// スキルの弱
	/*----画像----*/

	/*----定数----*/
	// スキル表の基礎の数
	const int BASE_NUM = 5;

	// スキル表の画像をずらす値
	const float SHIFT_VALUE = 104;

	// スキル表の基礎
	const Vec2 BASE_POS = { 1075.f,218.f };
	const Vec2 SKILL_POS = { 1183.f,233.f };
	const Vec2 NUM_POS = { 1106.f,244.f };
	const Vec2 STRENGTH_POS = { 1569.f,237.f };
	/*----定数----*/
}

using namespace SKILL_TABLE;

// コンストラクタ
SkillTable::SkillTable(SkillTableTexID skill_table_tex_id) {
	
	// IDを代入
	m_skill_table_tex_id = skill_table_tex_id;

	// スキルID識別
	InitSkillTableID();
}

// デストラクタ
SkillTable::~SkillTable() {


}

// 更新
void SkillTable::Update() {

	Vec2 mouse_pos = Lib::GetMousePoint();

	// マウスが表にあるスキルのどれかをクリックしたら
	if (Collision::IsInSquare(m_pos, m_tex.GetSize().x, m_tex.GetSize().y, mouse_pos) == true) {

		// スキルをセット
		Skill_ID &skill_id = Skill_ID::GetInstance();
		skill_id.SetSkillID(m_skill);
	}
}

// 描画
void SkillTable::Draw() {

	Lib::DrawBox2D(m_tex, m_pos.x, m_pos.y);
}

/*----初期化関数----*/
// スキル表の画像ID
void SkillTable::InitSkillTableID() {

	switch (m_skill_table_tex_id) {

	case SKILL_TABLE_BASE:

		m_pos = BASE_POS;

		m_tex = BASE_TEX;

		/*test*/
		m_skill = SPEED;
		/*test*/

		break;

	case CUSTOM_NUM1:

		m_pos = NUM_POS;

		m_tex = NUM1_TEX;

		break;

	case CUSTOM_NUM2:

		m_pos = NUM_POS;

		m_tex = NUM2_TEX;

		break;

	case CUSTOM_NUM3:

		m_pos = NUM_POS;

		m_tex = NUM3_TEX;

		break;

	case CUSTOM_NUM4:

		m_pos = NUM_POS;

		m_tex = NUM4_TEX;

		break;

	case CUSTOM_NUM5:

		m_pos = NUM_POS;

		m_tex = NUM5_TEX;

		break;

	case SKILL_TABLE_NORAML:

		m_pos = SKILL_POS;

		m_tex = NORAML_SKILL_TEX;

		break;

	case SKILL_TABLE_ACCEL:

		m_pos = SKILL_POS;

		m_tex = ACCEL_SKILL_TEX;

		break;

	case SKILL_TABLE_JUMP:

		m_pos = SKILL_POS;

		m_tex = JUMP_SKILL_TEX;

		break;

	case SKILL_TABLE_STOP:

		m_pos = SKILL_POS;

		m_tex = STOP_SKILL_TEX;

		break;

	case SKILL_WEAK:

		m_pos = STRENGTH_POS;

		m_tex = WEAK_TEX;

		break;

	default :

		m_pos = { 0,0 };

		m_tex = "hohe";

		break;
	}
}
/*----初期化関数----*/

// 

