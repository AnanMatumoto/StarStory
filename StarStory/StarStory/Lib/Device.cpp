#include "Lib.h"

//================================================
//　デバイス設定関連
//================================================

namespace {

	struct t_Point {
		POINT start = { 0,0 };//クリック時以外の座標を取得
		POINT end = { 0,0 };  //クリック時の座標を取得
	}pt;

	bool is_drag  = false; //ドラッグ判定変数
	bool is_click = false;//ダブルクリック判定変数
};

namespace Lib {

	HWND hWnd = nullptr;//ウィンドウハンドル

	LPDIRECT3D9 d3d = nullptr;
	LPDIRECT3DDEVICE9 dev = nullptr;

	//------------------------------------------------
	// ウィンドウプロシージャ
	LRESULT CALLBACK WinProc(
		HWND hwnd, UINT msg,
		WPARAM wp, LPARAM lp
	) {
		//unsigned short int x = 0, y = 0;
		int timer = 0;

		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		/*
		ダブルクリックが必要になったら
		case WM_LBUTTONDBLCLK:

			if (!is_click) {
				is_click = 1;
			}
		*/
			// マウスボタンクリック開始時
		case WM_LBUTTONDOWN:  // 左

			if (++timer >= 1.f) {
				is_click = true;
				pt.end.x = pt.start.x;
				pt.end.y = pt.start.y;
			}

			break;

		case WM_RBUTTONDOWN:  // 右
		case WM_MBUTTONDOWN:  // 中

			// マウスボタンクリック終了時
		case WM_LBUTTONUP:
			is_click = false;
			pt.end = { 0,0 };
			break;

			// マウスカーソル(表示or非表示)
		case WM_CREATE:
			ShowCursor(TRUE);
			break;

		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
		case WM_MOUSEMOVE:

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

		HINSTANCE h_instance = GetModuleHandle(nullptr);
		const char* class_name = "StarStory";
		WNDCLASSEX wc = {};

		//ウィンドウデバイスの設定
		SetWinDevice(
			h_instance,
			class_name, &wc
		);

		//デバイス登録
		if (RegisterClassEx(&wc) == 0) {
			ErrMsg("ウィンドウクラスの登録に失敗");
			return;
		}
		//ウィンドウ生成
		MakeWindow(
			h_instance,
			class_name, title,
			w, h
		);

		//作成失敗時
		if (hWnd == nullptr) {
			ErrMsg("ウィンドウの作成に失敗しました");
			return;
		}
		ShowWindow(hWnd, SW_SHOW);

		//D3D9初期化
		InitD3D9();
	}

	//----------------------------------------------------
	//ウィンドウデバイスの初期化
	void SetWinDevice(
		HINSTANCE h_instance,
		const char* class_name,
		WNDCLASSEX *wc
	) {

		//デバイスの設定
		wc->cbSize = sizeof(WNDCLASSEX);
		wc->style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc->lpfnWndProc = WinProc;
		wc->cbClsExtra = 0;//構造体に割り当てられる補助バイト数,予備メモリ
		wc->cbWndExtra = 0;//インスタンスに割り当てられる補助バイト数,メモリサイズ
		wc->hInstance = h_instance;
		wc->hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc->hCursor = LoadCursor(nullptr, IDI_APPLICATION);
		wc->hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		wc->lpszMenuName = MAKEINTRESOURCE(nullptr);
		wc->lpszClassName = class_name;
		wc->hIconSm = nullptr;
	}

	//-------------------------------------------------
	//ウィンドウ生成
	void MakeWindow(
		HINSTANCE h_instance,
		const char* class_name,
		const char* title,
		int w, int h
	) {

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
			nullptr,
			nullptr,
			h_instance,
			nullptr
		);
	}

	//-------------------------------------------------
	//DirectX９デバイスの初期化処理
	void InitD3D9() {

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
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
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
			0, nullptr,
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
		dev->Present(nullptr, nullptr, nullptr, nullptr);
	}

	//-----------------------------------------
	// マウス入力処理
	Vec2 GetMousePoint() {

		Vec2 vec(((float)pt.end.x), ((float)pt.end.y));
		return vec;
	}

	//----------------------------------------
	//　マウスの位置を取得する
	Vec2 GetPointOnDrag() {
		Vec2 vec(((float)pt.start.x), ((float)pt.start.y));
		return vec;
	}
	//------------------------------------
	//　マウスの左クリックの判定を返す
	const bool HasClickOnMouse() {
		if (is_click ==true) {
			return true;
		}
		return false;
	}
}

