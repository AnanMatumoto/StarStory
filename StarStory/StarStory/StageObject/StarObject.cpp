#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject() {


	m_center = {700,300};
	m_width =  46;
	m_height = 64;

	m_pos[0] = { m_center.m_x, m_center.m_y-m_height };
	m_pos[1] = { m_center.m_x + 31, (m_center.m_y-m_height) + 23 };
	m_pos[2] = { m_center.m_x + 18, (m_center.m_y-m_height) + 59 };
	m_pos[3] = { m_center.m_x - 20, (m_center.m_y-m_height) + 59 };
	m_pos[4] = { m_center.m_x - 30, (m_center.m_y-m_height) + 23 };

	m_rot[0] = 0;
	m_rot[1] = 1.28;
	m_rot[2] = 2.56;
	m_rot[3] = -2.56;
	m_rot[4] = -1.28;

	col[0] = 0x000000ff;
	col[1] = 0x0000ff00;
	col[2] = 0x00ff0000;
	col[3] = 0x00ffff00;
	col[4] = 0x00ff00ff;

}

void StarObject::Update() {

	++m_center.m_x;

}

void StarObject::Draw() {

	int i = 0;
	for (i = 0; i < 5; ++i) {

		Lib::DrawDaiamond2D(
			"hoge",
			m_pos[i].m_x,m_pos[i].m_y,
			m_height, m_width,
			m_rot[i],
			col[i]
			);
	}


}