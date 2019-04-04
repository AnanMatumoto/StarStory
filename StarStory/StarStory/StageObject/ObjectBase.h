#pragma once

#include "../Lib/Lib.h"

//================================
// ステージオブジェクトID
//================================
enum StageObjectID {

	OBJ_TEST1,
	OBJ_CLONE1,
};


//===================================
//　ステージオブジェクト基底クラス
//===================================

/*
	ステージに置かれるオブジェクトは
	以下を継承する。

	Update　：更新処理
	Draw　　：描画処理
	Delete　：フラグを削除状態にセットする
	IsDelete：削除状態かどうかを返す

*/

class ObjectBase {
	
public:

	ObjectBase();

	virtual void Update()   = 0;
	virtual void Draw  ()   = 0;
    void Delete();
    const bool IsDelete()const;
	virtual ~ObjectBase  (){}

protected:
	Vec2 m_pos;         // 座標
	Vertex vtx[4];      // 頂点情報
	float m_width;      // 幅
	float m_height;     // 高さ
	float m_rot;        // 回転角度
	bool  is_delete;    // 削除状態を示すフラグ
};

