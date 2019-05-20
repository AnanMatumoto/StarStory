#pragma once

#include "ObjectBase.h"
#include <string>

//================================
// テスト用オブジェクトクラス	
//================================

class MapObject :public ObjectBase {

public:

	MapObject(float x, float y,std::string tex_name,bool has_goal=false);
	~MapObject()override {}

private:

	//　更新処理
	void Update()override;
	
	//　描画処理
	void Draw()override;

	//頂点のセット
	void SetVertex(DWORD color= 0x00ffffff)override;

	const bool GetGoalPoint() {
		return m_has_goal;
	}

private:
	bool m_has_goal;	//ゴール判定フラグ

};

