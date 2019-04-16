#pragma once
#include "../Common/Common.h"
#include "../Object/ObjectBase.h"
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
	//　自分の親オブジェクトを取得する
	//void SetParent();

private:
	
	bool  has_y;		 //自身のY座標を取得する際のフラグ
	float m_speed;       //速さ
	Vec2  m_vel;		 //移動量
	std::vector<StarChild*> m_childs;
};