#pragma once

#include"../../Lib/Lib.h"

// ひし形の各場所
enum DiamondPart {

	TOP,				// 上
	TOP_RIGHT,			// 右上
	TOP_LEFT,			// 左上
	BOTTOM_RIGHT,		// 右下
	BOTTOM_LEFT,		// 左下
};

// ひし形の基底クラス
class DiamondBase {

public:

	DiamondBase() {};				// コンストラクタ
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画
	virtual~DiamondBase() = 0;		// デストラクタ

protected:

	/*--基本情報--*/
	float m_pos_x;			// x座標
	float m_pos_y;			// y座標

	// ひし形の描画に使う用
	float m_size_w;			// 幅
	float m_size_h;			// 高さ

	// ひし形の頂点に使う用
	float m_half_size_w;	// 幅
	float m_half_size_h;	// 高さ

	float m_angle;			// 角度

	DiamondPart m_diamond_pos;	// ひし形の各場所
	/*--基本情報--*/

	bool m_strength;	// 強弱スキルの判別(名前考え中)

private:

};

