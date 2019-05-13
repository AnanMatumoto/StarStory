#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar()
	: m_diamond_part (TOP) {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		m_diamond_base.push_back(new Diamond(m_diamond_part));

		m_diamond_part = static_cast<DiamondPart>(m_diamond_part + 1);
	}
}

// デストラクタ
CustomStar::~CustomStar() {

	for (auto x : m_diamond_base) {

		delete x;
		x = nullptr;
	}
}

// 更新
void CustomStar::Update() {

	for (auto x : m_diamond_base) {

		x->Update();
	}
}

// 描画
void CustomStar::Draw() {

	for (auto x : m_diamond_base) {

		x->Draw();
	}
}

