#include"Button.h"
#include"../Lib/Lib.h"
#include "../Collision/Collision.h"

//------------------------------
// 描画処理
void ButtonUI::Draw() {
	//ボタンの描画
	Lib::DrawBox2D(
		m_tex_name.c_str(),
		m_pos.x, m_pos.y
	);

}

//-------------------------------
// 更新処理
void ButtonUI::Update() {

	IsHitToMouse();
}

//-------------------------------
//　クリック状態フラグを返す
const bool ButtonUI::GetClick()const {
	if (was_click == true) {
		return true;
	}
	return false;
}

//当たったかどうかの判定
void ButtonUI::IsHitToMouse() {

	m_mouse.x = Lib::GetMousePoint().x;
	m_mouse.y = Lib::GetMousePoint().y;

	was_click = Collision::IsInSquare(
		m_pos,
		m_width, m_height,
		m_mouse
	);


}