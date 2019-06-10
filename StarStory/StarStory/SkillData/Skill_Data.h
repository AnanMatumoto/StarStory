#pragma once

#include "../Skill.h"
#include "../Sound/SoundManager/SoundManager.h"

struct Skill_Data
{
	Skill m_skill;
	SoundResourceID m_sound_resource;
    char  m_tex_name[50];
};