#pragma once

#include"../../StageObject/ObjectBase.h"
#include <string>

class ButtonUI : public ObjectBase {

public:

	//コンストラクタ
	ButtonUI(
		float x,
		float y,
		std::string tex_name = "none",
		float rot = 0.f
	);

	// 更新処理
	void Update() override;

	// 描画処理
	void Draw() override;

	//　クリック状態フラグを返す
	 bool GetClick();

	//　クリック回数を返す
	const int GetClickCount() const;

private:

	//当たったかどうかのフラグ
	void IsHitToMouse();

private:

	Vec2  m_mouse;				// マウス座標保存用変数
	Vec2  m_on_mouse;			// マウス座標保存用変数
	bool  m_was_click;		    // クリック状態を保存するフラグ
	bool  m_was_drag;
	int   m_click_count;		// クリック回数保存変数
	std::string m_tex_name;		// テクスチャ画像名
	D3DXCOLOR m_color;
};

