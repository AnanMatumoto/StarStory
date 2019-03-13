#pragma once
#include "Lib.h"
#include "Common.h"
#include <unordered_map>


#define VERTEX_FVF (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)


namespace {

	void ErrMsg(const char* _msg) {
		MessageBox(0, _msg, NULL, MB_OK);
		PostQuitMessage(0);
	}
	struct t_Point {
		POINT start = { 0,0 };//クリック時以外の座標を取得
		POINT end = { 0,0 };  //クリック時の座標を取得
	}pt;

	BYTE key[2][256];
	int is_drag = 0; //ドラッグ判定変数
	int is_click = 0;//ダブルクリック判定変数
};

namespace Lib {


	HWND hWnd = NULL;//ウィンドウハンドル
	std::unordered_map<std::string, Texture> tex_list;
	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 dev = NULL;


	//================================================
	//　デバイス設定関連
	//================================================
	//------------------------------------------------
	// ウィンドウプロシージャ
	LRESULT CALLBACK WinProc(
		HWND hwnd, UINT msg,
		WPARAM wp, LPARAM lp
	) {
		//unsigned short int x = 0, y = 0;

		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_LBUTTONDBLCLK:

			if (!is_click) {
				is_click = 1;
			}

			// マウスボタンクリック開始時
		case WM_LBUTTONDOWN:  // 左
			
			if (is_click) {
				pt.start.x = LOWORD(lp);
				pt.start.y = HIWORD(lp);

				if (!is_drag) {
					pt.end = pt.start;
					is_drag = 1;
				}
			}

			break;

		case WM_RBUTTONDOWN:  // 右
		case WM_MBUTTONDOWN:  // 中
			SetCapture(hwnd);
			break;

			// マウスボタンクリック終了時
		case WM_LBUTTONUP:
			is_drag = 0;
			is_click = 0;
			break;

		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
			ReleaseCapture();
			break;

		case WM_MOUSEMOVE:
			// フラグが１である
			if (is_drag) {
				pt.end.x = LOWORD(lp);
				pt.end.y = HIWORD(lp);
				return 0;
			}
			// 更新する座標を取得
			pt.start.x = LOWORD(lp);
			pt.start.y = HIWORD(lp);
			break;
		case WM_SYSKEYDOWN: // システムキー押下開始時
		case WM_SYSKEYUP:   // システムキー終了時
			return 0;
		}

