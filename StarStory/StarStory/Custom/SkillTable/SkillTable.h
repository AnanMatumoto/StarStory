#pragma once

#include "../../Lib/Lib.h"
#include "../../SkillData/Skill_Data.h"
#include "../DiamondBase/DiamondBase.h"

#include <fstream>

// スキル表
class SkillTable {
public:
	/*----enum----*/
	// オブジェクトID
	enum ObjectID {
		// 番号
		CUSTOM_NUM,
		// スキル
		SKILL,
		// 右方向の三角形
		RIGHT_TRIANGLE,
		// 左方向の三角形
		LEFT_TRIANGLE,

		MAX_OBJECT_NUM
	};
	/*----enum----*/
public :
	// コンストラクタ
	SkillTable(DiamondBase::DiamondPart diamond_part, std::string data_file);
	// 更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~SkillTable() {};
private:
	/*----画像----*/
	/*----番号----*/
	static const char *NUM1_TEX;
	static const char *NUM2_TEX;
	static const char *NUM3_TEX;
	static const char *NUM4_TEX;
	static const char *NUM5_TEX;
	/*----番号----*/
	// ノーマルスキル
	static const char *NORMAL_SKILL_TEX;
	// 加速スキル
	static const char *ACCEL_SKILL_TEX;
	// ジャンプスキル
	static const char *JUMP_SKILL_TEX;
	// 停止スキル
	static const char *STOP_SKILL_TEX;
	// 右向きの三角形
	static const char *RIGHT_TRIANGLE_TEX;
	// 左向きの三角形
	static const char *LEFT_TRIANGLE_TEX;
	/*----画像----*/
private:
	/*----定数----*/
	// スキル表の画像をずらす値
	static const float SHIFT_VALUE;
	/*----画像の初期位置----*/
	// 番号
	static const Vec2 CUSTOM_NUM_POS;
	// スキル
	static const Vec2 SKILL_POS;
	// 右向き三角形
	static const Vec2 RIGHT_TRIANGLE_POS;
	// 左向け三角形
	static const Vec2 LEFT_TRIANGLE_POS;
	/*----画像の初期位置----*/
	/*----定数----*/
private:
	/*----変数----*/
	// バイナリファイル読み込み用
	std::fstream m_file;
	// クリックしたかどうか
	bool m_is_click;
	/*----変数----*/
private:
	/*----配列----*/
	// 座標
	Vec2 m_pos[MAX_OBJECT_NUM];
	// 画像
	Lib::Texture m_tex[MAX_OBJECT_NUM];
	/*----配列----*/
private:
	/*----enum----*/
	// オブジェクトID
	ObjectID m_object_id;
	// スキルID
	Skill m_skill;
	// ひし形の番号
	DiamondBase::DiamondPart m_diamond_part;
	/*----enum----*/
private:
	/*----インスタンス----*/
	// スキルデータを外部ファイルに保存する用
	Skill_Data m_skill_data;
	/*----インスタンス----*/
private:
	/*----初期化----*/
	// 各オブジェクトの座標の初期化
	void InitObjetPos(DiamondBase::DiamondPart diamond_part);
	// 各オブジェクトの画像の初期化
	void InitObjectTex();
	// 番号画像初期化
	void InitNumTex();
	/*----初期化----*/
private:
	/*----更新----*/
	// スキルID変更
	void ChangeSkillID();
	/*----更新----*/
private :
	/*----描画----*/
	// スキル画像変更
	void ChangeSkillTex();
	/*----描画----*/
};

