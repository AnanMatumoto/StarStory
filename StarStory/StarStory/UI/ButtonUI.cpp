#include"../Lib/Lib.h"
#include"ButtonUI.h"


//描画
void ButtonUI::Draw() {
	//ボタンの描画
	Lib::DrawBox2D(
	m_tex_name.c_str(),
	m_pos.x, m_pos.y
	);

}

//更新
void ButtonUI::Update() {


}


//当たったかどうかの判定
void ButtonUI::IsHitToMouse() {


}