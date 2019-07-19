#include "SkillTable.h"
#include "../../Collision/Collision.h"

/*----画像----*/
/*----番号----*/
const char *SkillTable::NUM1_TEX = "Resource/Custom/ui_custom_num1.png";
const char *SkillTable::NUM2_TEX = "Resource/Custom/ui_custom_num2.png";
const char *SkillTable::NUM3_TEX = "Resource/Custom/ui_custom_num3.png";
const char *SkillTable::NUM4_TEX = "Resource/Custom/ui_custom_num4.png";
const char *SkillTable::NUM5_TEX = "Resource/Custom/ui_custom_num5.png";
/*----番号----*/
// ノーマルスキル
const char *SkillTable::NORMAL_SKILL_TEX = "Resource/Custom/UI_custom_normal.png";
// 加速スキル
const char *SkillTable::ACCEL_SKILL_TEX = "Resource/Custom/UI_custom_accel.png";
// ジャンプスキル
const char *SkillTable::JUMP_SKILL_TEX = "Resource/Custom/UI_custom_jump.png";
// 停止スキル
const char *SkillTable::STOP_SKILL_TEX = "Resource/Custom/UI_custom_stop.png";
// 右向きの三角形
const char *SkillTable::RIGHT_TRIANGLE_TEX = "Resource/Custom/UI_custom_right.png";
// 左向きの三角形
const char *SkillTable::LEFT_TRIANGLE_TEX = "Resource/Custom/UI_custom_left.png";
/*----画像----*/

/*----定数----*/
// スキル表の画像をずらす値
const float SkillTable::SHIFT_VALUE = 104;
/*----画像の初期位置----*/
// 番号
const Vec2 SkillTable::CUSTOM_NUM_POS{ 1106.f,244.f };
// スキル
const Vec2 SkillTable::SKILL_POS{ 1250.f,233.f };
// 右向き三角形
const Vec2 SkillTable::RIGHT_TRIANGLE_POS{ 1640.f,250.f };
// 左向け三角形
const Vec2 SkillTable::LEFT_TRIANGLE_POS{ 1200.f,250.f };
/*----画像の初期位置----*/
/*----定数----*/

/*----コンストラクタ----*/
SkillTable::SkillTable(DiamondBase::DiamondPart diamond_part, std::string data_file) :
	m_is_click(true),
	m_diamond_part(diamond_part){
	// スキルIDをバイナリデータから取得
	m_file.open(data_file, std::ios::binary | std::ios::in);
	m_file.read((char*)&m_skill_data, sizeof(Skill_Data));
	m_skill = m_skill_data.m_skill;
	m_file.close();

	// 各オブジェクトの座標の初期化
	InitObjetPos(diamond_part);
	// 各オブジェクトの画像の初期化
	InitObjectTex();
	// 番号画像初期化
	InitNumTex();
}
/*----コンストラクタ----*/

/*----更新----*/
void SkillTable::Update() {
	// スキルID変更
	ChangeSkillID();
}
/*----更新----*/

/*----描画----*/
void SkillTable::Draw() {
	// スキル画像変更用
	ChangeSkillTex();
	// オブジェクト描画
	for (int i = 0; i < MAX_OBJECT_NUM; ++i) {
		Lib::DrawBox2D(m_tex[m_object_id], m_pos[m_object_id].x, m_pos[m_object_id].y);
		m_object_id = static_cast<ObjectID>(m_object_id + 1);
	}
	// オブジェクトIDリセット
	m_object_id = CUSTOM_NUM;
}
/*----描画----*/

/*----初期化----*/
/*----各オブジェクトの座標の初期化----*/
void SkillTable::InitObjetPos(DiamondBase::DiamondPart diamond_part) {
	m_pos[CUSTOM_NUM] = CUSTOM_NUM_POS;
	m_pos[CUSTOM_NUM].y += SHIFT_VALUE * m_diamond_part;
	m_pos[SKILL] = SKILL_POS;
	m_pos[SKILL].y += SHIFT_VALUE * m_diamond_part;
	m_pos[RIGHT_TRIANGLE] = RIGHT_TRIANGLE_POS;
	m_pos[RIGHT_TRIANGLE].y += SHIFT_VALUE * m_diamond_part;
	m_pos[LEFT_TRIANGLE] = LEFT_TRIANGLE_POS;
	m_pos[LEFT_TRIANGLE].y += SHIFT_VALUE * m_diamond_part;
}
/*----各オブジェクトの座標の初期化----*/

