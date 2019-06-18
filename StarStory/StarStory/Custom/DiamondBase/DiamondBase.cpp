#include"DiamondBase.h"

/*----定数----*/
/*----描画用----*/
const float DiamondBase::SIZE_W = 384.f;
const float DiamondBase::SIZE_H = 384.f;
/*----描画用----*/

/*----当たり判定用----*/
const float DiamondBase::COLLISION_W = SIZE_W / 5;
const float DiamondBase::COLLISION_H = SIZE_H / 5;
/*----当たり判定用----*/
/*----定数----*/

/*----画像----*/
const char *DiamondBase::NORMAL_TEX = "Resource/Custom/Player_normal_384×384.png";		// NORMAL
const char *DiamondBase::SPEED_TEX = "Resource/Custom/Player_accel_384×384.png";		// SPEED
const char *DiamondBase::JUMP_TEX = "Resource/Custom/Player_jump_384×384.png";			// JUMP
const char *DiamondBase::STOP_TEX = "Resource/Custom/Player_stop_384×384.png";			// STOP
/*----画像----*/

/*----ゲッター----*/
// スキルデータを外部ファイルに保存する用
Skill_Data DiamondBase::GetSkillDara() {
	switch (m_skill) {
	// ジャンプスキル
	case JUMP:
		m_skill_data = { m_skill,STAR_JUMP_SE,"Resource/Player/player_1_jump.png" };
		break;
	// 加速スキル
	case SPEED:
		m_skill_data = { m_skill,STAR_ACCEL_SE,"Resource/Player/player_1_accel.png" };
		break;
	// 停止スキル
	case STOP:
		m_skill_data = { m_skill,STAR_STOP_SE,"Resource/Player/player_1_stop.png" };
		break;
	// ノーマルスキル
	default:
		m_skill_data = { m_skill,STAR_NORMAL_SE,"Resource/Player/player_1_normal.png" };
		break;
	}
	return m_skill_data;
}
/*----ゲッター----*/

