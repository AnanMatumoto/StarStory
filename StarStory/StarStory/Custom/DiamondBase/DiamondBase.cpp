#include"DiamondBase.h"


const float DiamondBase::SIZE_W = 384.f;		// ひし形の幅
const float DiamondBase::SIZE_H = 384.f;		// ひし形の高さ

// 当たり判定用
const float DiamondBase::COLLISION_W = SIZE_W / 5;
const float DiamondBase::COLLISION_H = SIZE_H / 5;

const char DiamondBase::NORMAL_TEX[50] = "Resource/Custom/Player_normal_384×384.png";		// NORMAL
const char DiamondBase::SPEED_TEX[50] = "Resource/Custom/Player_accel_384×384.png";		// SPEED
const char DiamondBase::JUMP_TEX[50] = "Resource/Custom/Player_jump_384×384.png";			// JUMP
const char DiamondBase::STOP_TEX[50] = "Resource/Custom/Player_stop_384×384.png";			// STOP

