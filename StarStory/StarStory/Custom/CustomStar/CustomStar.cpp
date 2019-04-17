#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	// ひし形の幅の設定
	m_size_w = 230;
	m_size_h = 320;

	// 当たり判定用の頂点の初期化
	vertex[0] = { m_pos_x - m_size_w,m_pos_y };
	vertex[1] = { m_pos_x,m_pos_y - m_size_h };
	vertex[2] = { m_pos_x + m_size_w,m_pos_y };
	vertex[3] = { m_pos_x,m_pos_y + m_size_h };
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

		// 
		CustomStar::SettingPos();

		// 星のひし形に当たったら指定の位置に画像を描画
		if (Collision::IsInDiamond(
			vertex[0], vertex[1], vertex[2], vertex[3],
			mouse_pos) == true) {

			Lib::DrawBox2D(
				"Resource/Custom/player_1_light.png",
				500, 1000);
		}
	}
}

// 描画
void CustomStar::Draw() {

	// ひし形を星型に並べて描画
	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		// 
		CustomStar::SettingPos();

		Lib::DrawDaiamond2D(
			"Resource/Custom/player_1_normal(仮).png",
			m_pos_x, m_pos_y, m_size_h, m_size_w, m_angle);
	}
}

// ひし形の各座標を設定
void CustomStar::SettingPos() {

	switch (diamond_pos) {

	case TOP:

		m_pos_x = TOP_POS_X;
		m_pos_y = TOP_POS_Y;
		m_angle = TOP_ANGLE;
		diamond_pos = TOP_RIGHT;
		break;

	case TOP_RIGHT:

		m_pos_x = TOP_POS_X + 150.f;
		m_pos_y = TOP_POS_Y + 110.f;
		m_angle = TOP_ANGLE + 1.26f;
		diamond_pos = TOP_LEFT;
		break;

	case TOP_LEFT:

		m_pos_x = TOP_POS_X + 150.f;
		m_pos_y = TOP_POS_Y + 110.f;
		m_angle = TOP_ANGLE + 1.26f;
		diamond_pos = BOTTOM_RIGHT;
		break;

	case BOTTOM_RIGHT:

		m_pos_x = TOP_POS_X + 90.f;
		m_pos_y = TOP_POS_Y + 285.f;
		m_angle = TOP_ANGLE + 2.52f;
		diamond_pos = BOTTOM_RIGHT;
		break;

	case BOTTOM_LEFT:

		m_pos_x -= TOP_POS_X + 90.f;
		m_pos_y += TOP_POS_Y + 285.f;
		m_angle -= TOP_ANGLE + 2.52f;
		diamond_pos = TOP;
		break;

	default:

		m_pos_x = 0;
		m_pos_y = 0;
		m_angle = 0;
		diamond_pos = TOP;
		break;
	}
}

