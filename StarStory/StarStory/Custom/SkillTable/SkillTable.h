#pragma once

#include"../../Lib/Lib.h"
#include"../../Skill.h"
#include"../CustomStar/CustomStar.h"

/*----定数----*/
const int MAX_SKILL_NUM = 5;
/*----定数----*/

// スキル表クラス
class SkillTable {

public:

	SkillTable();	// コンストラクタ
	~SkillTable();	// デストラクタ

	void Update();	// 更新
	void Draw();	// 描画

private:
	/*----変数----*/
	Vec2 m_pos;			// 描画用座標
	char m_tex[256];
	/*----変数----*/

	/*----enum----*/
	Skill m_skill_id;	// スキルID保管用
	/*----enum----*/
};

