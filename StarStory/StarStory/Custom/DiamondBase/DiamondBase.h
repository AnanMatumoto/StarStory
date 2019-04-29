#pragma once

#include"../../Lib/Lib.h"
#include"../../Skill.h"

/*
おめぇーらぜってぇゲームデータみたいなところに
入れてやっかんな覚えとけよ
*/

/*----定数----*/
const int MAX_VERTEX_NUM = 4;
/*----定数----*/

/*----enum----*/
// ひし形の設置場所
enum DiamondPart {

	TOP,			// 上(基準点)
	TOP_RIGHT,		// 右上
	TOP_LEFT,		// 左上
	BOTTOM_RIGHT,	// 右下
	BOTTOM_LEFT		// 左下
};

// ひし形の頂点の場所
enum DiamondVertex {

	TOP_VERTEX,		// 上
	RIGHT_VERTEX,	// 右
	BOTTOM_VERTEX,	// 下
	LEFT_VERTEX		// 左
};
/*----enum----*/

// ひし形基底クラス
class DiamondBase {

public:

	DiamondBase() {};				// デフォルトコンストラクタ
	DiamondBase(					// コンストラクタ
		float x, float y,
		float angle,
		float w, float h,
		Vec2 vertex_pos,
		Skill id);

	virtual ~DiamondBase() {};		// デストラクタ

	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画

protected:

	/*----変数----*/
	float m_pos_x;				// x座標(ひし形の中心座標)
	float m_pos_y;				// y座標(ひし形の中心座標)
	float m_angle;				// 角度
	float m_size_w;				// 描画の時に使う幅
	float m_size_h;				// 描画の時に使う高さ
	float m_half_size_w;		// 当たり判定の時に使う幅
	float m_half_size_h;		// 当たり判定の時に使う高さ

	// ひし形の頂点情報
	Vec2 m_vertex_pos[MAX_VERTEX_NUM];
	/*----変数----*/

	/*----関数----*/
	// クリックされた時の当たり判定
	void IsHitMouse();

	// ひし形の描画
	void DrawDiamond();
	/*----関数----*/

	/*----enum----*/
	DiamondPart m_diamond_part;			// ひし形を置く場所
	DiamondVertex m_diamond_vertex;		// ひし形の頂点の場所
	Skill skill_id;						// スキルの情報
	/*----enum----*/
};