/*----各オブジェクトの画像の初期化----*/
void SkillTable::InitObjectTex() {
	m_tex[RIGHT_TRIANGLE] = RIGHT_TRIANGLE_TEX;
	m_tex[LEFT_TRIANGLE] = LEFT_TRIANGLE_TEX;
	m_tex[SKILL] = NORMAL_SKILL_TEX;
	m_tex[CUSTOM_NUM] = NUM1_TEX;
}
/*----各オブジェクトの画像の初期化----*/

/*----番号画像初期化----*/
void SkillTable::InitNumTex() {
	// 番号によって画像変更
	switch (m_diamond_part) {
	case DiamondBase::DiamondPart::TOP_PART:
		m_tex[CUSTOM_NUM] = NUM1_TEX;
		break;
	case DiamondBase::DiamondPart::TOP_RIGHT_PART:
		m_tex[CUSTOM_NUM] = NUM2_TEX;
		break;
	case DiamondBase::DiamondPart::BOTTOM_RIGHT_PART:
		m_tex[CUSTOM_NUM] = NUM3_TEX;
		break;
	case DiamondBase::DiamondPart::BOTTOM_LEFT_PART:
		m_tex[CUSTOM_NUM] = NUM4_TEX;
		break;
	case DiamondBase::DiamondPart::TOP_LEFT_PART:
		m_tex[CUSTOM_NUM] = NUM5_TEX;
		break;
	}
}
/*----番号画像初期化----*/
/*----初期化----*/

/*----更新----*/
/*----スキルID変更----*/
void SkillTable::ChangeSkillID() {
	// マウス座標の取得
	Vec2 mouse_pos = Lib::GetMousePoint();

	// 右三角形
	if (Collision::IsInSquare(
		m_pos[RIGHT_TRIANGLE],
		m_tex[RIGHT_TRIANGLE].GetSize().x, m_tex[RIGHT_TRIANGLE].GetSize().y,
		mouse_pos) == true
		&& m_is_click == true) {

		m_is_click = false;

		m_skill = static_cast<Skill>(m_skill + 1);
		if (m_skill > STOP) {
			m_skill = NORMAL;
		}
		Skill_ID::GetInstance().SetSkillID(m_skill, m_diamond_part);
	}
	if (Collision::IsInSquare(
		m_pos[LEFT_TRIANGLE],
		m_tex[LEFT_TRIANGLE].GetSize().x, m_tex[LEFT_TRIANGLE].GetSize().y,
		mouse_pos) == true
		&& m_is_click == true) {

		m_is_click = false;

		m_skill = static_cast<Skill>(m_skill - 1);
		if (m_skill < NORMAL) {
			m_skill = STOP;
		}
		Skill_ID::GetInstance().SetSkillID(m_skill, m_diamond_part);
	}
	// マウス座標の情報が{0,0}の時もう一度クリックできるように
	if (mouse_pos.x == 0.f && mouse_pos.y == 0.f) {
		m_is_click = true;
	}
}
/*----スキルID変更----*/
/*----更新----*/

/*----描画----*/
/*----スキル画像変更用----*/
void SkillTable::ChangeSkillTex() {
	// スキルによって画像変更
	switch (m_skill) {
	case JUMP:
		m_tex[SKILL] = JUMP_SKILL_TEX;
		break;

	case SPEED:
		m_tex[SKILL] = ACCEL_SKILL_TEX;
		break;

	case STOP:
		m_tex[SKILL] = STOP_SKILL_TEX;
		break;

	default:
		m_tex[SKILL] = NORMAL_SKILL_TEX;
		break;
	}
}
/*----描画----*/

