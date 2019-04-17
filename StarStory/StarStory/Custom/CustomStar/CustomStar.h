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
	//void SettingPos();

	// 更新
	void Update()override;

	// 描画
	void Draw()override;

	// デストラクタ
	//~CustomStar()override;

private:

	// 定数
	#define MAX_DIANMOND_NUM (5)	// ひし形の最大個

	// ひし形の各場所
	DiamondPos diamond_pos;

	// ひし形の各頂点座標保管場所
	Vec2 vertex[4];

	// マウス座標
	Vec2 mouse_pos;
};

