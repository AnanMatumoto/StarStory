#include "Lib.h"

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
		float depth,
		DWORD col,
		float ox, float oy
	) {

		float x1 = x - w * (ox);//原点X座標
		float y1 = y - h * (oy);//原点左座標
		float x2 = x + w * (1.f - ox);//右下X座標
		float y2 = y + h * (1.f - oy);//右下ｙ座標

		Vertex vtx[4] = {
			{{x1, y1, depth,1.f}, col, {0.f,0.f}},
			{{x2, y1, depth,1.f}, col, {1.f,0.f}},
			{{x2, y2, depth,1.f}, col, {1.f,1.f}},
			{{x1, y2, depth,1.f} ,col,  {0.f,1.f}}
		};


		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}

	//----------------------------------------
	//色相指定型オーバーロード
	void DrawPx2D(
		const Texture& tex,
		float x, float y,
		D3DXCOLOR color,
		float w, float h,
		float depth,
		float ox, float oy
	) {

		float x1 = x - w * (ox);//原点X座標
		float y1 = y - h * (oy);//原点左座標
		float x2 = x + w * (1.f - ox);//右下X座標
		float y2 = y + h * (1.f - oy);//右下ｙ座標

		Vertex vtx[4] = {
			{{x1, y1, depth,1.f}, color, {0.f,0.f}},
			{{x2, y1, depth,1.f}, color, {1.f,0.f}},
			{{x2, y2, depth,1.f}, color, {1.f,1.f}},
			{{x1, y2, depth,1.f} ,color,  {0.f,1.f}}
		};
		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		SetAlphaBlend();
		SetColorBlend();
		dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));
	}


	//----------------------------------------
	//四角形描画関数
	void DrawBox2D(
		const Texture& tex,
		float pos_x,
		float pos_y,
		float width,
		float height,
		float depth,
		DWORD color,
		float ox,
		float oy
	) {

		DrawPx2D(
			tex,
			pos_x, pos_y,
			tex.GetSize().x * width,
			tex.GetSize().y * height,
			depth,
			color, ox, oy
		);
	}

	//----------------------------------------
	//色相指定型オーバーロード
	void DrawBox2D(
		const Texture& tex,
		float pos_x, float pos_y,
		D3DXCOLOR color,
		float w, float h,
		float depth,
		float ox, float oy 
	){
		DrawPx2D(
			tex,
			pos_x, pos_y,
			color,
			tex.GetSize().x * w,
			tex.GetSize().y * h,
			depth,
			ox, oy
		);

	}

	//-----------------------------------------------
	// 四角形描画関数
	void DrawBox2D(
		const Texture& tex,
		Vertex v[4]
	) {
		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2,
			v,
			sizeof(Vertex));
	}
	//-----------------------------------------------
	// α指定付板ポリゴン
	void DrawBoxAlpha(
		const Texture& tex,
		float pos_x,
		float pos_y,
		D3DXCOLOR color,
		float width,
		float height,
		float ox, float oy

	) {
		D3DXCOLOR col;
		col.r = color.r;
		col.g = color.g;
		col.b = color.b;
		col.a = color.a;

		float x1 = pos_x - width * ox;
		float y1 = pos_y - height * oy;
		float x2 = pos_x + width * (1.f - ox);
		float y2 = pos_y + height * (1.f - oy);
		Vertex vtx[4] = {
			{{x1, y1, 0.f,1.f}, col, {0.f,0.f}},
			{{x2, y1, 0.f,1.f}, col, {1.f,0.f}},
			{{x2, y2, 0.f,1.f}, col, {1.f,1.f}},
			{{x1, y2, 0.f,1.f} ,col, {0.f,1.f}}
		};
		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		SetAlphaBlend();
		dev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtx, sizeof(Vertex));

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

	//---------------------------------------
	//回転付菱形描画関数
	void DrawDaiamond2D(
		const Texture& tex,
		float pos_x, float pos_y,
		float h, float w,
		float angle,
		DWORD color,
		float ox, float oy
	) {
		Vertex vtx[4] = {
			{{-ox, (0.5f - oy), 0.f,1.f},color,{0.f,0.5f}},
			{{(0.5f - ox),-oy,0.f,1.f},color,{0.5f,1.f}},
			{{(1.f - ox),(0.5f - oy),0.f,1.f},color,{1.f,0.5f}},
			{{(0.5f - ox),(1.f - oy),0.f,1.f},color,{0.5f, 0.f}}
		};

		D3DXMATRIX mtx;
		D3DXMatrixScaling(&mtx, w, h, 1.f);

		if (angle != 0) {
			D3DXMATRIX rot_mtx;
			D3DXMatrixRotationZ(&rot_mtx, angle);
			mtx *= rot_mtx;
		}
		mtx._41 = pos_x;
		mtx._42 = pos_y;

		D3DXVec2TransformCoordArray(
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			&mtx, 4
		);

		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2, vtx,
			sizeof(Vertex));
	}

	//---------------------------------------
    //(複数)回転付菱形描画関数
	void DrawDaiamonds2D(
		const Texture& tex,
		float pos_x[], float pos_y[],
		float obj_num,
		float h, float w,
		float angle,
		DWORD color,
		float ox, float oy
	) {


		Vertex vtx[4] = {
			{{-ox, (0.5f - oy), 0.5f,1.f},color,{0.f,0.5f}},
			{{(0.5f - ox),-oy,0.5f,1.f},color,{0.5f,1.f}},
			{{(1.f - ox),(0.5f - oy),0.f,1.f},color,{1.f,0.5f}},
			{{(0.5f - ox),(1.f - oy),0.f,1.f},color,{0.5f, 0.f}}
		};

		D3DXMATRIX mtx;
		D3DXMatrixScaling(&mtx, w, h, 1.f);

		if (angle != 0) {
			D3DXMATRIX rot_mtx;
			D3DXMatrixRotationZ(&rot_mtx, angle);
			mtx *= rot_mtx;
		}

		for (int i = 0; i < obj_num; ++i) {
			mtx._41 = pos_x[i];
			mtx._42 = pos_y[i];
		}

		D3DXVec2TransformCoordArray(
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			(D3DXVECTOR2*)vtx, sizeof(Vertex),
			&mtx, 4
		);

		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2, vtx,
			sizeof(Vertex));
	}

	//-------------------------------------
	// 菱形描画関数オーバーロード
	void DrawDiamond2D(
		const Texture& tex,
		Vertex vtx_[4]
	) {

		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2,
			vtx_,
			sizeof(Vertex));
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

	//--------------------------------------
	//　カラーブレンドの設定
	void SetColorBlend() {

		dev->SetTextureStageState(
			0, D3DTSS_COLOROP,
			D3DTOP_MODULATE);
		dev->SetTextureStageState(
			0, D3DTSS_COLORARG1,
			D3DTA_TEXTURE);
		dev->SetTextureStageState(
			0, D3DTSS_COLORARG2,
			D3DTA_DIFFUSE);
	}

	//----------------------------------
	// UVアニメーション関数
	void AnimationUV(
		const Texture& tex,
		int   length,
		int   slice_num,
		float depth,
		float pos_x, float pos_y,
		float h, float w,
		float ox, float oy,
		DWORD color
	) {
		float x1 = pos_x - w * (ox);
		float y1 = pos_y - h * (oy);
		float x2 = pos_x + w * (1.f - ox);
		float y2 = pos_y + h * (1.f - oy);

		if (length <= 0 || slice_num <=0) {
			return;
		}
		
		//一枚当たりの画像UVサイズ
		float slice_size = 1.0 / length;

		float uv_x1 =slice_size*slice_num;
		float uv_y1 = 0.f;
		float uv_x2 = uv_x1 + slice_size;
		float uv_y2 = 1.f;

		Vertex vtx[4] = {
			{{x1,y1,depth,1.f},color,{uv_x1,uv_y1}},
			{{x2,y1,depth,1.f},color,{uv_x2,uv_y1}},
			{{x2,y2,depth,1.f},color,{uv_x2,uv_y2}},
			{{x1,y2,depth,1.f},color,{uv_x1,uv_y2}}
		};

		dev->SetTexture(0, tex);
		dev->SetFVF(VERTEX_FVF);
		SetAlphaBlend();
		SetColorBlend();
		dev->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2, vtx,
			sizeof(Vertex));
	}

	//--------------------------------
	//　UVアニメーション（オーバーロード）
	void AnimationUV(
		AnimationParameter& param,
		float depth,
		float width, float height
	) {
		AnimationUV(
			param.name.c_str(),
			param.length,
			param.speed,
			depth,
			param.ofset.x,
			param.ofset.y,
			width, height
		);

	}
}

