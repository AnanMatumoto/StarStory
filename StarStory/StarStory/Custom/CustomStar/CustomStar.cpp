#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	// ひし形の幅の設定
	m_size_w = DIAMOND_W;
	m_size_h = DIAMOND_H;

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

	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		// ひし形とマウスの当たり判定
		CollisionMouse();
	}
}

// 描画
void CustomStar::Draw() {

	// 星の描画
	DrawStar();
}

// ひし形の座標とマウスの座標の当たり判定
void CustomStar::CollisionMouse() {

	// 星のひし形に当たったら指定の位置に画像を描画
	if (Collision::IsInDiamond(
		m_vertex_positions[0], m_vertex_positions[1], m_vertex_positions[2], m_vertex_positions[3],
		m_mouse_pos) == true) {

		// 当たり判定確認用
		Lib::DrawBox2D("Resource/Custom/player_1_light.png", 300, 200);
	}
}

// ひし形の各座標を設定
void CustomStar::SettingPos() {

	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		switch (m_diamond_pos) {

		case TOP:

			m_diamond_info[i].pos_x = TOP_POS_X;
			m_diamond_info[i].pos_y = TOP_POS_Y;
			m_diamond_info[i].angle = TOP_ANGLE;
			m_diamond_pos = TOP_RIGHT;
			break;

		case TOP_RIGHT:

			m_diamond_info[i].pos_x = TOP_RIGHT_POS_X;
			m_diamond_info[i].pos_y = TOP_RIGHT_POS_Y;
			m_diamond_info[i].angle = TOP_RIGHT_ANGLE;
			m_diamond_pos = TOP_LEFT;
			break;

		case TOP_LEFT:

			m_diamond_info[i].pos_x = TOP_LEFT_POS_X;
			m_diamond_info[i].pos_y = TOP_LEFT_POS_Y;
			m_diamond_info[i].angle = TOP_LEFT_ANGLE;
			m_diamond_pos = BOTTOM_RIGHT;
			break;

		case BOTTOM_RIGHT:

			m_diamond_info[i].pos_x = BOTTOM_RIGHT_POS_X;
			m_diamond_info[i].pos_y = BOTTOM_RIGHT_POS_Y;
			m_diamond_info[i].angle = BOTTOM_RIGHT_ANGLE;
			m_diamond_pos = BOTTOM_LEFT;
			break;

		case BOTTOM_LEFT:

			m_diamond_info[i].pos_x = BOTTOM_LEFT_POS_X;
			m_diamond_info[i].pos_y = BOTTOM_LEFT_POS_Y;
			m_diamond_info[i].angle = BOTTOM_LEFT_ANGLE;
			m_diamond_pos = TOP;
			break;

		default:

			m_diamond_info[i].pos_x = 0;
			m_diamond_info[i].pos_y = 0;
			m_diamond_info[i].angle = 0;
			m_diamond_pos = TOP;
			break;
		}
	}
}

// ひし形の各頂点の座標を代入する
void CustomStar::SettingVertex() {

	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {
		m_diamond_info[i].vertex_positions[0] = { m_pos_x - m_half_size_w ,m_pos_y };
		m_vertex_positions[1] = { m_pos_x,m_pos_y - m_half_size_h };
		m_vertex_positions[2] = { m_pos_x + m_half_size_w ,m_pos_y };
		m_vertex_positions[3] = { m_pos_x,m_pos_y + m_half_size_h };
	}
}

// 星型の描画
void CustomStar::DrawStar() {

	// ひし形を星型に並べて描画
	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {

		// ひし形を描画
		Lib::DrawDaiamond2D(
			"Resource/Custom/player_1_normal(仮).png",
			m_diamond_info[i].pos_x, m_diamond_info[i].pos_y,
			m_size_h, m_size_w,
			m_angle);
	}
}

