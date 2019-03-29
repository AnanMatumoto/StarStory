#pragma once

//===================================
//  複製基底クラス
//===================================

/*
	Cloneableクラスを継承した場合、
	以下の関数により自身を複製する。

	Clone:　複製関数
*/

class Cloneable {

public:

	Cloneable(){}
	virtual Cloneable* Clone(){
	
		return new Cloneable();
	}	
	virtual ~Cloneable(){}
};