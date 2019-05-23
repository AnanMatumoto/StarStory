#include"SkillTable.h"
#include"../../Collision/Collision.h"
#include"../../Skill.h"

// スキル表に必要なもの
namespace SKILL_TABLE {
	/*----画像----*/

	/*----スキル横の数字----*/
	const char NUM1_TEX[50] = "Resource/Custom/ui_custom_num1.png";
	const char NUM2_TEX[50] = "Resource/Custom/ui_custom_num2.png";
	const char NUM3_TEX[50] = "Resource/Custom/ui_custom_num3.png";
	const char NUM4_TEX[50] = "Resource/Custom/ui_custom_num4.png";
	const char NUM5_TEX[50] = "Resource/Custom/ui_custom_num5.png";
	/*----スキル横の数字----*/

	const char BASE_TEX[50] = "Resource/Custom/ui_custom_skillbase.png";			// スキル表の基礎
	const char NORAML_SKILL_TEX[50] = "Resource/Custom/UI_custom_normal.png";		// スキル表のノーマルスキル
	const char ACCEL_SKILL_TEX[50] = "Resource/Custom/UI_custom_accel.png";			// スキル表の加速スキル
	const char JUMP_SKILL_TEX[50] = "Resource/Custom/UI_custom_jump.png";			// スキル表のジャンプスキル
	const char STOP_SKILL_TEX[50] = "Resource/Custom/UI_custom_stop.png";			// スキル表の停止スキル
	const char WEAK_TEX[50] = "Resource/Custom/UI_custom_weak.png";					// スキルの弱
	/*----画像----*/

	/*----定数----*/
	const float SHIFT_VALUE = 104;		// スキル表の画像をずらす値

	// 画像の初期位置
	const Vec2 BASE_POS = { 1075.f,218.f };
	const Vec2 SKILL_POS = { 1183.f,233.f };
	const Vec2 NUM_POS = { 1106.f,244.f };
	const Vec2 STRENGTH_POS = { 1569.f,237.f };
	/*----定数----*/
}

using namespace SKILL_TABLE;

// コンストラクタ
SkillTable::SkillTable(TexID tex_id){

	// スキルID識別
	InitTexID(tex_id);
};

// デストラクタ
SkillTable::~SkillTable() {

	m_tex_id = BASE1;
}

// 更新
void SkillTable::Update() {

	// スキルのテクスチャの時に当たり判定を取る
	if (m_tex_id 
		== NORMAL_SKILL 
		|| ACCEL_SKIL 
		|| JUMP_SKILL 
		|| STOP_SKILL) {

		// マウス座標の取得
		Vec2 mouse_pos = Lib::GetMousePoint();

		// マウスが表にあるスキルのどれかをクリックしたら
		if (Collision::IsInSquare(
			m_pos, m_tex.GetSize().x, m_tex.GetSize().y,
			mouse_pos) == true) {

			// スキルをセット
			Skill_ID &skill_id = Skill_ID::GetInstance();
			skill_id.SetSkillID(m_skill);
		}
	}
}

// 描画
void SkillTable::Draw() {

	Lib::DrawBox2D(m_tex, m_pos.x, m_pos.y);
	
	Lib::DrawBox2D(NUM1_TEX, NUM_POS.x,NUM_POS.y,1.0f,1.0f,0.f, Lib::CreateColor(1.f, 1.f, 1.f, 0.f));
	Lib::DrawBox2D(NUM2_TEX, NUM_POS.x,NUM_POS.y + SHIFT_VALUE,1.0f,1.0f,0.f, Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f));
	Lib::DrawBox2D(NUM3_TEX, NUM_POS.x,NUM_POS.y + SHIFT_VALUE*2,1.0f,1.0f,0.f, Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f));
	Lib::DrawBox2D(NUM4_TEX, NUM_POS.x,NUM_POS.y + SHIFT_VALUE*3,1.0f,1.0f,0.f, Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f));
	Lib::DrawBox2D(NUM5_TEX, NUM_POS.x,NUM_POS.y + SHIFT_VALUE*4,1.0f,1.0f,0.f, Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f));
}

/*----初期化関数----*/
// スキル表の画像ID
void SkillTable::InitTexID(TexID tex_id) {

	switch (tex_id) {

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
/*
		m_tex = NUM1_TEX;

		m_pos = NUM_POS;
*/
		break;

	case CUSTOM_NUM2:
/*
		m_tex = NUM2_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE;
*/
		break;

	case CUSTOM_NUM3:
/*
		m_tex = NUM3_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE * 2;
*/
		break;

	case CUSTOM_NUM4:
/*
		m_tex = NUM4_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE * 3;
*/
		break;

	case CUSTOM_NUM5:
/*
		m_tex = NUM5_TEX;

		m_pos = NUM_POS;

		m_pos.y += SHIFT_VALUE * 4;
*/
		break;

	case NORMAL_SKILL:

		m_tex = NORAML_SKILL_TEX;

		m_pos = SKILL_POS;

		m_skill = NORMAL;

		break;

	case ACCEL_SKIL:

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

	case STRENGTH5:

		m_tex = WEAK_TEX;

		m_pos = STRENGTH_POS;

		m_pos.y += SHIFT_VALUE * 4;

		break;

	default :

		break;
	}
}
/*----初期化関数----*/

