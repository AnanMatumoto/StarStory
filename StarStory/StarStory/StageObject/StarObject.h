#pragma once
#include "../Common/Common.h"
#include "../Lib/Lib.h"

class StarObject {

public:
	StarObject();
	~StarObject(){}

	void Update();
	void Draw();

private:

	void Move();
	void Rotation();
	void ForEach();

private:
	Vec2 m_pos;          //中心座用
	Vec2 m_side_ps[5];   //各辺の座標
	Vec2 m_vel;		     //速さ
	float m_rot;		 //回転角
	float m_side_rot[5]; //各辺の回転角
	float m_width;       //幅
	float m_height;      //高
	float m_speed;
	unsigned long col[5];
	D3DXMATRIX world_mat;
	D3DXMATRIX rot_mat;
	D3DXMATRIX mul_mat;
	D3DXMATRIX trans_mat;
};