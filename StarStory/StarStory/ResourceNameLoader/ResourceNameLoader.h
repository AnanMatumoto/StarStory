#pragma once

#include <unordered_map>
#include <string>
//===============================
//リソースのリスト読み込みクラス
//===============================

enum ResourceID {

	PNG_TITLE_BACK_GROUND,
	PNG_TITLE_START,
	PNG_TITLE_END,

	PNG_SELECT_BACK_GROUND,
	PNG_SELECT_BOOK,
	PNG_SELECT_STAGE1,
	PNG_SELECT_BACK,

	PNG_CUSTOM_BASE,
	PNG_CUSTOM_DECISION,
	PNG_CUSTOM_BACK,
	PNG_CUSTOM_MAP1,

	PNG_GAME_OBJ_192,
	PNG_GAME_OBJ_128,
	PNG_GAME_OBJ_64,
	PNG_GAME_BACK_GROUND,
	PNG_GAME_WIND,
	PNG_GAME_FRAME,
	PNG_GAME_BACK,
	PNG_GAME_STOP,

	PNG_RESULT_FAILD,
	PNG_RESULT_CLEAR,
	PNG_RESULT_WIND,
	PNG_RESULT_TO_CUSTOM,
	PNG_RESULT_TO_SELECT,
	PNG_RESULT_FRAME_R,
	PNG_RESULT_FRAME_L,
	PNG_RESULT_ROGO_FAILD,
	PNG_RESULT_ROGO_CLEAR,
	PNG_MAX_NUM,
};

class ResourceNameLoader {

public:

	static ResourceNameLoader& GetInstance() {
		static ResourceNameLoader list_loder;
	    return list_loder;
	}

	void EntryResourceName();
	const char* GetName(ResourceID id);


private:
	std::unordered_map<ResourceID, const char*> m_list;

};

