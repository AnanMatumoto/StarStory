#include"Diamond.h"
#include"../../Lib/Lib.h"

/*----public----*/
/*----コンストラクタ----*/
Diamond::Diamond(DiamondPart part, std::string data_file) {
	// ひし形の位置代入
	m_diamond_part = part;
	// ひし形の座標、角度を入れる
	InitDiamondInfo(m_diamond_part);
	// ひし形の頂点座標を入れる
	InitVertexPos();
	// スキルデータをバイナリファイルから読み込む
	InitSkillID(data_file);
}
/*----コンストラクタ----*/
/*----public----*/

/*----private----*/
/*--定数--*/
/*--ひし形の各座標、角度--*/
// TOPの初期座標(x,y)と角度
const float Diamond::TOP_POS_X = 632.f;
const float Diamond::TOP_POS_Y = 275.f;
const float Diamond::TOP_ANGLE = 0.f;
// TOP_RIGHTの初期座標(x,y)と角度
const float Diamond::TOP_RIGHT_POS_X = TOP_POS_X + 99.f;
const float Diamond::TOP_RIGHT_POS_Y = TOP_POS_Y + 72.f;
const float Diamond::TOP_RIGHT_ANGLE = TOP_ANGLE + 1.26f;
// TOP_LEFTの初期座標(x,y)と角度
const float Diamond::TOP_LEFT_POS_X = TOP_POS_X - 99.f;
const float Diamond::TOP_LEFT_POS_Y = TOP_POS_Y + 72.f;
const float Diamond::TOP_LEFT_ANGLE = TOP_ANGLE - 1.26f;
// BOTTOM_RIGHTの初期座標(x,y)と角度
const float Diamond::BOTTOM_RIGHT_POS_X = TOP_POS_X + 61.f;
const float Diamond::BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 189.f;
const float Diamond::BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.51f;
// BOTTOM_LEFTの初期座標(x,y)と角度
const float Diamond::BOTTOM_LEFT_POS_X = TOP_POS_X - 61.f;
const float Diamond::BOTTOM_LEFT_POS_Y = TOP_POS_Y + 189.f;
const float Diamond::BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.51f;
/*--ひし形の各座標、角度--*/
/*--定数--*/

/*----初期化関数----*/
/*----各ひし形の座標(中心のx,y)と角度を初期化----*/
void Diamond::InitDiamondInfo(DiamondPart part) {
	switch (m_diamond_part) {
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
/*----各ひし形の座標(中心のx,y)と角度を初期化----*/

/*----各ひし形の頂点の座標の初期化----*/
void Diamond::InitVertexPos() {
	m_vertex_pos[TOP_VERTEX] = { m_pos_x,m_pos_y - m_collision_h };
	m_vertex_pos[RIGHT_VERTEX] = { m_pos_x + m_collision_w,m_pos_y };
	m_vertex_pos[BOTTOM_VERTEX] = { m_pos_x,m_pos_y + m_collision_h };
	m_vertex_pos[LEFT_VERTEX] = { m_pos_x - m_collision_w,m_pos_y };
}
/*----各ひし形の頂点の座標の初期化----*/

/*----スキルデータをバイナリファイルから読み込む----*/
void Diamond::InitSkillID(std::string data_file) {
	m_file.open(data_file, std::ios::binary | std::ios::in);
	m_file.read((char*)&m_skill_data, sizeof(Skill_Data));
	m_skill = m_skill_data.m_skill;
	m_file.close();
}
/*----スキルデータをバイナリファイルから読み込む----*/
/*----初期化関数----*/

/*----更新用関数----*/
/*----更新----*/
void Diamond::Update() {
	// スキルID更新
	UpdateSkillID();
}
/*----更新----*/

/*----スキルIDによって、画像を変更----*/
void Diamond::UpdateSkillID() {
	// スキルIDを取得する
	m_skill = Skill_ID::GetInstance().GetSkillID(m_diamond_part);
}
/*----スキルIDによって、画像を変更----*/
/*----更新用関数----*/

/*----描画用関数----*/
/*----描画----*/
void Diamond::Draw() {
	// スキルIDによって、画像を変更
	ChangeTex();
	// ひし形描画
	Lib::DrawDaiamond2D(
		m_tex,
		m_pos_x, m_pos_y,
		m_size_h, m_size_w,
		m_angle);
}
/*----描画----*/

/*----ひし形のスキルを判定して描画画像を変える----*/
void Diamond::ChangeTex() {
	// スキルによって画像変更
	switch (m_skill) {
		// ジャンプスキル
	case JUMP:
		m_tex = (char*)JUMP_TEX;
		break;
		// 加速スキル
	case SPEED:
		m_tex = (char*)SPEED_TEX;
		break;
		// 停止スキル
	case STOP:
		m_tex = (char*)STOP_TEX;
		break;
		// ノーマルスキル
	default:
		m_tex = (char*)NORMAL_TEX;
		break;
	}
}
/*----ひし形のスキルを判定して描画画像を変える----*/
/*----描画用関数----*/
/*----private----*/