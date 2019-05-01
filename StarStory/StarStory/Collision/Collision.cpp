#include "Collision.h"
#include <cmath>


namespace Collision {


	//---------------------------------------
	//　三角形と点の当たり判定
	bool IsInTriangle(
		Vec2 v1, Vec2 v2,
		Vec2 v3, Vec2 point
	){
	
		float crs1 = v1.Cross(v1, v2, point);
		float crs2 = v2.Cross(v2, v3, point);
		float crs3 = v3.Cross(v3, v1, point);

		if ((crs1 > 0) && (crs2 > 0) && (crs3 > 0)) {
			return true;
		}
		return false;
	}


	//--------------------------------------
	//　菱形と点の当たり判定
	bool IsInDiamond(
		Vec2 v1, Vec2 v2,
		Vec2 v3, Vec2 v4,
		Vec2 point
	) {

		float crs1 = v1.Cross(v1, v2, point);
		float crs2 = v2.Cross(v2, v3, point);
		float crs3 = v3.Cross(v3, v4, point);
		float crs4 = v4.Cross(v4, v1, point);

		if ((crs1 > 0) && (crs2 > 0) && (crs3 > 0) && (crs4 > 0)) {
			return true;
		}
		return false;
	};

	//---------------------------------------
	//　四角形と点の当たり判定
	bool IsInSquare(
		Vec2 pos,
		float w, float h,
		Vec2 point) {

		float left = pos.x;
		float right = pos.x + w;
		float top = pos.y;
		float bottom = pos.y + h;

		if (point.x > left && point.x < right) {
			if (point.y> top && point.y < bottom) {
				return true;
			}
		}

		return false;
	}

};
