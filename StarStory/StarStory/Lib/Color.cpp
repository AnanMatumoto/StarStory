#include "Lib.h"

namespace Lib {

	D3DXCOLOR CreateColor(
		float r,
		float g,
		float b,
		float a
	) {

		D3DXCOLOR color;
		color.r = (FLOAT)r;
		color.g = (FLOAT)g;
		color.b = (FLOAT)b;
		color.a = (FLOAT)a;

		return color;
	}

};