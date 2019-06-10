#include "UIManager.h"
#include "../../Lib/Lib.h"
#include "../UIFactory/UIObjectFactory.h"
#include "../Button/Button.h"
#include <vector>

//-------------------------------
//インスタンス生成
UIManager& UIManager::GetInstance() {
	static UIManager s_instance;
	return s_instance;
}

//--------------------------------
// UIの登録
void UIManager::Register(
	UIObjectID id,
	float x, float y,
	std::string tex_name
) {

	UIObjectFactory UI_factory;
	m_UI_list.emplace(id, UI_factory.Create(id, x, y, tex_name));
}

//---------------------------------
// UIの更新処理
void UIManager::Update() {

	for (auto it : m_UI_list) {
		it.second->Update();
	}
}

//-------------------------------------
// UIの描画
void UIManager::Draw() {
	for (auto it : m_UI_list) {
		it.second->Draw();
	}
}

//------------------------------------
//　指定したUIを削除
void UIManager::Delete(UIObjectID id) {

	auto itr = m_UI_list.find(id);

	if (itr != m_UI_list.end()) {
		ObjectBase* obj = itr->second;
		delete obj;
	}
	m_UI_list.erase(itr);
}

//-----------------------------------
//　UIの削除
void UIManager::AllDelete() {

	for (auto it : m_UI_list) {
		ObjectBase* UI = it.second;
		if (UI != nullptr) {
			delete UI;
		}
	}
	m_UI_list.clear();
}

//---------------------------------------------
// クリックされたUIのIDを返す
UIObjectID UIManager::FindClickedUI() {

	UIObjectID id = BT_NONE;
	// リストからクリックされたオブジェクトを取得する
	for (auto ui : m_UI_list) {
		ButtonUI* buttom = (ButtonUI*)ui.second;
		if (buttom->GetClick()) {
			id = ui.first;
		}
	}
	return id;
}

//--------------------------------------------
//  スイッチ式のUIに対するONとOFF状態を判定する
bool UIManager::SwitchOnUI(UIObjectID id) {

	auto ui = m_UI_list.find(id);
	if (ui != m_UI_list.end()) {
		ButtonUI* button = (ButtonUI*)ui->second;
		if (button->GetClickCount() == 1) {
			return true;
		}
		else {
			return false;
		}

	}
}