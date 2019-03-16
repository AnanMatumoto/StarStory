﻿#include "Lib.h"

#define VERTEX_FVF (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)


//======================================
//　2D描画関連
//======================================

namespace Lib {

	//----------------------------------------
	// 左上原点ピクセルサイズ
	void DrawPx2D(
		const Texture& tex,
		float x, float y,
		float w, float h,
		DWORD col,
		float ox, float oy
	) {

		float x1 = x - w * (ox);//原点X座標
		float y1 = y - h * (oy);//原点左座標
		float x2 = x + w * (1.f - ox);//右下X座標
		float y2 = y + h * (1.f - oy);//右下ｙ座標

		Vertex vtx[4] = {
			{{x1, y1, 0.f,1.f}, col, {0.f,0.f}},
			{{x2, y1, 0.f,1.f}, col, {1.f,0.f}},
			{{x2, y2, 0.f,1.f}, col, {1.f,1.f}},
			{{x1, y2, 0.f,1.f} ,col,  {0.f,1.f}}
		};


		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}


	void DrawBox2D(
		const Texture& tex,
		float pos_x,
		float pos_y,
		float width,
		float height,
		DWORD color,
		float ox,
		float oy
	) {

		DrawPx2D(
			tex,
			pos_x, pos_y,
			tex.GetSize().x * width,
			tex.GetSize().y * height,
			color, ox, oy
		);
	}

	//-----------------------------------------------
	//座標から上向きに頂点を作る三角形
	void DrawTriangle2D(
		const Texture& tex,
		Vertex v[],
		float pos_x, float pos_y,
		float w, float h,
		DWORD color
	) {

		v[3] = {};

		float hlf_w = pos_x + w / 2;
		float hlf_h = pos_y - h;
		float width = pos_x + w;

		v[0] = { {pos_x, pos_y, 0.f,1.f},color,{0.f,0.f} };
		v[1] = { {hlf_w, hlf_h, 0.f,1.f},color,{0.5f,1.f} };
		v[2] = { {width, pos_y, 0.f,1.f},color,{1.f,1.f} };

		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, v, sizeof(Vertex));

	}
	//--------------------------------------------------
	//*********改良中**********************
	/*void RotTriangle2D(
		Vertex v[],
		float angle,
		float &px, float &py
		) {
*/
//D3DXMATRIX mtx, rot_mtx;
//int i = 0;

//行列の初期化
//D3DXMatrixIdentity(&mtx);
//D3DXMatrixIdentity(&rot_mtx);

//回転行列に角度を設定する
//D3DXMatrixRotationZ(&rot_mtx, angle);
//

//各頂点に回転を加える
//for (i = 0; i < 3; ++i) {
//	D3DXMatrixTranslation(
//		&mtx,
//		v[i].pos.x,
//		v[i].pos.y,
//		v[i].pos.z
//	);
//	mtx *= rot_mtx;

//	v[i].pos.x = mtx._41;
//	v[i].pos.y = mtx._42;
//	v[i].pos.z = mtx._43;

//}
//}



	//---------------------------------------
	//回転を行う三角形ポリゴン
	void RotTriangle2D(
		const Texture& tex,
		float angle,
		float& pos_x, float& pos_y,
		float w, float h,
		float ox, float oy,
		DWORD color
	) {
		float lft_x = ox - 0.03f;
		float lft_y = oy - 0.04f;
		float rht_x = ox + 0.03f;
		float rht_y = oy + 0.04f;


		Vertex vtx[3] = {
			{{-lft_x, -lft_y, 0.f,1.f},color,{0.f,0.f}},
			{{(1.f - ox), -oy,0.f,1.f},color,{0.5f,1.f}},
			{{(1.f - rht_x),(1.f - rht_y),0.f,1.f},color,{1.f,1.f}}
		};

		//拡縮、回転行列
		D3DXMATRIX pos_mtx, rot_mtx;
		D3DXMatrixScaling(&pos_mtx, w, h, 1.f);

		if (0 != angle) {
			D3DXMatrixRotationZ(&rot_mtx, D3DXToRadian(angle));
			pos_mtx *= rot_mtx;
		}

		//新座標
		pos_mtx._41 = pos_x;
		pos_mtx._42 = pos_y;

		//頂点バッファを行列に変換する
		D3DXVec2TransformCoordArray(
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			&pos_mtx, 3
		);

		dev->SetTexture(0, tex);
		dev->SetRenderState(D3DRS_LIGHTING, false);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			1, vtx, sizeof(Vertex));

	}

	//-------------------------------------
	//　αブレンドの設定
	void SetAlphaBlend() {
		//ブレンディングモードの設定
		dev->SetTextureStageState(
			0, D3DTSS_COLOROP,
			D3DTOP_SELECTARG1);
		dev->SetTextureStageState(
			0, D3DTSS_COLORARG1,
			D3DTA_TEXTURE);
		//αブレンドの設定
		dev->SetTextureStageState(
			0, D3DTSS_ALPHAOP,
			D3DTOP_SELECTARG1);
		dev->SetTextureStageState(
			0, D3DTSS_ALPHAARG1,
			D3DTA_TEXTURE);
		//出力したα値の反映方法を指定する
		dev->SetRenderState(
			D3DRS_ALPHABLENDENABLE,
			TRUE);
		dev->SetRenderState(
			D3DRS_SRCBLEND,
			D3DBLEND_SRCALPHA);
		dev->SetRenderState(
			D3DRS_DESTBLEND,
			D3DBLEND_INVSRCALPHA);
	}
}
