#pragma once

#include "../Lib/Lib.h"


//===================================
//　ステージオブジェクト基底クラス
//===================================

class ObjectBase {
	
public:

	ObjectBase(float x, float y, float rotate = 0.f) : m_pos(x, y),m_rot(rotate) {

		m_width = 0;
		m_height = 0;
		m_is_delete = false;

		memset(m_vtx, 0, sizeof(m_vtx));

	}
	virtual ~ObjectBase() {}

	//　更新処理
	virtual void Update()   = 0;
	
	//　描画処理
	virtual void Draw  ()   = 0;
	
	/*
	頂点情報をセットする
	引数：
	　　color(頂点カラー)
	*/
	virtual void SetVertex(DWORD color = 0x00ffffff) {}
	
	//　削除フラグをセットする
	void Delete();
	
	//　削除状態かどうかを返す
    const bool IsDelete()const;

	//　X座標ゲッター
	const float GetX()const;
	
	//　Y座標ゲッター
	const float GetY()const;

	//  回転角度ゲッター
	const float GetRot()const;

	/*
	頂点情報ゲッター(指定した頂点情報を取得）
	引数：
	　　prim_num(頂点の番号)
	*/const Vertex GetVertex(int prim_num)const;

protected:
	
	/*
	矩形用ローカル座標変換
	引数：
	　　vtx  (頂点座標)
	  　width(オブジェクトの幅)
	    height(オブジェクトの高さ)
	*/
	void BoxLocalTransform(
		Vertex vtx[4],
		float width,
		float height
	);

	/*
	菱形用ローカル座標変換
	引数：
	　　vtx  (頂点座標)
	  　width(オブジェクトの幅)
	    height(オブジェクトの高さ)
	*/
	void DiamondLocalTransform(
		Vertex vtx[4],
		float width,
		float height
	);

	/*
	オブジェクトの上の辺と当たったかを返す
	引数：
	　point(星のとある頂点)
	  boj  (マップオブジェクト)
	*/
	bool IsHitToUpper(Vec2 point, ObjectBase* obj);

protected:
	Vec2 m_pos;				 // 座標
	Vertex m_vtx[4];		 // 頂点情報
	float m_width;			 // 幅
	float m_height;			 // 高さ
	std::string m_tex_name;  // 画像名
	float m_rot;			 // 回転角度
	bool  m_is_delete;		 // 削除状態を示すフラグ
};

