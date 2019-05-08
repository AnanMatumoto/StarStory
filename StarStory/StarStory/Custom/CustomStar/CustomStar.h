﻿#pragma once

#include"../DiamondBase/DiamondBase.h"
#include"../Diamond/Diamond.h"

// カスタムシーンの星(ひし形のマネージャー)
class CustomStar {

public:

	CustomStar();		// コンストラクタ

	~CustomStar();		// デストラクタ

	void Reset();		// リセット

	void Update();		// 更新

	void Draw();		// 描画

private:

	DiamondBase* m_diamond_base[MAX_DIAMOND_NUM];		// ひし形の実体化

	/*----enum----*/
	DiamondPart m_diamond_part;
	/*----enum----*/
};