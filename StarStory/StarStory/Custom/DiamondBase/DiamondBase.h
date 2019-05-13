﻿#pragma once

#include"../../Lib/Lib.h"
#include"../../Collision/Collision.h"
#include"../../Skill.h"
#include "../../SkillData/Skill_Data.h"

/*----定数----*/
// 描画の時に使用する(元画像w 32, h 23) 6.5倍
const float DIAMOND_W = 150;		// ひし形の幅
const float DIAMOND_H = 208; 		// ひし形の高さ

// 当たり判定の時に使用する
const float HALF_DIAMOND_W = DIAMOND_W / 2;		// ひし形の幅の半分
const float HALF_DIAMOND_H = DIAMOND_H / 2;		// ひし形の高さの半分
/*----定数----*/

// ひし形基底クラス
class DiamondBase {

public:
	/*----enum----*/
	// ひし形の設置場所
	enum DiamondPart {

		TOP,			// 上(基準点)
		TOP_RIGHT,		// 右上
		BOTTOM_RIGHT,	// 右下
		BOTTOM_LEFT,	// 左下
		TOP_LEFT,		// 左上

		MAX_DIAMOND_NUM
	};

	// ひし形の頂点の場所
	enum DiamondVertex {

		TOP_VERTEX,		// 上
		RIGHT_VERTEX,	// 右
		BOTTOM_VERTEX,	// 下
		LEFT_VERTEX,	// 左

		MAX_VERTEX_NUM
	};
	/*----enum----*/

public:
	// コンストラクタ
	DiamondBase() :
		// サイズ初期化
		m_size_w(DIAMOND_W),
		m_size_h(DIAMOND_H),
		m_half_size_w(HALF_DIAMOND_W),
		m_half_size_h(HALF_DIAMOND_H),

		// スキルの種類初期化(最初はすべて、NORMALで描画)
		m_skill(NORMAL){};

	// デストラクタ
	virtual ~DiamondBase() {


	};

	/*----関数----*/
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画

	// ゲッター
	virtual Skill_Data GetSkillDara() = 0;		// スキルデータを外部ファイルに保存する用
	/*----関数----*/

protected:
	/*----変数----*/
	float m_pos_x;				// x座標(ひし形の中心座標)
	float m_pos_y;				// y座標(ひし形の中心座標)
	float m_angle;				// 角度
	float m_size_w;				// 描画の時に使う幅
	float m_size_h;				// 描画の時に使う高さ
	float m_half_size_w;		// 当たり判定の時に使う幅
	float m_half_size_h;		// 当たり判定の時に使う高さ

	Vec2 m_vertex_pos[MAX_VERTEX_NUM];		// ひし形の頂点情報

	char* m_tex;						// ひし形の描画用変数
	/*----変数----*/

	/*----画像----*/
	const char NORMAL_TEX[50] = "Resource/Player/player_1_normal.png";		// NORMAL
	const char SPEED_TEX[50] = "Resource/Player/player_1_accel.png";		// SPEED
	const char JUMP_TEX[50] = "Resource/Player/player_1_jump.png";			// JUMP
	const char LIGHT_TEX[50] = "Resource/Player/player_1_light.png";		// LIGHT
	const char STOP_TEX[50] = "Resource/Player/player_1_stop.png";			// STOP
	/*----画像----*/

	/*----関数----*/
	// マウスにクリックされた時の当たり判定
	bool IsHitMouse() {

		// マウスの座標取得
		Vec2 mouse_pos = Lib::GetMousePoint();

		// マウスとの当たり判定
		if (Collision::IsInDiamond(
			m_vertex_pos[TOP_VERTEX],
			m_vertex_pos[RIGHT_VERTEX],
			m_vertex_pos[BOTTOM_VERTEX],
			m_vertex_pos[LEFT_VERTEX],
			mouse_pos) == true) {

			return true;
		}
		else {

			return false;
		}
	}
	/*----関数----*/

	/*----enum----*/
	DiamondVertex m_diamond_vertex;		// ひし形の頂点の場所
	Skill m_skill;						// スキルの情報
	DiamondPart m_diamond_part;			// ひし形を置く場所
	/*----enum----*/
};

