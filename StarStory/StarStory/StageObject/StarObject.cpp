#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject(
	float x,
	float y,
	float rot
) : ObjectBase(x,y, rot
){

	m_width   = 1;
	m_height  = 1;
	m_vel.x   = 0;
}

void StarObject::Update() {

	m_vel.x =( Lib::KeyOn(VK_RIGHT) - Lib::KeyOn(VK_LEFT))*3.f;
	m_pos.x += m_vel.x;
	++m_rot;
	
}

void StarObject::Draw() {

	float ox = 0.f;
	float oy = 0.f;


	vtx[0].pos = { ox, oy,0.f,1.f };
	vtx[1].pos = { ox+ m_width, oy, 0.f,1.f };
	vtx[2].pos = { ox+m_width, oy + m_height,0.f, 1.f };
	vtx[3].pos = { ox, oy + m_height, 0.f, 1.f };

	BoxLocalTransform(vtx, m_width, m_height);
}