		return DefWindowProc(hwnd, msg, wp, lp);

	}
	//-------------------------------------------------
	//　ウィンドウ初期化からDirectX9デバイス設定まで
	void Init(int w, int h, const char* title) {

		HINSTANCE h_instance = GetModuleHandle(NULL);
		const char* class_name = "TEST";

		//デバイスの設定
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc.lpfnWndProc = WinProc;
		wc.cbClsExtra = 0;//構造体に割り当てられる補助バイト数,予備メモリ
		wc.cbWndExtra = 0;//インスタンスに割り当てられる補助バイト数,メモリサイズ
		wc.hInstance = h_instance;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDI_APPLICATION);
		wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		wc.lpszMenuName = MAKEINTRESOURCE(NULL);
		wc.lpszClassName = class_name;
		wc.hIconSm = NULL;

		//デバイス登録
		if (RegisterClassEx(&wc) == 0) {
			ErrMsg("ウィンドウクラスの登録に失敗");
			return;
		}

		DWORD dw_exstyle = WS_EX_LEFT;
		DWORD dw_style = WS_OVERLAPPEDWINDOW;

		RECT r = { 0, 0, w, h };
		AdjustWindowRectEx(&r, dw_style, FALSE, dw_exstyle);

		hWnd = CreateWindowEx(
			dw_exstyle,
			class_name,
			title,
			dw_style,
			CW_USEDEFAULT,//起動時の位置と幅をウィンドウズに委ねる
			CW_USEDEFAULT,
			r.right - r.left,
			r.bottom - r.top,
			NULL,
			NULL,
			h_instance,
			NULL
		);
		//作成失敗時
		if (hWnd == NULL) {
			ErrMsg("ウィンドウの作成に失敗しました");
			return;
		}
		ShowWindow(hWnd, SW_SHOW);

		d3d = Direct3DCreate9(D3D_SDK_VERSION);
		D3DPRESENT_PARAMETERS pp = {};
		{
			//　バッファの設定
			pp.BackBufferWidth = 0;
			pp.BackBufferHeight = 0;
			pp.BackBufferFormat = D3DFMT_A8R8G8B8;//ARGB 8ビット
			pp.BackBufferCount = 1;

			//　マルチサンプル設定
			pp.MultiSampleType = D3DMULTISAMPLE_4_SAMPLES;
			pp.MultiSampleQuality = 0;

			pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			pp.hDeviceWindow = hWnd;
			pp.Windowed = TRUE;  // フルスクリーンの場合はFALSE
			pp.EnableAutoDepthStencil = TRUE; // Zバッファの使用を有効にする
			pp.AutoDepthStencilFormat = D3DFMT_D24S8;
			pp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
			pp.FullScreen_RefreshRateInHz = 0;
			pp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
		}

		//DirectXデバイス生成
		d3d->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&pp,
			&dev
		);
	}

	//------------------------------------------
	//　アプリケーション終了時の処理
	void AppEnd() {
		if (dev) {
			dev->Release();
			dev = nullptr;
		}
		if (d3d) {
			d3d->Release();
			d3d = nullptr;
		}
	}

	//------------------------------------------
	//　メッセージ処理
	bool ProcessMessage() {
		MSG msg;

		//　メッセージが０では無い間
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT) {
				return false;
			}
		}
		return true;
	}

	//-------------------------------------------
	//描画開始処理
	void DrawBegin(DWORD back_color) {
		dev->Clear(
			0, NULL,
			D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
			back_color | 0xff000000,
			1.0f, 0
		);
		dev->BeginScene();
	}

	//-------------------------------------------
	//描画終了処理
	void DrawEnd() {
		dev->EndScene();
		dev->Present(NULL, NULL, NULL, NULL);
	}

	//============================================
	//　テクスチャ設定関連
	//============================================

	//-------------------------------------------------
	//　コンストラクタ
	Texture::Texture(const char* file_name) :Texture() {

		if (file_name == nullptr || *file_name == '\0') {
			ErrMsg("画像名を指定してください");
			return;
		}

		//　画像登録処理
		name = file_name;
		auto itr = tex_list.find(file_name);
		if (itr != tex_list.end()) {
			//　すでにリスト内に登録されている場合
			tex = itr->second.tex;
			if (tex) {
				tex->AddRef();
			}
			size = itr->second.size;
		}
		else {
			//　登録がされていない場合
			D3DXIMAGE_INFO tex_info;
			if (SUCCEEDED(D3DXGetImageInfoFromFile(file_name, &tex_info))) {
				size.x = (float)tex_info.Width;
				size.y = (float)tex_info.Height;
				D3DXCreateTextureFromFileEx(
					dev,
					file_name,
					0, 0, 0, 0,   // 画像ファイルから取得
					D3DFMT_A8R8G8B8,
					D3DPOOL_MANAGED,
					D3DX_FILTER_LINEAR,	   // フィルタリングの指定（中間色を指定する）
					D3DX_FILTER_LINEAR,
					D3DCOLOR_XRGB(0, 0, 0),// アルファキーの指定（黒）
					&tex_info,
					NULL,
					&tex
				);
				tex_list.emplace(file_name, *this);
			}
		}
	}

	//-----------------------------------------
	//　コンストラクタ（メンバイニシャライザ）
	Texture::Texture(const Texture& _tex) :
		tex(_tex.tex),
		size(_tex.size),
		name(_tex.name)
	{
		if (tex) {
			//参照カウンタインクリメント
			tex->AddRef();
		}
	}

	//-------------------------------------------
	//　コンストラクタ（代入演算子オーバーロード）
	Texture& Texture::operator=(const Texture& _tex) {

		name = _tex.name;
		if (tex) {
			tex->Release();
		}
		tex = _tex.tex;
		if (tex) {
			tex->AddRef();
		}
		size = _tex.size;
		return *this;
	}

	//-----------------------------------------
	//  デストラクタ
	Texture::~Texture() {
		if (tex) {
			//参照カウンタデクリメント
			tex->Release();
		}
	}

	//==========================================
	// キー・マウス関連
	//==========================================
	 bool KeyTest(const BYTE k) {
		return ((k & 0x80) != 0);
	}
	//------------------------------------------
	// 毎フレーム処理
	void KeyUpdate() {
		memcpy(key[1], key[0], sizeof(*key));
		GetKeyboardState(key[0]);
	}
	//------------------------------------------
	//　キー押下処理
	bool KeyOn(int nVirtKey) {
		return KeyTest(key[0][nVirtKey]);
	}
	//------------------------------------------
	//　キーを押した瞬間の処理
	bool KeyPress(int nVirtKey) {
		return KeyTest(key[0][nVirtKey]) && !KeyTest(key[1][nVirtKey]);
	}
	//-----------------------------------------
	// キー解放処理
	bool KeyOff(int nVirtKey) {
		return !KeyTest(key[0][nVirtKey]) && KeyTest(key[1][nVirtKey]);
	}

	//-----------------------------------------
	// マウス入力処理
	POINT GetPoint(float* x, float *y) {

		*x = pt.end.x;
		*y = pt.end.y;

		return pt.end;
	}

	//======================================
	//　2D描画関連
	//======================================

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
		
		v[0] = {{pos_x, pos_y, 0.f,1.f},color,{0.f,0.f}};
		v[1] = {{hlf_w, hlf_h, 0.f,1.f},color,{0.5f,1.f}};
		v[2] = {{width, pos_y, 0.f,1.f},color,{1.f,1.f}};

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
		float lft_y=  oy - 0.04f;
		float rht_x = ox + 0.03f;
		float rht_y = oy + 0.04f;

		
		Vertex vtx[3] = {
			{{-lft_x, -lft_y, 0.f,1.f},color,{0.f,0.f}},
			{{(1.f - ox), -oy,0.f,1.f},color,{0.5f,1.f}},
			{{(1.f-rht_x),(1.f - rht_y),0.f,1.f},color,{1.f,1.f}}
		};

		//拡縮、回転行列
		D3DXMATRIX pos_mtx, rot_mtx;
		D3DXMatrixScaling(&pos_mtx, w, h, 1.f);

		if (0 != angle) {
			D3DXMatrixRotationZ(&rot_mtx,D3DXToRadian(angle));
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

	


};

