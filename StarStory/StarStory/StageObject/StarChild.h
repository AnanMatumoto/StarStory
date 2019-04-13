#pragma once

#include "ObjectBase.h"
#include <vector>

class ObjectTest1;
class StarObject;

//====================================
// 星オブジェクトの子クラス
//====================================

class StarChild :public ObjectBase {

public:
	StarChild(float x, float y, float rot);
	~StarChild()override{}

	/*　自身の頂点とオブジェクトが当たっているかを判定し
		その結果を返す
	*/
	bool GetIsHit();

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

	ObjectBase* m_parent;			    //親オブジェクト
	std::vector<ObjectTest1*> m_hit_obj;//マップオブジェクトのリスト
	
};