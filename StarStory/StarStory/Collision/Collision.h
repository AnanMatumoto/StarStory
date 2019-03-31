#pragma once
#include "../Lib//Lib.h"

namespace Collision {

	/*
		三角形と点の当たり判定

		第1～3：三角形の各辺
	　　第4　 ：マウスポイントまたはそれ以外の点
	*/

	bool IsInTriangle(
		Vec2 v1, Vec2 v2,
		Vec2 v3, Vec2 point
	);

	/*
		菱形と点の当たり判定

		第1～第4：菱形の各辺
		第5　　 ：マウスポイントまたはそれ以外の点

	◆使用例

		side[4]={ //菱形の４辺を定義
			{pos.x-w, pos.y},
			{pos.x, pos_y-h},
			{pos.x+x, pos.y},
			{pos.x, pos.y+h}
		};

		//マウスを点として保存
		t_Float2(Lib::GetPointOnDrag().x, Lib::PointOnDrag().y);

		//判定をとる
		bool is_hit = Collision::IsInDiamond(
				side[0], side[1],
				side[2], side[3],
				pf
			);
	*/
	bool IsInDiamond(
		Vec2 v1, Vec2 v2,
		Vec2 v3, Vec2 v4,
		Vec2 point
	);

	/*
		四角形と点の当たり判定
		第1：XY座標
		第2：幅
		第3：高
		第4：マウスポイントまたはそれ以外の点
	*/
	bool IsInSquare(
		Vec2 pos,
		float w, float h,
		Vec2 point);

};