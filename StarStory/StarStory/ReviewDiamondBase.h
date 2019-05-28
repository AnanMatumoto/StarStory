#pragma once

#include"../../Lib/Lib.h"
#include"../../Collision/Collision.h"
#include"../../Skill.h"
#include "../../SkillData/Skill_Data.h"

#include<fstream>

// ひし形基底クラス
class DiamondBase {

public:
	/*----enum----*/
	// ひし形の設置場所
	enum DiamondPart {

		TOP_PART,			// 上(基準点)
		TOP_RIGHT_PART,		// 右上
		BOTTOM_RIGHT_PART,	// 右下
		BOTTOM_LEFT_PART,	// 左下
		TOP_LEFT_PART,		// 左上

		MAX_DIAMOND_PART_NUM
	};

	// ひし形の頂点の場所
	enum DiamondVertex {

		TOP_VERTEX,		// 上
		RIGHT_VERTEX,	// 右
		BOTTOM_VERTEX,	// 下
		LEFT_VERTEX,	// 左

		MAX_DIAMOND_VERTEX_NUM
	};
	/*----enum----*/

public:
	// コンストラクタ
	DiamondBase() :
		// スキルの種類初期化(最初はすべて、NORMALで描画)
		m_skill(NORMAL),
		m_file("none") {

		// サイズ初期化
		m_size_w = DIAMOND_W;
		m_size_h = DIAMOND_H;
		m_half_size_w = COLLISION_DIAMOND_W;
		m_half_size_h = COLLISION_DIAMOND_H;
	};

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

protected:
	/*----変数----*/
	float m_pos_x;				// x座標(ひし形の中心座標)
	float m_pos_y;				// y座標(ひし形の中心座標)
	float m_angle;				// 角度
	float m_size_w;				// 描画の時に使う幅
	float m_size_h;				// 描画の時に使う高さ
	float m_half_size_w;		// 当たり判定の時に使う幅
	float m_half_size_h;		// 当たり判定の時に使う高さ

	Vec2 m_vertex_pos[MAX_DIAMOND_VERTEX_NUM];		// ひし形の頂点情報

	char* m_tex;		// ひし形の描画用変数

	Skill_Data m_skill_data;	// スキルデータ読み込み用インスタンス
	std::fstream m_file;		// バイナリファイル読み込み用
	/*----変数----*/

	/*----enum----*/
	DiamondVertex m_diamond_vertex;		// ひし形の頂点の場所
	Skill m_skill;						// スキルの情報
	DiamondPart m_diamond_part;			// ひし形を置く場所
	/*----enum----*/

protected:
	/*----画像----*/
	static const char NORMAL_TEX[50]; 	// NORMAL
	static const char SPEED_TEX[50];	// SPEED
	static const char JUMP_TEX[50];		// JUMP
	static const char STOP_TEX[50]; 	// STOP
	/*----画像----*/

private:
	/*----定数----*/
	static const float DIAMOND_W;	// ひし形の幅
	static const float DIAMOND_H;	// ひし形の高さ

	// 当たり判定用
	static const float COLLISION_DIAMOND_W;		// ひし形の幅
	static const float COLLISION_DIAMOND_H;		// ひし形の高さ
	/*----定数----*/
};

