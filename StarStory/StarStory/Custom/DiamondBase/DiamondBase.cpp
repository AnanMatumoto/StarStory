#include"DiamondBase.h"

const float DiamondBase::SIZE_W = 384.f;		// ひし形の幅
const float DiamondBase::SIZE_H = 384.f;		// ひし形の高さ

// 当たり判定用
const float DiamondBase::COLLISION_W = SIZE_W / 5;
const float DiamondBase::COLLISION_H = SIZE_H / 5;

const char *DiamondBase::NORMAL_TEX = "Resource/Custom/Player_normal_384×384.png";		// NORMAL
const char *DiamondBase::SPEED_TEX = "Resource/Custom/Player_accel_384×384.png";		// SPEED
const char *DiamondBase::JUMP_TEX = "Resource/Custom/Player_jump_384×384.png";			// JUMP
const char *DiamondBase::STOP_TEX = "Resource/Custom/Player_stop_384×384.png";			// STOP

/*----ゲッター----*/
// スキルデータを外部ファイルに保存する用
Skill_Data DiamondBase::GetSkillDara() {

	switch (m_skill) {

	case JUMP:

		m_skill_data = { m_skill,STAR_JUMP_SE,"Resource/Player/player_1_jump.png" };

		break;

	case SPEED:

		m_skill_data = { m_skill,STAR_ACCEL_SE,"Resource/Player/player_1_accel.png" };

		break;

	case STOP:

		m_skill_data = { m_skill,STAR_STOP_SE,"Resource/Player/player_1_stop.png" };

		break;

	default:

		m_skill_data = { m_skill,STAR_NORMAL_SE,"Resource/Player/player_1_normal.png" };

		break;
	}
	return m_skill_data;
}
/*----ゲッター----*/

/*----更新関数----*/
// マウスにクリックされた時の当たり判定
bool DiamondBase::IsHitMouse() {

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
/*----更新関数----*/

