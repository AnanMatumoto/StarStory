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
		m_file("none"),
		m_size_w(SIZE_W),
		m_size_h(SIZE_H),
		m_collision_w(COLLISION_W),
		m_collision_h(COLLISION_H){};
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
	// ひし形の頂点情報
	Vec2 m_vertex_pos[MAX_DIAMOND_VERTEX_NUM];
	// ひし形の描画用変数
	char* m_tex;
	// バイナリファイル読み込み用
	std::fstream m_file;
	/*----変数----*/
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
private:
	/*----定数----*/
	/*----描画用----*/
	static const float SIZE_W;
	static const float SIZE_H;
	/*----描画用----*/

	/*----当たり判定用----*/
	static const float COLLISION_W;		// ひし形の幅
	static const float COLLISION_H;		// ひし形の高さ
	/*----当たり判定用----*/
	/*----定数----*/
};

