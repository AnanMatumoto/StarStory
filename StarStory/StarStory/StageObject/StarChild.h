#pragma once

#include "ObjectBase.h"

class StarObject;

//====================================
// 星オブジェクトの子クラス
//====================================

class StarChild :public ObjectBase {

public:
	StarChild(float x, float y);
	~StarChild()override{}

private:

	void Update()override;
	void Draw()override;
	void RefParentVertex(Vertex vtx[4]);

private:

	ObjectBase* m_parent; //親オブジェクト


};