#pragma once
#include "../Common/Common.h"
#include "ObjectBase.h"
#include "StarChild.h"

//=================================
// 星オブジェクト親クラス
//=================================

class StarObject : public ObjectBase{

public:
	StarObject(float x, float y);
	~StarObject()override{}

private:
	void Update()override;
	void Draw()override;

	

private:
	Vec2 m_vel;		     //速さ
	float m_speed;
};