#include "StarObject.h"
#include "../Lib/Lib.h"

StarObject::StarObject() {


	m_pos = {700,300};
	m_width =  46;
	m_height = 64;
	m_vel = { 0, 0 };
	m_rot = 0;
	m_speed = 2.f;

	m_side_ps[0] = { m_pos.m_x, m_pos.m_y-m_height };
	m_side_ps[1] = { (m_pos.m_x+m_width) + 31, (m_pos.m_y-m_height) + 23 };
	m_side_ps[2] = { (m_pos.m_x+m_width) + 31, (m_pos.m_y-m_height) + 105};
	m_side_ps[3] = { (m_pos.m_x-m_width) + 45, (m_pos.m_y-m_height) + 127};
	m_side_ps[4] = { (m_pos.m_x-m_width) + 0,  (m_pos.m_y-m_height) + 61 };

	m_side_rot[0] = 0;
	m_side_rot[1] = 1.28;
	m_side_rot[2] = 2.56;
	m_side_rot[3] = -2.45;
	m_side_rot[4] = -1.2;

	col[0] = 0x000000ff;
	col[1] = 0x0000ff00;
	col[2] = 0x00ff0000;
	col[3] = 0x00ffff00;
	col[4] = 0x00ff00ff;

	D3DXMatrixIdentity(&world_mat);

}

void StarObject::Update() {

	Move();
	Rotation();
	ForEach();

}

void StarObject::Move() {

	m_vel.m_x = m_speed;
	m_pos.m_x += m_vel.m_x/60.f;
}

void StarObject::Rotation() {

	m_rot = m_speed / 60.f;
}

void StarObject::ForEach() {

	int i = 0, j = 0;
	
	if (m_vel.m_x > 0) {
		D3DXMatrixTranslation(&trans_mat, m_pos.m_x,0,0);

	}
	if (m_rot > 0) {
		D3DXMatrixRotationZ(&rot_mat,D3DXToRadian(m_rot));
	}

	D3DXMatrixMultiply(&world_mat, &rot_mat, &trans_mat);
	Lib::dev->SetTransform(D3DTS_WORLD, &world_mat);

}




void StarObject::Draw() {

	int i = 0;
	for (i = 0; i < 5; ++i) {

		Lib::DrawDaiamond2D(
			"hoge",
			m_side_ps[i].m_x,m_side_ps[i].m_y,
			m_height, m_width,
			m_side_rot[i],
			col[i],
			0,0
			);
	}


}