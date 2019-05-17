#include "Lib.h"
#include <unordered_map>


//============================================
//　テクスチャ設定関連
//============================================

namespace Lib {

	std::unordered_map<std::string, Texture> tex_list;

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
					//D3DCOLOR_XRGB(0, 0, 0),// アルファキーの指定（黒）
					NULL,
					&tex_info,
					nullptr,
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

}

