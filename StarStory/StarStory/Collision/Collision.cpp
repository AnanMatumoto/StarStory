#include "Collision.h"
#include <cmath>

namespace Collision {

	//--------------------------------------
	//　菱形と点の当たり判定
	bool IsInDiamond(
		Vec2 v1, Vec2 v2,
		Vec2 v3, Vec2 v4,
		Vec2 p
	) {

		float crs1 = v1.Cross(v1, v2, p);
		float crs2 = v2.Cross(v2, v3, p);
		float crs3 = v3.Cross(v3, v4, p);
		float crs4 = v4.Cross(v4, v1, p);

		if ((crs1 > 0) && (crs2 > 0) && (crs3 > 0) && (crs4 > 0)) {
			return true;
		}
		return false;
	}

};
