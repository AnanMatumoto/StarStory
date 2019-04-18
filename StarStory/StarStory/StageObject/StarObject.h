#pragma once
#include "../Common/Common.h"
#include "ObjectBase.h"
#include <vector>

class StarChild;

//=================================
// 星オブジェクト親クラス
//=================================

class StarObject : public ObjectBase{

public:
	StarObject(float x, float y, float rot);
	~StarObject()override{}

private:
	// 更新処理
	void Update()override;
	//描画処理
	void Draw()override;
	//　頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	// 自動操作
	void AutomaticMove();
	//  スキル発動
	void SkillActive(int skill_id);

private:

	Vec2  m_vel;		    //移動量
	float m_speed;			//速さ
	float m_jump_power;		//ジャンプ力
	float m_jump_interval;  //ジャンプ時間
	std::vector<StarChild*> m_childs;
};

