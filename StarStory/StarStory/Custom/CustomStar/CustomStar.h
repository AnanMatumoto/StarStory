#pragma once

#include<vector>

#include"../../Lib/Lib.h"
#include"../../Collision/Collision.h"
#include"../DiamondBase/DiamondBase.h"

// カスタム画面の星
class CustomStar: public DiamondBase{

public:

	// コンストラクタ
	CustomStar();

	// カスタムシーンのマウス座標をセットする
	// Setter兼Getterになってしまっている
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
	~CustomStar()override;

/*--変数--*/
private:

	/*--定数--*/
	// 描画の時に使用
	const float DIAMOND_W = 230;			// ひし形の幅
	const float DIAMOND_H = 320;			// ひし形の高さ

	// 当たり判定の時に使用
	const float HALF_DIAMOND_W = DIAMOND_W / 2;		// ひし形の幅の半分
	const float HALF_DIAMOND_H = DIAMOND_H / 2;		// ひし形の高さの半分

	/*--ひし形の各座標、角度--*/
	// TOPの初期座標(x,y)と角度
	const float TOP_POS_X = 500.f;
	const float TOP_POS_Y = 500.f;
	const float TOP_ANGLE = 0.f;

	// TOP_RIGHTの初期座標(x,y)と角度
	const float TOP_RIGHT_POS_X = TOP_POS_X + 150.f;
	const float TOP_RIGHT_POS_Y = TOP_POS_Y + 110.f;
	const float TOP_RIGHT_ANGLE = TOP_ANGLE + 1.26f;

	// TOP_LEFTの初期座標(x,y)と角度
	const float TOP_LEFT_POS_X = TOP_POS_X - 150.f;
	const float TOP_LEFT_POS_Y = TOP_POS_Y + 110.f;
	const float TOP_LEFT_ANGLE = TOP_ANGLE - 1.26f;

	// BOTTOM_RIGHTの初期座標(x,y)と角度
	const float BOTTOM_RIGHT_POS_X = TOP_POS_X + 90.f;
	const float BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 285.f;
	const float BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.52f;

	// BOTTOM_LEFTの初期座標(x,y)と角度
	const float BOTTOM_LEFT_POS_X = TOP_POS_X - 90.f;
	const float BOTTOM_LEFT_POS_Y = TOP_POS_Y + 285.f;
	const float BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.52f;
	/*--ひし形の各座標、角度--*/
	/*--定数--*/

	/*--変数--*/
	// マウス座標取得用
	// カスタムシーンのfloatのマウス座標を取得
	Vec2 m_mouse_pos;
	/*--変数--*/

/*--関数--*/
private:

	/*--コンストラクタで呼ぶもの--*/
	/*
		 Vertex,Pos,Partの順番に呼び出す
	*/
	// ひし形の各頂点を代入
	void SettingVertex()override;

	// ひし形の座標
	void SettingPos()override;

	// ひし形の位置を設定
	void SettingPart()override;
	/*--コンストラクタで呼ぶもの--*/

	/*--更新するもの--*/
	// ひし形とマウスの当たり判定用
	void CollisionMouse();
	/*--更新するもの--*/

	/*--描画するもの--*/
	// 星型の描画
	void DrawStar();
	/*--描画するもの--*/
};

