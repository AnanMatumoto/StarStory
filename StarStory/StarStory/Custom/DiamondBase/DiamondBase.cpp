#include"DiamondBase.h"


const float DiamondBase::DIAMOND_W = 384.f;		// ひし形の幅
const float DiamondBase::DIAMOND_H = 384.f;		// ひし形の高さ

// 当たり判定用
const float DiamondBase::COLLISION_DIAMOND_W = DIAMOND_W / 6;
const float DiamondBase::COLLISION_DIAMOND_H = DIAMOND_H / 6;

const char DiamondBase::NORMAL_TEX[50] = "Resource/Custom/Player_normal_384×384.png";		// NORMAL
const char DiamondBase::SPEED_TEX[50] = "Resource/Custom/Player_accel_384×384.png";		// SPEED
const char DiamondBase::JUMP_TEX[50] = "Resource/Custom/Player_jump_384×384.png";			// JUMP
const char DiamondBase::STOP_TEX[50] = "Resource/Custom/Player_stop_384×384.png";			// STOP

