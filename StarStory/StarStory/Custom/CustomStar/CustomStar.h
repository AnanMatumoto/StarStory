#pragma once

#include"../../Lib/Lib.h"
#include"../../Collision/Collision.h"
#include"../DiamondBase/DiamondBase.h"

// ひし形の各場所
enum DiamondPos {

	TOP,				// 上
	TOP_RIGHT,			// 右上
	TOP_LEFT,			// 左上
	BOTTOM_RIGHT,		// 右下
	BOTTOM_LEFT,		// 左下
};

// カスタム画面の星
class CustomStar: public DiamondBase{

public:

	// コンストラクタ
	CustomStar();

	// ひし形の座標
	void SettingPos();

	// ひし形の各頂点を代入
	/*--使うところ--*/
	/*
	 カスタムスターのアップデートで
	SetthingPos()を呼ぶ前にのみ使用する
	*/
	/*--使うところ--*/
	void SetthigVertex();

	// ひし形とマウスの当たり判定用
	void CollisionMouse();

	// カスタムシーンのマウス座標をセットする
	Vec2 SetMousePos(float mouse_pos_x, float mouse_pos_y) {

		m_mouse_pos.x = mouse_pos_x;
		m_mouse_pos.y = mouse_pos_y;

		return m_mouse_pos;
	}

	// 更新
	void Update()override;

	// 描画
	void Draw()override;

	// デストラクタ
	//~CustomStar()override;

private:

	/*--定数--*/
	#define MAX_DIANMOND_NUM (5)	// ひし形の最大個
	#define MAX_VERTEX_NUM (4)		// ひし形の頂点の数
	#define DIAMOND_W (230)			// ひし形の幅
	#define DIAMOND_H (320)			// ひし形の高さ

	// TOPの初期位置、角度
	const float TOP_POS_X = 500.f;
	const float TOP_POS_Y = 500.f;
	const float TOP_ANGLE = 0.f;
	/*--定数--*/

	// ひし形の各場所
	DiamondPos m_diamond_pos;

	// ひし形の各頂点座標保管場所
	Vec2 m_vertex_positions[MAX_VERTEX_NUM];

	// マウス座標取得用
	// カスタムシーンのfloatのマウス座標を取得
	Vec2 m_mouse_pos;
};

