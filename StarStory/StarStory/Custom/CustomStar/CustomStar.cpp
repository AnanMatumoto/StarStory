#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	// ひし形の幅の設定
	m_size_w = 230;
	m_size_h = 320;

	// 当たり判定用の頂点の初期化
	vertex[0] = { m_pos_x - m_size_w,m_pos_y };
	vertex[1] = { m_pos_x,m_pos_y - m_size_h };
	vertex[2] = { m_pos_x + m_size_w,m_pos_y };
	vertex[3] = { m_pos_x,m_pos_y + m_size_h };
}

// デストラクタ
/*--メモ--*/
/*
動的生成をする機会がないからいまいちわからない
*/
/*--メモ--*/

// 更新
void CustomStar::Update() {

	// マウスの座標を取得


	// 星のひし形に当たったら指定の位置に画像を描画
	if(Collision::IsInDiamond(
		vertex[0], vertex[1], vertex[2], vertex[3],
		mouse_pos)){ }
}

// 描画
void CustomStar::Draw() {

	// ひし形を星型に並べて描画
	for (int i = 0; i < MAX_DIANMOND_NUM; ++i) {
		Lib::DrawDaiamond2D(
			"Resource/Custom/player_1_normal(仮).png",
			300, 500, 100, 100, 0);
	}
}

