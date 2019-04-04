#pragma once
#include "../Common/Common.h"
#include "ObjectBase.h"

//=================================
// 星オブジェクト親クラス
//=================================

class StarObject : public ObjectBase{

public:

	StarObject(float x, float y);
	~StarObject()override{}

	//ToDo : ObjectBaseクラスに追加すべき?
	const float GetRot() const {
		return m_rot;
	}

private:
	void Update()override;
	void Draw()override;
	
	// ToDo:これをLibへ移動する
	// ローカル座標での描画
	void LocalTransform(
		Vertex vtx[4],
		float width, float height
	);
	

private:
	Vec2 m_vel;		     //速さ
	float m_speed;
};