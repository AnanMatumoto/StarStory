#pragma once
#include "../Lib//Lib.h"

namespace Collision {

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
		Vec2 p
	);

};