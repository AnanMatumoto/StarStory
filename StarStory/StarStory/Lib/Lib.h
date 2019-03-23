#include "../Common/Common.h"
#include <d3d9.h>
#include<d3dx9.h>
#include <string>

#pragma once
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#define NOMINMAX


struct Vertex
{
	D3DXVECTOR4 pos;
	DWORD		col;
	D3DXVECTOR2 uv;

};

namespace Lib {

	extern HWND hWnd;
	extern LPDIRECT3D9 d3d;
	extern LPDIRECT3DDEVICE9 dev;

	//================================================
	//　デバイス設定関連
	//================================================

	/*
	使用方法：
	　例）
		Init(WINDOW_W,WINDOW_H,"サンプル");  // 初期化

		while(ProcessMessage()){			 // メッセージループ処理
			DrawBegin(0);					 // 描画処理開始
			DrawEnd();						 // 描画処理終了
		}
		AppEnd();							 // アプリ終了処理
	*/
	LRESULT CALLBACK WinProc(
		HWND hwnd, UINT msg,
		WPARAM wp, LPARAM lp
	);

	void Init(
		int w, int h,
		const char* title
	);
	
	void SetWinDevice(
		HINSTANCE h_instance,
		const char* class_name,
		WNDCLASSEX *wc
	);

	void MakeWindow(
		HINSTANCE h_instance,
		const char* class_name,
		const char* title,
		int w, int h
	);

	void InitD3D9();
	void AppEnd();
	bool ProcessMessage();
	void DrawBegin(DWORD back_color = 0xe0e0ff
	);
	void DrawEnd();

	//================================================
	// テクスチャ読み込み関連
	//================================================
	class Texture {

	public:

		/*
		使用方法：
		　<コンストラクタ>
		  例）
			・Texture tex("画像名");
			・Texture("画像名");
			・Texture tex = "画像名";

		　< LPDIRECTTEXTURE9をテクスチャクラスに代用する場合 >
		  例）
			LPDIRECTTEXTURE9 texture;
			Texutre tex("画像名");
			texture = tex;

		  < サイズ、名前を取得する場合 >
		  例）※リブ内での操作にしか有効ではないので注意
			 float size = tex.GetSize();
			 const char* name = tex.GetName();
		*/

		// コンストラクタ
		Texture() :tex(nullptr), size(0.f, 0.f) {}
		Texture(const char* file_name);
		Texture(const Texture& t);

		Texture& operator=(const Texture& _tex);
		operator LPDIRECT3DTEXTURE9()const {
			return tex;
		};
		const D3DXVECTOR2& GetSize() const {
			return size;
		};
		const std::string& GetName() const {
			return name;
		};
		~Texture();
	private:

		LPDIRECT3DTEXTURE9 tex;
		D3DXVECTOR2 size;
		std::string name;

	};

	//=========================================
	//　キー・マウス処理関連
	//=========================================

	/*
	使用方法：
		例）

		while(true){

		  KeyUpdate();	     // 毎フレームキーの入力情報を確認する

		　 KeyOn('A'); 	     //  「A」キー押下
		   KeyPress('S')      // 「S」キーを押した瞬間
		   KeyOff('VK_SPACE');// スペースキーを離した瞬間
		}
	*/

	void KeyUpdate();
	bool KeyOn(int nVirtKey);
	bool KeyPress(int nVirtKey);
	bool KeyOff(int nVirtKey);
	POINT GetMousePoint(float* x, float* y);
	//============================================
	// 2D描画処理
	//============================================

	/*
		ピクセルサイズ描画関数（基本は左上原点）

		第1　：指定するテクスチャ
		第2,3：描画したい座標
		第4,5：幅高を【ピクセルサイズ】で指定する
		第6　：色相
		第7,8：オフセット値(0.5で中心座標)

	仕様方法：
	　Lib::DrawPx(
		"Hoge.png"
		0, 0,
		128, 256,
		0x00ffffff,
		0.5, 0,5
	  );

	*/
	void DrawPx2D(
		const Texture& tex,
		float pos_x,
		float pos_y,
		float width = 1.f,
		float height = 1.f,
		DWORD color = 0x00ffffff,
		float ox = 0.f,
		float oy = 0.f
	);

	/*
		セルサイズ指定描画関数（基本は左上原点）
	
		内容はDrawPx2Dと同じ
		第4,5引数には【倍率】を直接渡す
	*/
	void DrawBox2D(
		const Texture& tex,
		float pos_x,
		float pos_y,
		float width = 1.f,
		float height = 1.f,
		DWORD color = 0x00ffffff,
		float ox = 0.f,
		float oy = 0.f
	);

	/*
		三角形描画関数（ピクセルサイズ）

		◆注意
		第2：引数に頂点を渡すことで描画可能
		（内部で頂点配列は作られない）
		
	*/
	void DrawTriangle2D(
		const Texture& tex,
		Vertex v[],
		float pos_x, float pos_y,
		float width=128, float height=128,
		DWORD color = 0x00ffffff
	);

	/*
		三角形回転描画関数（ピクセルサイズ）

		第1　：指定するテクスチャ
		第2　：回転角度（内部でラジアン変換有り）
		第3.4：自身の座標
		第5.6：幅高（ピクセルサイズで指定）
		第7.8：基準値からの距離（0.5以下で左寄り）
		第9	 ：色相

	◆使用方法：
		Lib::RotTriangle2D(
			"Player.jpg",
			c,
			x, y,
			128,128
			);
	*/
	void RotTriangle2D(
		const Texture& tex,
		float angle,
		float &px, float &py,
		float w, float h,
		float ox=0.5f, float oy=0.5f,
		DWORD color	= 0x00ffffff
	);

	/*
		回転付菱形描画関数

		第1　：指定するテクスチャ
		第2,3：XY座標
		第4,5：対角線（幅高）
		第6  ：回転角度
		第7　：色相
		第8,9：オフセット値（デフォルト中心座標）

		（※オフセット値0.5で中心を軸に回転）
	*/
	void DrawDaiamond2D(
		const Texture& tex,
		float pos_x, float pos_y,
		float h, float w,
		float angle,
		DWORD color = 0x00ffffff,
		float ox = 0.5f, float oy = 0.5f
	);



	//αブレンドの設定（外部での使用はできない）
	void SetAlphaBlend();
};

