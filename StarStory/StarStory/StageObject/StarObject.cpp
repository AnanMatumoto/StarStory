#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x,y, rot
){

	m_width   = 0;
	m_height  = 0;
	m_vel.x   = 0;
}

void StarObject::Update() {

	m_vel.x =( Lib::KeyOn(VK_RIGHT) - Lib::KeyOn(VK_LEFT))*3.f;
	m_pos.x += m_vel.x;
	++m_rot;
	
}

void StarObject::Draw() {

	vtx[0].pos = { m_pos.x, m_pos.y,0.f,1.f };
	vtx[1].pos = { m_pos.x + m_width, m_pos.y, 0.f,1.f };
	vtx[2].pos = { m_pos.x + m_width, m_pos.y + m_height,0.f, 1.f };
	vtx[3].pos = { m_pos.x, m_pos.y + m_height, 0.f, 1.f };
}


