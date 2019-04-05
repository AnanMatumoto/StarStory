#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject(float x, float y) : ObjectBase(x,y){

	m_width   = 128.f;
	m_height  = 128.f;
	m_vel.x   = 0;
	m_rot     = 0;

	//LocalTransform(vtx, m_width, m_height);

}

void StarObject::Update() {

	m_vel.x =( Lib::KeyOn(VK_RIGHT) - Lib::KeyOn(VK_LEFT))*3.f;
	m_pos.x += m_vel.x;

}


void StarObject::Draw() {

	
	Lib::DrawPx2D(
		"abc",
		m_pos.x, m_pos.y,
		m_width, m_height
		);


}
