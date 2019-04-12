#pragma once

#include"../Lib/Lib.h"

// ひし形の基底クラス
class DiamondBase {

public:

	DiamondBase() {}				// コンストラクタ
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画
	virtual~DiamondBase() {}		// デストラクタ

protected:

	D3DXVECTOR2 m_pos;		// 座標
	float m_width;			// 幅
	float m_height;			// 高さ
	float m_angle;			// 角度

	//int or bool strength;			// 強弱スキルの判別

private:

};

/*必要なもの

*/

