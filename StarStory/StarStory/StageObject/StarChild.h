#pragma once

#include "ObjectBase.h"
#include <vector>
#include <string>

class ObjectTest1;
class StarObject;

//====================================
// 星オブジェクトの子クラス
//====================================

class StarChild :public ObjectBase {

public:
	StarChild(
		float x,
		float y,
		std::string tex_name,
		float rot
		);
	~StarChild()override{}

	//当たり判定用変数ゲッター
	const bool GetHit()const;
	void SetHit(bool is_hit_);
	//当たり判定判定処理
	void IsHitToObject();
private:
	// 更新処理
	void Update()override;
	// 描画処理
	void Draw()override;
	// 頂点座標の設定
	void SetVertex(DWORD color= 0x00ffffff)override;
	// 親の座標を反映する
	void RefParentVertex(Vertex vtx[4]);
	

private:
	std::string m_tex_name;				//画像名
	ObjectBase* m_parent;			    //親オブジェクト
	std::vector<ObjectTest1*> m_hit_obj;//マップオブジェクトのリスト
	bool is_hit;
	
};