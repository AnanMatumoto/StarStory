#pragma once

#include"../Lib/Lib.h"

// ひし形の基底クラス
class DiamondBase {

public:

	DiamondBase() {}				// コンストラクタ
	virtual void Update() = 0;		// 更新
	virtual void Draw() = 0;		// 描画
	virtual~DiamondBase() = 0;		// デストラクタ

protected:

	D3DXVECTOR2 m_pos;		// 座標
	D3DXVECTOR2 m_uv;		// 幅と高さ
	float m_angle;			// 角度

	bool m_strength;			// 強弱スキルの判別(名前考え中)

private:

};

/*必要なもの

*/

