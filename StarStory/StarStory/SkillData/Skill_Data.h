﻿#pragma once

#include "../Skill.h"
#include "../SoundManager/SoundManager.h"

struct Skill_Data
{
	Skill m_skill;
	SoundResourceID m_sound_resource;
    char  tex_name[50];
};