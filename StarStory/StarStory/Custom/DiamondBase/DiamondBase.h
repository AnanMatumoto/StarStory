#pragma once

#include"../../Lib/Lib.h"
#include"../../Skill.h"

// ひし形の各場所
enum DiamondPart {

	TOP,				// 上
	TOP_RIGHT,			// 右上
	TOP_LEFT,			// 左上
	BOTTOM_RIGHT,		// 右下
	BOTTOM_LEFT,		// 左下
};

// ひし形の各頂点
enum DiamondVertex {

	TOP_VERTEX,			// 上
	RIGHT_VERTEX,		// 右
	BOTTOM_VERTEX,		// 下
	LEFT_VERTEX			// 左
};

// ひし形の基底クラス
class DiamondBase {

public:

	DiamondBase() {};				// コンストラクタ
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画
	virtual~DiamondBase() = 0;		// デストラクタ

	/*--コンストラクタで呼ぶもの--*/
	/*
		 Vertex,Pos,Partの順番に呼び出す
	*/
	// ひし形の各頂点を代入
	virtual void SettingVertex() = 0;

	// ひし形の座標
	virtual void SettingPos() = 0;

	// ひし形の位置を設定
	virtual void SettingPart() = 0;
	/*--コンストラクタで呼ぶもの--*/

protected:

	/*--定数--*/
	static const int MAX_DIAMOND_NUM = 5;		// ひし形の最大個
	static const int MAX_VERTEX_NUM = 4;		// ひし形の頂点の数
	/*--定数--*/

	/*--基本情報--*/
	/*--変数--*/
	float m_pos_x_list[MAX_DIAMOND_NUM];		// x座標
	float m_pos_y_list[MAX_DIAMOND_NUM];		// y座標

	float m_angle_list[MAX_DIAMOND_NUM];		// 角度

	// ひし形の描画に使う用
	float m_size_w;			// 幅
	float m_size_h;			// 高さ

	// ひし形の頂点に使う用(当たり判定の時に使用)
	float m_half_size_w;	// 幅
	float m_half_size_h;	// 高さ

	bool m_is_strength_list[MAX_DIAMOND_NUM];	// 強弱スキルの判別(名前考え中)

	Vec2 m_vertex_pos_list[MAX_DIAMOND_NUM][MAX_VERTEX_NUM];	// ひし形の各頂点座標保管場所
	/*--変数--*/

	/*--enum--*/
	DiamondPart m_diamond_part_list[MAX_DIAMOND_NUM];		// ひし形の各場所

	DiamondVertex m_diamond_vertex;						// ひし形の各頂点の情報

	Skill m_skill_list[MAX_DIAMOND_NUM];			// スキルの情報
	/*--enum--*/
	/*--基本情報--*/

private:

};

