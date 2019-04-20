#pragma once

#include "ObjectBase.h"

//================================
// テスト用オブジェクトクラス	
//================================

class MapObject :public ObjectBase {

public:

	MapObject(float x, float y);
	~MapObject()override {}

private:

	//　更新処理
	void Update()override;
	
	//　描画処理
	void Draw()override;

	//頂点のセット
	void SetVertex(DWORD color= 0x000000)override;

};

