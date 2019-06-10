#include"Button.h"
#include"../../Lib/Lib.h"
#include "../../Collision/Collision.h"

//---------------------------------
//コンストラクタ
ButtonUI::ButtonUI(
	float x, float y,
	std::string tex_name,
	float rot
) :ObjectBase(x, y, rot) {

	m_tex_name = tex_name;
	Lib::Texture tex(m_tex_name.c_str());
	m_width = tex.GetSize().x;
	m_height = tex.GetSize().y;
	m_was_click = false;
	m_click_count = 0;
	m_color = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
}

//----------------------------------
// 描画処理
void ButtonUI::Draw() {

	//ボタンの描画
	Lib::DrawBox2D(
		m_tex_name.c_str(),
		m_pos.x, m_pos.y,
		m_color
	);
}

//-------------------------------
// 更新処理
void ButtonUI::Update() {

	IsHitToMouse();
}

//-------------------------------
//　クリック状態フラグを返す
 bool ButtonUI::GetClick() {

	if (m_was_click == true) {
		++m_click_count;

		if (m_click_count >= 2) {
			m_click_count = 0;
		}
		return true;
	}

	return false;
}

 //------------------------------
 //　クリック回数を返す
 const int ButtonUI::GetClickCount()const {
	 return m_click_count;
 }

//当たったかどうかの判定
void ButtonUI::IsHitToMouse() {

	// クリック処理
	m_mouse = Lib::GetMousePoint();
	
	m_was_click = Collision::IsInSquare(
		m_pos,
		m_width, m_height,
		m_mouse
	);

	// カーソルが乗っているのか
	m_on_mouse = Lib::GetPointOnDrag();

	m_was_drag = Collision::IsInSquare(
		m_pos,
		m_width, m_height,
		m_on_mouse
	);

	if (m_was_drag == true) {
		m_color = Lib::CreateColor(0.5f, 0.5f, 0.5f, 0.f);
	}
	else {
		m_color = Lib::CreateColor(1.f, 1.f, 1.f, 0.f);
	}
}