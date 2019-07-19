#include"CustomObjectManager.h"

#include <fstream>

/*----public----*/
/*----コンストラクタ----*/
CustomObjectManager::CustomObjectManager() :
	m_diamond_part(Diamond::TOP_PART),
	m_skill_table_object_id(SkillTable::CUSTOM_NUM){

	// オブジェクト生成
	for (int i = 0; i < Diamond::MAX_DIAMOND_PART_NUM; ++i) {

		std::string dat = "./Resource/skill_data_0";
		dat += std::to_string(i + 1);
		dat += ".dat";

		// 星生成
		m_diamond_list.push_back(new Diamond(m_diamond_part,dat));
		// スキル表生成
		m_skill_table.push_back(new SkillTable(m_diamond_part, dat));

		m_diamond_part = static_cast<Diamond::DiamondPart>(m_diamond_part + 1);
	}
}
/*----コンストラクタ----*/

/*----更新----*/
void CustomObjectManager::Update() {
	// ひし形の更新
	for (auto diamod : m_diamond_list) {
		diamod->Update();
	}
	// スキルテーブルの更新
	for (auto skill_table : m_skill_table) {
		skill_table->Update();
	}
}
/*----更新----*/

/*----描画----*/
void CustomObjectManager::Draw() {
	// ひし形の描画
	for (auto diamond : m_diamond_list) {

		diamond->Draw();
	}
	// スキルテーブルの描画
	for (auto skill_table : m_skill_table) {

		skill_table->Draw();
	}
}
/*----描画----*/

/*----デストラクタ----*/
CustomObjectManager::~CustomObjectManager() {

	// ひし形のスキル情報をバイナリデータに出力
	for (int i = 0; i < Diamond::MAX_DIAMOND_PART_NUM; ++i) {

		std::string dat = "./Resource/skill_data_0";
		dat += std::to_string(i + 1);
		dat += ".dat";

		m_file.open(dat, std::ios::binary | std::ios::out);
		m_file.write((char*)&m_diamond_list[i]->GetSkillDara(), sizeof(Skill_Data));
		m_file.close();
	}
	// ひし形の削除
	for (auto diamond : m_diamond_list) {
		delete diamond;
		diamond = nullptr;
	}
	// スキルテーブルの削除
	for (auto skill_table : m_skill_table) {
		delete skill_table;
		skill_table = nullptr;
	}
}
/*----デストラクタ----*/
/*----public----*/

