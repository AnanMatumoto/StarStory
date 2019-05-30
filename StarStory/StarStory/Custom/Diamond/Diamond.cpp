#include"Diamond.h"
#include"../../Lib/Lib.h"

const float Diamond::TOP_POS_X = 632.f;
const float Diamond::TOP_POS_Y = 275.f;
const float Diamond::TOP_ANGLE = 0.f;

const float Diamond::TOP_RIGHT_POS_X = TOP_POS_X + 99.f;
const float Diamond::TOP_RIGHT_POS_Y = TOP_POS_Y + 72.f;
const float Diamond::TOP_RIGHT_ANGLE = TOP_ANGLE + 1.26f;

const float Diamond::TOP_LEFT_POS_X = TOP_POS_X - 99.f;
const float Diamond::TOP_LEFT_POS_Y = TOP_POS_Y + 72.f;
const float Diamond::TOP_LEFT_ANGLE = TOP_ANGLE - 1.26f;

const float Diamond::BOTTOM_RIGHT_POS_X = TOP_POS_X + 61.f;
const float Diamond::BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 189.f;
const float Diamond::BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.51f;

const float Diamond::BOTTOM_LEFT_POS_X = TOP_POS_X - 61.f;
const float Diamond::BOTTOM_LEFT_POS_Y = TOP_POS_Y + 189.f;
const float Diamond::BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.51f;

// コンストラクタ
Diamond::Diamond(DiamondPart part, std::string data_file){

	// ひし形の座標、角度を入れる
	InitDiamondInfo(part);

	// ひし形の頂点座標を入れる
	InitVertexPos();

	InitSkillID(data_file);
}

// デストラクタ
Diamond::~Diamond() {

}

// 更新
void Diamond::Update() {

	// スキルIDによって、画像を変更
	ChangeTex();

	// マウスとの辺り判定
	ChangeSkillID();
}

// 描画
void Diamond::Draw() {

	// ひし形描画
	Lib::DrawDaiamond2D(
		m_tex,
		m_pos_x, m_pos_y,
		m_size_h, m_size_w,
		m_angle);
}

/*----初期化関数----*/
// 各ひし形の座標(中心のx,y)と角度を初期化
void Diamond::InitDiamondInfo(DiamondPart part) {

	switch (part) {

		// 上
	case TOP_PART:
		m_pos_x = TOP_POS_X;
		m_pos_y = TOP_POS_Y;
		m_angle = TOP_ANGLE;
		break;

		// 右上
	case TOP_RIGHT_PART:
		m_pos_x = TOP_RIGHT_POS_X;
		m_pos_y = TOP_RIGHT_POS_Y;
		m_angle = TOP_RIGHT_ANGLE;
		break;

		// 左上
	case TOP_LEFT_PART:
		m_pos_x = TOP_LEFT_POS_X;
		m_pos_y = TOP_LEFT_POS_Y;
		m_angle = TOP_LEFT_ANGLE;
		break;

		// 右下
	case BOTTOM_RIGHT_PART:
		m_pos_x = BOTTOM_RIGHT_POS_X;
		m_pos_y = BOTTOM_RIGHT_POS_Y;
		m_angle = BOTTOM_RIGHT_ANGLE;
		break;

		// 左下
	case BOTTOM_LEFT_PART:
		m_pos_x = BOTTOM_LEFT_POS_X;
		m_pos_y = BOTTOM_LEFT_POS_Y;
		m_angle = BOTTOM_LEFT_ANGLE;
		break;

		// それ以外の値が入った場合
	default:
		m_pos_x = 0;
		m_pos_y = 0;
		m_angle = 0;
		break;
	}
}

// 各ひし形の頂点の座標
void Diamond::InitVertexPos() {

	m_vertex_pos[TOP_VERTEX] = { m_pos_x,m_pos_y - m_collision_h };
	m_vertex_pos[RIGHT_VERTEX] = { m_pos_x + m_collision_w,m_pos_y };
	m_vertex_pos[BOTTOM_VERTEX] = { m_pos_x,m_pos_y + m_collision_h };
	m_vertex_pos[LEFT_VERTEX] = { m_pos_x - m_collision_w,m_pos_y };
}

// スキルデータをバイナリファイルから読み込む
void Diamond::InitSkillID(std::string data_file) {

	m_file.open(data_file, std::ios::binary | std::ios::in);
	m_file.read((char*)&m_skill_data, sizeof(Skill_Data));

	m_skill = m_skill_data.m_skill;

	m_file.close();

}
/*----初期化関数----*/

/*----更新用関数----*/
// マウスにクリックされたときの当たり判定
void Diamond::ChangeSkillID() {

	if (IsHitMouse() == true) {

		// スキルIDを取得する
		Skill_ID &skill_id = Skill_ID::GetInstance();
		m_skill = skill_id.GetSkillID();
	}
}

// ひし形のスキルを判定して描画画像を変える
void Diamond::ChangeTex() {

	// スキルによって画像変更
	switch (m_skill) {

	case JUMP:
		m_tex = (char*)JUMP_TEX;
		break;

	case SPEED:
		m_tex = (char*)SPEED_TEX;
		break;

	case STOP:
		m_tex = (char*)STOP_TEX;
		break;

	default:
		m_tex = (char*)NORMAL_TEX;
		break;
	}
}
/*----更新用関数----*/

/*----ゲッター----*/
// スキルデータを外部ファイルに保存する用
Skill_Data Diamond::GetSkillDara() {

	Skill_Data skill_data;

	switch (m_skill) {

	case JUMP:

		skill_data = { m_skill,STAR_JUMP_SE,"Resource/Player/player_1_jump.png" };

		break;

	case SPEED:

		skill_data = { m_skill,STAR_ACCEL_SE,"Resource/Player/player_1_accel.png" };

		break;

	case STOP:

		skill_data = { m_skill,STAR_STOP_SE,"Resource/Player/player_1_stop.png" };

		break;

	default:

		skill_data = { m_skill,STAR_NORMAL_SE,"Resource/Player/player_1_normal.png" };

		break;
	}
	return skill_data;
}
/*----ゲッター----*/

