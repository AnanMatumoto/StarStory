#pragma once

#include"../StageObject/ObjectBase.h"
#include <string>

class ButtonUI : public ObjectBase {

public:

	//コンストラクタ
	ButtonUI(
		float x, float y,
		std::string tex_name = "none",
		float rot = 0.f
	) :ObjectBase(x, y, rot) {

		Lib::Texture tex;
		m_tex_name = tex_name;
		m_width = tex.GetSize().x;
		m_height = tex.GetSize().y;
	}

	// 更新処理
	void Update() override;

	//描画処理
	void Draw() override;

	//　クリック状態フラグを返す
	const bool GetClick()const;

private:

	//当たったかどうかのフラグ
	void IsHitToMouse();

private:
	bool was_click;				// クリック状態を保存するフラグ
	std::string m_tex_name;		// テクスチャ画像名

	/*マウスオブジェクトの当たり判定を取って
	  自分のis_hitをtrueにする
	*/

	//当たったかどうかのフラグ

};

