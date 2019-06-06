#include"SkillTable.h"
#include"../../Collision/Collision.h"
#include"../../Skill.h"

/*----画像----*/

/*----スキル横の数字----*/
const char *SkillTable::NUM1_TEX = "Resource/Custom/ui_custom_num1.png";
const char *SkillTable::NUM2_TEX = "Resource/Custom/ui_custom_num2.png";
const char *SkillTable::NUM3_TEX = "Resource/Custom/ui_custom_num3.png";
const char *SkillTable::NUM4_TEX = "Resource/Custom/ui_custom_num4.png";
const char *SkillTable::NUM5_TEX = "Resource/Custom/ui_custom_num5.png";
/*----スキル横の数字----*/

const char *SkillTable::BASE_TEX = "Resource/Custom/ui_custom_skillbase.png";			// スキル表の基礎
const char *SkillTable::NORAML_SKILL_TEX = "Resource/Custom/UI_custom_normal.png";		// スキル表のノーマルスキル
const char *SkillTable::ACCEL_SKILL_TEX = "Resource/Custom/UI_custom_accel.png";		// スキル表の加速スキル
const char *SkillTable::JUMP_SKILL_TEX = "Resource/Custom/UI_custom_jump.png";			// スキル表のジャンプスキル
const char *SkillTable::STOP_SKILL_TEX = "Resource/Custom/UI_custom_stop.png";			// スキル表の停止スキル
const char *SkillTable::WEAK_TEX = "Resource/Custom/UI_custom_weak.png";				// スキルの弱
/*----画像----*/

/*----定数----*/
const float SkillTable::SHIFT_VALUE = 104;		// スキル表の画像をずらす値

// 画像の初期位置
const Vec2 SkillTable::BASE_POS = { 1075.f,218.f };
const Vec2 SkillTable::SKILL_POS = { 1183.f,233.f };
const Vec2 SkillTable::NUM_POS = { 1106.f,244.f };
const Vec2 SkillTable::STRENGTH_POS = { 1569.f,237.f };
/*----定数----*/

// コンストラクタ
SkillTable::SkillTable(TexID tex_id):
	m_brightness(Lib::CreateColor(1.f, 1.f, 1.f, 0.f)){

	// スキルID識別
	InitTexID(tex_id);
};

// デストラクタ
SkillTable::~SkillTable() {

}

// 更新
void SkillTable::Update() {

	// アクティブなスキルに対応するNUMを明るくする
	if (m_tex_id == CUSTOM_NUM1 && Skill_ID::GetInstance().GetSkillID() == NORMAL) {
		m_brightness = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
	}
	else if (m_tex_id == CUSTOM_NUM1 && Skill_ID::GetInstance().GetSkillID() != NORMAL) {
		m_brightness = Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f);
	}

	if (m_tex_id == CUSTOM_NUM2 && Skill_ID::GetInstance().GetSkillID() == SPEED) {
		m_brightness = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
	}
	else if (m_tex_id == CUSTOM_NUM2 && Skill_ID::GetInstance().GetSkillID() != SPEED) {
		m_brightness = Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f);
	}

	if (m_tex_id == CUSTOM_NUM3 && Skill_ID::GetInstance().GetSkillID() == JUMP) {
		m_brightness = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
	}
	else if (m_tex_id == CUSTOM_NUM3 && Skill_ID::GetInstance().GetSkillID() != JUMP) {
		m_brightness = Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f);
	}

	if (m_tex_id == CUSTOM_NUM4 && Skill_ID::GetInstance().GetSkillID() == STOP) {
		m_brightness = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
	}
	else if (m_tex_id == CUSTOM_NUM4 && Skill_ID::GetInstance().GetSkillID() != STOP) {
		m_brightness = Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f);
	}
}

// 描画
void SkillTable::Draw() {

	Lib::DrawBox2D(m_tex, m_pos.x, m_pos.y, m_brightness);
}

/*----初期化関数----*/
// スキル表の画像ID
void SkillTable::InitTexID(TexID tex_id) {

	m_tex_id = tex_id;

	switch (m_tex_id) {

	case BASE1:

		m_tex = BASE_TEX;

		m_pos = BASE_POS;

		break;

	case BASE2:

		m_tex = BASE_TEX;

		m_pos = BASE_POS;

		m_pos.y += SHIFT_VALUE;

		break;

	case BASE3:

		m_tex = BASE_TEX;

		m_pos = BASE_POS;

		m_pos.y += SHIFT_VALUE * 2;

		break;

	case BASE4:

		m_tex = BASE_TEX;

		m_pos = BASE_POS;

		m_pos.y += SHIFT_VALUE * 3;

		break;

	case BASE5:

		m_tex = BASE_TEX;

		m_pos = BASE_POS;

		m_pos.y += SHIFT_VALUE * 4;

		break;
			
	case CUSTOM_NUM1:

		m_tex = NUM1_TEX;

		m_pos = NUM_POS;

		break;

	case CUSTOM_NUM2:

		m_tex = NUM2_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE;

		break;

	case CUSTOM_NUM3:

		m_tex = NUM3_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE * 2;

		break;

	case CUSTOM_NUM4:

		m_tex = NUM4_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE * 3;

		break;

	case NORMAL_SKILL:

		m_tex = NORAML_SKILL_TEX;

		m_pos = SKILL_POS;

		m_skill = NORMAL;

		break;

	case ACCEL_SKILL:

		m_tex = ACCEL_SKILL_TEX;

		m_pos = SKILL_POS;

		m_pos.y += SHIFT_VALUE;

		m_skill = SPEED;

		break;

	case JUMP_SKILL:

		m_tex = JUMP_SKILL_TEX;

		m_pos = SKILL_POS;

		m_pos.y += SHIFT_VALUE * 2;

		m_skill = JUMP;

		break;

	case STOP_SKILL:

		m_tex = STOP_SKILL_TEX;

		m_pos = SKILL_POS;

		m_pos.y += SHIFT_VALUE * 3;

		m_skill = STOP;

		break;

	case STRENGTH1:

		m_tex = WEAK_TEX;

		m_pos = STRENGTH_POS;

		break;

	case STRENGTH2:

		m_tex = WEAK_TEX;

		m_pos = STRENGTH_POS;

		m_pos.y += SHIFT_VALUE;

		break;

	case STRENGTH3:

		m_tex = WEAK_TEX;

		m_pos = STRENGTH_POS;

		m_pos.y += SHIFT_VALUE * 2;

		break;

	case STRENGTH4:

		m_tex = WEAK_TEX;

		m_pos = STRENGTH_POS;

		m_pos.y += SHIFT_VALUE * 3;

		break;

	default :

		m_tex = "hoge";

		m_pos = { 0,0 };

		break;
	}
}
/*----初期化関数----*/

// クリックされたときにskill.hにスキルを渡す
void SkillTable::ClickSkillSet() {

	// マウス座標の取得
	Vec2 mouse_pos = Lib::GetMousePoint();

	// マウスが表にあるスキルのどれかをクリックしたら
	if (Collision::IsInSquare(
		m_pos, m_tex.GetSize().x, m_tex.GetSize().y,
		mouse_pos) == true) {

		// スキルをセット
		Skill_ID::GetInstance().SetSkillID(m_skill);
	}
}

