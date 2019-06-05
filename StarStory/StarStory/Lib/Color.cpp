#include "Lib.h"

namespace Lib {

	/*
	色の生成処理
	*/
	D3DXCOLOR CreateColor(
		float red,
		float gleen,
		float blue,
		float alpha
	) {

		D3DXCOLOR color;
		color.r = (FLOAT)red;
		color.g = (FLOAT)gleen;
		color.b = (FLOAT)blue;
		color.a = (FLOAT)alpha;

		return color;
	}

};