#include"CustomStar.h"

// コンストラクタ
CustomStar::CustomStar() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		m_diamond_base[i] = new Diamond(m_diamond_part);

		m_diamond_part = static_cast<DiamondPart>(m_diamond_part + 1);
	}
}

// デストラクタ
CustomStar::~CustomStar() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		delete m_diamond_base[i];
		m_diamond_base[i] = nullptr;
	}
}

// 更新
void CustomStar::Update() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		m_diamond_base[i]->Update();
	}
}

// 描画
void CustomStar::Draw() {

	for (int i = 0; i < MAX_DIAMOND_NUM; ++i) {

		m_diamond_base[i]->Draw();
	}
}

