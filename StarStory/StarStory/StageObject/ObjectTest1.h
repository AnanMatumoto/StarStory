#pragma once

#include "ObjectBase.h"

//================================
// テスト用オブジェクトクラス	
//================================

class ObjectTest1 :public ObjectBase {

public:
	ObjectTest1();
	~ObjectTest1()override {}
private:

	//　更新処理
	void Update()override;
	//　描画処理
	void Draw()override;
	//  解放状態かどうか
	const bool IsDelete()const override;
	// 複製処理
	ObjectBase* Clone() override;


	

};

