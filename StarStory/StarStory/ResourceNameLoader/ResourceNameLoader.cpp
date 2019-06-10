#include "ResourceNameLoader.h"

void ResourceNameLoader::EntryResourceName(){

	//タイトルシーン使用画像
	m_list.emplace(PNG_TITLE_BACK_GROUND,  "Resource/Title/ui_title_base.png");
	m_list.emplace(PNG_TITLE_START,        "Resource/Title/ui_title_start.png");
	m_list.emplace(PNG_TITLE_END,          "Resource/Title/ui_title_end.png");

	//セレクトシーン使用画像
	m_list.emplace(PNG_SELECT_BACK_GROUND, "Resource/StageSelect/stage_1_cover.png");
	m_list.emplace(PNG_SELECT_BOOK,        "Resource/StageSelect/ui_select_base.png");
	m_list.emplace(PNG_SELECT_STAGE1,      "Resource/StageSelect/ui_select_ep1.png");
	m_list.emplace(PNG_SELECT_BACK,        "Resource/StageSelect/ui_select_title.png");

	//カスタムシーン使用画像
	m_list.emplace(PNG_CUSTOM_BASE,        "Resource/Custom/ui_custom_base_ver2.png");
	m_list.emplace(PNG_CUSTOM_DECISION,    "Resource/Custom/ui_custom_nextpage.png");
	m_list.emplace(PNG_CUSTOM_BACK,        "Resource/Custom/ui_custom_stageselect.png");
	m_list.emplace(PNG_CUSTOM_MAP1,        "Resource/Custom/stage1_map.png");
	
	//ゲームシーン使用画像
	m_list.emplace(PNG_GAME_OBJ_192,       "Resource/Game/object_192x192.png");
	m_list.emplace(PNG_GAME_OBJ_128,       "Resource/Game/object_128x128.png");
	m_list.emplace(PNG_GAME_OBJ_64,        "Resource/Game/object_64x64.png");
	m_list.emplace(PNG_GAME_BACK_GROUND,   "Resource/Game/stage1_background_1-1_1920×1080_ｄ (1).png");
	m_list.emplace(PNG_GAME_WIND,          "Resource/Game/ui_stage_base.png");
	m_list.emplace(PNG_GAME_FRAME,         "Resource/Game/ui_flame_557_102.png");
	m_list.emplace(PNG_GAME_BACK,          "Resource/Game/ui_stage_custom.png");
	m_list.emplace(PNG_GAME_STOP,          "Resource/Game/ui_stage_stop.png");

	//リザルトシーン使用画像
	m_list.emplace(PNG_RESULT_FAILD,       "Resource/Result/gameover_illustration.png");
	m_list.emplace(PNG_RESULT_CLEAR,       "Resource/Result/gameclera_illustration.png");
	m_list.emplace(PNG_RESULT_WIND,        "Resource/Result/ui_result_base.png");
	m_list.emplace(PNG_RESULT_TO_CUSTOM,   "Resource/Result/ui_result_custom.png");
	m_list.emplace(PNG_RESULT_TO_SELECT,   "Resource/Result/ui_result_select.png");
	m_list.emplace(PNG_RESULT_FRAME_R,     "Resource/Result/ui_flame_262_63.png");
	m_list.emplace(PNG_RESULT_FRAME_L,     "Resource/Result/ui_flame_262_63.png");
	m_list.emplace(PNG_RESULT_ROGO_FAILD,  "Resource/Result/GameOver.png");
	m_list.emplace(PNG_RESULT_ROGO_CLEAR,  "Resource/Result/GameClear.png");
}
const char* ResourceNameLoader::GetName(ResourceID id) {

	auto it = m_list.find(id);
	if (it != m_list.end()) {
		return it->second;
	}
	return nullptr;
}

