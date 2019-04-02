#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject() {


	m_pos = {700,300};
	m_width =  46;
	m_height = 64;
	m_vel = { 3.f, 0 };
	m_rot = 0;

	m_side_ps[0] = { m_pos.m_x, m_pos.m_y-m_height };
	m_side_ps[1] = { m_pos.m_x + 31, (m_pos.m_y-m_height) + 23 };
	m_side_ps[2] = { m_pos.m_x + 18, (m_pos.m_y-m_height) + 59 };
	m_side_ps[3] = { m_pos.m_x - 20, (m_pos.m_y-m_height) + 59 };
	m_side_ps[4] = { m_pos.m_x - 30, (m_pos.m_y-m_height) + 23 };

	m_side_rot[0] = 0;
	m_side_rot[1] = 1.28;
	m_side_rot[2] = 2.56;
	m_side_rot[3] = -2.56;
	m_side_rot[4] = -1.28;

	col[0] = 0x000000ff;
	col[1] = 0x0000ff00;
	col[2] = 0x00ff0000;
	col[3] = 0x00ffff00;
	col[4] = 0x00ff00ff;

}

void StarObject::Update() {

	Move();
	Rotation();
	ForEach();

}

void StarObject::Move() {

	++m_vel.m_x;
	m_vel / 50.f;
	m_pos.m_x += m_vel.m_x;
}

void StarObject::Rotation() {

	++m_rot;
	m_rot / 60.f;
}

void StarObject::ForEach() {

	int i = 0, j = 0;
	
	if (m_vel.m_x > 0) {
		for (i = 0; i < 5; ++i) {
			m_side_ps[i].m_x += m_vel.m_x;
		}
	}
	if (m_rot > 0) {
		for (j = 0; j < 5; ++j) {
			m_side_rot[j] += m_rot;
		}
	}

}




void StarObject::Draw() {

	int i = 0;
	for (i = 0; i < 5; ++i) {

		Lib::DrawDaiamond2D(
			"hoge",
			m_side_ps[i].m_x,m_side_ps[i].m_y,
			m_height, m_width,
			m_side_rot[i],
			col[i]
			);
	}


}