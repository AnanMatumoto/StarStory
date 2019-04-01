#pragma once
#include "../Common/Common.h"


class StarObject {

public:
	StarObject();
	~StarObject(){}

	void Update();
	void Draw();


private:
	Vec2 m_center;//中心座用
	Vec2 m_pos[5];
	float m_rot[5];
	float m_width;
	float m_height;

	unsigned long col[5];

};