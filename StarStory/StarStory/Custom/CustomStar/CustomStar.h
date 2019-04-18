#pragma once

#include<vector>

#include"../../Lib/Lib.h"
#include"../../Collision/Collision.h"
#include"../DiamondBase/DiamondBase.h"
#include"../../Skill.h"

// カスタム画面の星
class CustomStar: public DiamondBase{

public:

	// コンストラクタ
	CustomStar();

	// 更新
	void Update()override;

	// 描画
	void Draw()override;

	// デストラクタ
	~CustomStar()override;

/*--変数--*/
private:

	/*--定数--*/
	static const int MAX_DIANMOND_NUM = 5;		// ひし形の最大個
	static const int MAX_VERTEX_NUM = 4;		// ひし形の頂点の数

	const float DIAMOND_W = 230;				// ひし形の幅
	const float DIAMOND_H = 320;				// ひし形の高さ

	/*--ひし形の各座標、角度--*/
	// TOPの初期位置、角度
	const float TOP_POS_X = 500.f;
	const float TOP_POS_Y = 500.f;
	const float TOP_ANGLE = 0.f;

	// TOP_RIGHTの初期位置、角度
	const float TOP_RIGHT_POS_X = TOP_POS_X + 150.f;
	const float TOP_RIGHT_POS_Y = TOP_POS_Y + 110.f;
	const float TOP_RIGHT_ANGLE = TOP_ANGLE + 1.26f;

	// TOP_LEFTの初期位置、角度
	const float TOP_LEFT_POS_X = TOP_POS_X - 150.f;
	const float TOP_LEFT_POS_Y = TOP_POS_Y + 110.f;
	const float TOP_LEFT_ANGLE = TOP_ANGLE - 1.26f;

	// BOTTOM_RIGHTの初期位置、角度
	const float BOTTOM_RIGHT_POS_X = TOP_POS_X + 90.f;
	const float BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 285.f;
	const float BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.52f;

	// BOTTOM_LEFTの初期位置、角度
	const float BOTTOM_LEFT_POS_X = TOP_POS_X - 90.f;
	const float BOTTOM_LEFT_POS_Y = TOP_POS_Y + 285.f;
	const float BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.52f;
	/*--ひし形の各座標、角度--*/
	/*--定数--*/

	/*--変数--*/
	// ひし形が持つ情報
	DiamondInfo m_diamond_info[MAX_DIANMOND_NUM];

	// ひし形の各頂点座標保管場所
	Vec2 m_vertex_positions[MAX_VERTEX_NUM];

	// マウス座標取得用
	// カスタムシーンのfloatのマウス座標を取得
	Vec2 m_mouse_pos;
	/*--変数--*/

/*--関数--*/
private:

	/*--更新するもの--*/
	// ひし形の座標
	void SettingPos();

	// ひし形の各頂点を代入
	/*--使うところ--*/
	/*
	 カスタムスターのアップデートで
	SetthingPos()を呼ぶ前にのみ使用する
	*/
	/*--使うところ--*/
	void SettingVertex();

	// ひし形とマウスの当たり判定用
	void CollisionMouse();

	// カスタムシーンのマウス座標をセットする
	Vec2 SetMousePos(float mouse_pos_x, float mouse_pos_y) {

		m_mouse_pos.x = mouse_pos_x;
		m_mouse_pos.y = mouse_pos_y;

		return m_mouse_pos;
	}
	/*--更新するもの--*/

	/*--描画するもの--*/
	// 星型の描画
	void DrawStar();
	/*--描画するもの--*/
};

// ひし形の情報保存用
struct DiamondInfo {

	SkillId skill_id;	// スキルの情報

	float pos_x;	// x座標
	float pos_y;	// y座標

	float angle;	// 角度

	Vec2 vertex_positions[4];	// ひし形の各頂点	
};

