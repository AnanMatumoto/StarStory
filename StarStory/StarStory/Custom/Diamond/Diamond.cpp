#include"Diamond.h"

// コンストラクタ
Diamond::Diamond(DiamondPart part) {

	// ひし形の場所を決める
	m_diamond_part = part;

	// ひし形の座標、角度を入れる
	InitDiamondInfo();

	// ひし形の頂点座標を入れる
	InitVertexPos();
}

// デストラクタ
Diamond::~Diamond() {


}

// 更新
void Diamond::Update() {

	// マウスとの辺り判定
	ChangeSkillID();
}

// 描画
void Diamond::Draw() {

	// スキルによって画像変更
	ChangeTex();

	// ひし形描画
	DrawDaiamond2D(
		m_tex,
		m_pos_x, m_pos_y,
		m_size_h, m_size_w,
		m_angle);
}

/*----初期化関数----*/
// 各ひし形の頂点の座標
void Diamond::InitVertexPos() {

	m_vertex_pos[TOP_VERTEX] = { m_pos_x,m_pos_y - m_half_size_h };
	m_vertex_pos[RIGHT_VERTEX] = { m_pos_x + m_half_size_w,m_pos_y };
	m_vertex_pos[BOTTOM_VERTEX] = { m_pos_x,m_pos_y + m_half_size_h };
	m_vertex_pos[LEFT_VERTEX] = { m_pos_x - m_half_size_w,m_pos_y };
}

// 各ひし形の座標(中心のx,y)と角度を初期化
void Diamond::InitDiamondInfo() {

	switch (m_diamond_part) {

		// 上
	case TOP:
		m_pos_x = TOP_POS_X;
		m_pos_y = TOP_POS_Y;
		m_angle = TOP_ANGLE;
		break;

		// 右上
	case TOP_RIGHT:
		m_pos_x = TOP_RIGHT_POS_X;
		m_pos_y = TOP_RIGHT_POS_Y;
		m_angle = TOP_RIGHT_ANGLE;
		break;

		// 左上
	case TOP_LEFT:
		m_pos_x = TOP_LEFT_POS_X;
		m_pos_y = TOP_LEFT_POS_Y;
		m_angle = TOP_LEFT_ANGLE;
		break;

		// 右下
	case BOTTOM_RIGHT:
		m_pos_x = BOTTOM_RIGHT_POS_X;
		m_pos_y = BOTTOM_RIGHT_POS_Y;
		m_angle = BOTTOM_RIGHT_ANGLE;
		break;

		// 左下
	case BOTTOM_LEFT:
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
		m_tex = JUMP_TEX;
		break;

	case SPEED:
		m_tex = SPEED_TEX;
		break;

	case LIGHT:
		m_tex = LIGHT_TEX;
		break;

	case STOP:
		m_tex = STOP_TEX;
		break;

	default:
		m_tex = NORMAL_TEX;
		break;
	}
}
/*----更新用関数----*/

