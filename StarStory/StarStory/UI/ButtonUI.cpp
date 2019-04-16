#include"../Lib/Lib.h"
#include"ButtonUI.h"

//描画
void ButtonUI::Draw() {
	//ボタンの描画
	Lib::DrawPx2D(
		"Resource/title/test_title_start.png",
		450, 800, 200, 100
	);

}

//更新
void ButtonUI::Update() {


}


//当たったかどうかの判定
void ButtonUI::Hit() {

	if (true)
	{
		is_hit = true;
	}
	else {
		is_hit = false;
	}
}