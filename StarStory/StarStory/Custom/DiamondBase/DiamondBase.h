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
		// 上(基準点)
		TOP_PART,
		// 右上
		TOP_RIGHT_PART,
		// 右下
		BOTTOM_RIGHT_PART,
		// 左下
		BOTTOM_LEFT_PART,
		// 左上
		TOP_LEFT_PART,

		MAX_DIAMOND_PART_NUM
	};
	// ひし形の頂点の場所
	enum DiamondVertex {
		// 上
		TOP_VERTEX,
		// 右
		RIGHT_VERTEX,
		// 下
		BOTTOM_VERTEX,
		// 左
		LEFT_VERTEX,

		MAX_DIAMOND_VERTEX_NUM
	};
	/*----enum----*/
public:
	// コンストラクタ
	DiamondBase() :
		m_skill(NORMAL),
		m_file("none"),
		m_size_w(SIZE_W),
		m_size_h(SIZE_H)
	{};
	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Draw() = 0;
	// デストラクタ
	virtual ~DiamondBase() {};
public:
	/*----ゲッター----*/
	// スキルデータを外部ファイルに保存する用
	Skill_Data GetSkillDara();
	/*----ゲッター----*/
protected:
	/*----変数----*/
	// x座標(ひし形の中心座標)
	float m_pos_x;
	// y座標(ひし形の中心座標)
	float m_pos_y;
	// 角度
	float m_angle;
	// 描画の時に使う幅
	float m_size_w;
	// 描画の時に使う高さ
	float m_size_h;
	// 当たり判定の時に使う幅
	float m_collision_w;
	// 当たり判定の時に使う高さ
	float m_collision_h;
	// ひし形の描画用変数
	char* m_tex;
	// バイナリファイル読み込み用
	std::fstream m_file;
	/*----変数----*/
protected:
	/*----配列----*/
	// ひし形の頂点情報
	Vec2 m_vertex_pos[MAX_DIAMOND_VERTEX_NUM];
	/*----配列----*/
protected:
	/*----インスタンス----*/
	// スキルデータ読み込み用インスタンス
	Skill_Data m_skill_data;
	/*----インスタンス----*/
protected:
	/*----enum----*/
	// ひし形の頂点の場所
	DiamondVertex m_diamond_vertex;
	// スキルの情報
	Skill m_skill;
	// ひし形を置く場所
	DiamondPart m_diamond_part;
	/*----enum----*/
protected:
	/*----画像----*/
	// NORMAL
	static const char *NORMAL_TEX;
	// SPEED
	static const char *SPEED_TEX;
	// JUMP
	static const char *JUMP_TEX;
	// STOP
	static const char *STOP_TEX;
	/*----画像----*/
protected:
	/*----定数----*/
	// 幅
	static const float SIZE_W;
	// 高さ
	static const float SIZE_H;
	/*----定数----*/
};

