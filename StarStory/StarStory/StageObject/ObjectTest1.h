#pragma once

#include "ObjectBase.h"

//================================
// テスト用オブジェクトクラス	
//================================

class ObjectTest1 :public ObjectBase {

public:
	ObjectTest1(float x, float y);
	~ObjectTest1()override {}
private:

	//　更新処理
	void Update()override;
	//　描画処理
	void Draw()override;
	//頂点座標をセットする
	void SetVertex(DWORD color = 0x00ffffff)override;


};

