#pragma once

#include"../Lib/Lib.h"

// ひし形の基底クラス
class DiamondBase {

public:

	DiamondBase() {}				// コンストラクタ
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画
	virtual~DiamondBase() {}		// デストラクタ

protected:

	SkillId skill_id;		// スキルの種類

	D3DXVECTOR2 m_pos;		// 座標
	float m_width;			// 幅
	float m_height;			// 高さ
	float m_rot;			// 角度

	//int or bool strength;			// 強弱スキルの判別

private:



};

// スキルの種類
enum SkillId {

	SPEED,		// 加速
	JUMP,		// 跳ねる
	LIGHT,		// 光る
	STOP		// 停止
};

// ひし形の区別に必要な情報
struct SkillInfo {

	SkillId skill_id;

};

/*必要なもの

	ひし形の描画
	更新

	情報を渡すときに必要な情報
	スキルの種類
	描画の情報

*/

