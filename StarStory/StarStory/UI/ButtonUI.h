#pragma once
#include"../StageObject/ObjectBase.h"
#include <string>

class ButtonUI : public ObjectBase {

public:

	//コンストラクタ
	ButtonUI(
		float x, float y,
		std::string tex_name="none",		
		float rot=0.f
	):ObjectBase(x, y, rot) {

		m_tex_name = tex_name;

	}

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//当たったかどうかのフラグ
	void IsHitToMouse();

	bool GetHit() {
		this->is_hit;
	}
	//is_hitのゲッター

private:

	bool is_hit;
	std::string m_tex_name;

	/*マウスオブジェクトの当たり判定を取って
	  自分のis_hitをtrueにする
	*/

	//当たったかどうかのフラグ

};

