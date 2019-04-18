#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	// ひし形の幅の設定
	m_size_w = DIAMOND_W;
	m_size_h = DIAMOND_H;
}

// デストラクタ
/*--メモ--*/
/*
動的生成をする機会がないからいまいちわからない
*/
/*--メモ--*/

// 更新
void CustomStar::Update() {

	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		// ひし形の座標とマウスの座標の当たり判定
		CustomStar::CollisionMouse();
	}
}

// 描画
void CustomStar::Draw() {

	// ひし形を星型に並べて描画
	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		// ひし形のそれぞれの座標をセット
		CustomStar::SettingPos();

		// ひし形をダブルクリックしたら
		Lib::DrawDaiamond2D(
			"Resource/Custom/player_1_normal(仮).png",
			m_pos_x, m_pos_y, m_size_h, m_size_w, m_angle);
	}
}

// ひし形の座標とマウスの座標の当たり判定
void CustomStar::CollisionMouse() {

	// ひし形のそれぞれの頂点をセット
	CustomStar::SetthigVertex();

	// 星のひし形に当たったら指定の位置に画像を描画
	if (Collision::IsInDiamond(
		m_vertex_positions[0], m_vertex_positions[1], m_vertex_positions[2], m_vertex_positions[3],
		m_mouse_pos) == true) {

		// 当たり判定確認用
		Lib::DrawBox2D(
			"Resource/Custom/player_1_light.png",
			300, 200);
	}
}

// ひし形の各座標を設定
void CustomStar::SettingPos() {

	switch (m_diamond_pos) {

	case TOP:

		m_pos_x = TOP_POS_X;
		m_pos_y = TOP_POS_Y;
		m_angle = TOP_ANGLE;
		m_diamond_pos = TOP_RIGHT;
		break;

	case TOP_RIGHT:

		m_pos_x = TOP_POS_X + 150.f;
		m_pos_y = TOP_POS_Y + 110.f;
		m_angle = TOP_ANGLE + 1.26f;
		m_diamond_pos = TOP_LEFT;
		break;

	case TOP_LEFT:

		m_pos_x = TOP_POS_X - 150.f;
		m_pos_y = TOP_POS_Y + 110.f;
		m_angle = TOP_ANGLE - 1.26f;
		m_diamond_pos = BOTTOM_RIGHT;
		break;

	case BOTTOM_RIGHT:

		m_pos_x = TOP_POS_X + 90.f;
		m_pos_y = TOP_POS_Y + 285.f;
		m_angle = TOP_ANGLE + 2.52f;
		m_diamond_pos = BOTTOM_LEFT;
		break;

	case BOTTOM_LEFT:

		m_pos_x = TOP_POS_X - 90.f;
		m_pos_y = TOP_POS_Y + 285.f;
		m_angle = TOP_ANGLE - 2.52f;
		m_diamond_pos = TOP;
		break;

	default:

		m_pos_x = 0;
		m_pos_y = 0;
		m_angle = 0;
		m_diamond_pos = TOP;
		break;
	}
}

// ひし形の各頂点の座標を代入する
void CustomStar::SetthigVertex() {

	// ひし形のそれぞれの座標をセット
	CustomStar::SettingPos();

	m_vertex_positions[0] = { m_pos_x - m_size_w / 2,m_pos_y };
	m_vertex_positions[1] = { m_pos_x,m_pos_y - m_size_h / 2 };
	m_vertex_positions[2] = { m_pos_x + m_size_w / 2,m_pos_y };
	m_vertex_positions[3] = { m_pos_x,m_pos_y + m_size_h / 2 };
}

