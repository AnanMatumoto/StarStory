#include"../Lib/Lib.h"
#include"Button.h"

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




}

//-------------------------------
//　クリック状態フラグを返す
const bool ButtonUI::GetClick()const {
	return was_click;
}

//当たったかどうかの判定
void ButtonUI::IsHitToMouse() {


}