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

		m_tex_name = tex_name;
		Lib::Texture tex(m_tex_name.c_str());
		m_width = tex.GetSize().x;
		m_height = tex.GetSize().y;
		was_click = false;
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

	Vec2  m_mouse;			//マウス座標保存用変数
	bool was_click;		    // クリック状態を保存するフラグ
	std::string m_tex_name;	// テクスチャ画像名
	


	/*マウスオブジェクトの当たり判定を取って
	  自分のis_hitをtrueにする
	*/

	//当たったかどうかのフラグ

};

