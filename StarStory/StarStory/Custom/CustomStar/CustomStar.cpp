#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	// ひし形の幅の設定(描画用)
	m_size_w = DIAMOND_W;
	m_size_h = DIAMOND_H;

	// ひし形の幅の設定(当たり判定用)
	m_half_size_w = HALF_DIAMOND_W;
	m_half_size_h = HALF_DIAMOND_H;

	// ひし形の位置を設定
	SettingPart();

	// ひし形のそれぞれの座標をセット
	SettingPos();

	// ひし形のそれぞれの頂点をセット
	SettingVertex();
}

// 基底クラスのデストラクタ
DiamondBase::~DiamondBase() {

}

// デストラクタ
CustomStar::~CustomStar() {

}

// 更新
void CustomStar::Update() {

		// ひし形とマウスの当たり判定
		CollisionMouse();
}

// 描画
void CustomStar::Draw() {

	// 星の描画
	DrawStar();
}

// ひし形の座標とマウスの座標の当たり判定
void CustomStar::CollisionMouse() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		// 星のひし形に当たったら指定の位置に画像を描画
		if (Collision::IsInDiamond(
			m_vertex_positions[i][TOP_VERTEX], m_vertex_positions[i][RIGHT_VERTEX], 
			m_vertex_positions[i][BOTTOM_VERTEX], m_vertex_positions[i][LEFT_VERTEX],
			m_mouse_pos) == true) {

			// 当たり判定確認用
			Lib::DrawBox2D("Resource/Custom/player_1_light.png", 300, 200);
		}
	}
}

// ひし形の位置を設定
void CustomStar::SettingPart() {
		
		m_diamond_part[TOP] = TOP;
		m_diamond_part[TOP_RIGHT] = TOP_RIGHT;
		m_diamond_part[TOP_LEFT] = TOP_LEFT;
		m_diamond_part[BOTTOM_RIGHT] = BOTTOM_RIGHT;
		m_diamond_part[BOTTOM_LEFT] = BOTTOM_LEFT;
}

// ひし形の各座標を設定
void CustomStar::SettingPos() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		switch (m_diamond_part[i]) {

		case TOP:

			m_pos_x[i] = TOP_POS_X;
			m_pos_y[i] = TOP_POS_Y;
			m_angle[i] = TOP_ANGLE;
			break;

		case TOP_RIGHT:

			m_pos_x[i] = TOP_RIGHT_POS_X;
			m_pos_y[i] = TOP_RIGHT_POS_Y;
			m_angle[i] = TOP_RIGHT_ANGLE;
			break;

		case TOP_LEFT:

			m_pos_x[i] = TOP_LEFT_POS_X;
			m_pos_y[i] = TOP_LEFT_POS_Y;
			m_angle[i] = TOP_LEFT_ANGLE;
			break;

		case BOTTOM_RIGHT:

			m_pos_x[i] = BOTTOM_RIGHT_POS_X;
			m_pos_y[i] = BOTTOM_RIGHT_POS_Y;
			m_angle[i] = BOTTOM_RIGHT_ANGLE;
			break;

		case BOTTOM_LEFT:

			m_pos_x[i] = BOTTOM_LEFT_POS_X;
			m_pos_y[i] = BOTTOM_LEFT_POS_Y;
			m_angle[i] = BOTTOM_LEFT_ANGLE;
			break;

		default:

			m_pos_x[i] = 0;
			m_pos_y[i] = 0;
			m_angle[i] = 0;
			break;
		}
	}
}

// ひし形の各頂点の座標を代入する
void CustomStar::SettingVertex() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {
		m_vertex_positions[i][TOP_VERTEX] = { m_pos_x[i] ,m_pos_y[i] - m_half_size_h };
		m_vertex_positions[i][RIGHT_VERTEX] = { m_pos_x[i] + m_half_size_w ,m_pos_y[i] };
		m_vertex_positions[i][BOTTOM_VERTEX] = { m_pos_x[i] ,m_pos_y[i] + m_half_size_h };
		m_vertex_positions[i][LEFT_VERTEX] = { m_pos_x[i] - m_half_size_w ,m_pos_y[i] };
	}
}

// 星型の描画
void CustomStar::DrawStar() {

	// ひし形を星型に並べて描画
	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		// ひし形を描画
		Lib::DrawDaiamond2D(
			"Resource/Custom/player_1_normal(仮).png",
			m_pos_x[i], m_pos_y[i],
			m_size_h, m_size_w,
			m_angle[i]);
	}
}

