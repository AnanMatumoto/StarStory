#include"../../Collision/Collision.h"
#include"DiamondBase.h"
#include"../../UI/UIManager.h"

using namespace Lib;
using namespace Collision;

// コンストラクタ
DiamondBase::DiamondBase(
	float x, float y,
	float angle,
	float w, float h,
	Vec2 vertex_pos,
	Skill id) {

	m_pos_x = x;
	m_pos_y = y;
	m_angle = angle;
	m_size_w = w;
	m_size_h = h;
	m_half_size_w = w / 2;
	m_half_size_h = h / 2;
	m_vertex_pos[MAX_VERTEX_NUM] = vertex_pos;
	skill_id = id;
}

// マウスにクリックされたときの当たり判定
void DiamondBase::IsHitMouse() {

	// マウスの座標取得
	Vec2 mouse_pos = GetMousePoint();

	// マウスとの当たり判定
	if (IsInDiamond(
		m_vertex_pos[TOP_VERTEX],
		m_vertex_pos[RIGHT_VERTEX],
		m_vertex_pos[BOTTOM_VERTEX],
		m_vertex_pos[LEFT_VERTEX],
		mouse_pos
	) == true) {

	// カスタムシーンに保存されている、スキルIDを取得する
	}
}

// ひし形を描画
/*
	引数で描画に必要な値をとってくる
*/
void DiamondBase::DrawDiamond() {

	// ひし形描画
	DrawDaiamond2D(
		"hoge",
		m_pos_x, m_pos_y,
		m_size_w, m_size_h, 
		m_angle);
}

