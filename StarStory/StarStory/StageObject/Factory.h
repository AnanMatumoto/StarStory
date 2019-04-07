#pragma once
#include "ObjectBase.h"

//================================
//　ファクトリ抽象クラス
//================================

/*
	生成を目的とするクラスは以下を継承する。

	Create：IDと一致するオブジェクトの生成を行う
	Clone ：IDと一致するオブジェクトのクローンを生成する。

*/

class Factory {

public:
	Factory(){}
	virtual ObjectBase* Create(
		int id,
		float x,
		float y,
		float rotate
	) = 0;

	~Factory(){}

};

