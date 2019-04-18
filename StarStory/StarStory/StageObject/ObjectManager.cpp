#include "ObjectManager.h"
#include "Factory.h"
#include "StageObjectFactory.h"
#include "../UI/UIObjectFactory.h"
#include "../Lib/Lib.h"
#include <vector>



//-----------------------------------
// インスタンス生成
ObjectManager& ObjectManager::GetInstance() {

	static ObjectManager s_instance;
	return s_instance;
}

//----------------------------------
//　オブジェクトの登録
void ObjectManager::Register(
	StageObjectID id,
	float x, float y,
	std::string tex_name
) {

	UIObjectFactory UI_factory;
	m_UI_list.emplace(id, UI_factory.Create(id, x, y, tex_name));
}

//----------------------------------
//　オブジェクト登録処理(オーバーロード)
void ObjectManager::Register(
	StageObjectID id,
	float x, float y,
	Skill skill,
	std::string tex_name,
	float rot
) {
	StageObjectFactory obj_factory;
	m_obj_list.emplace(id, obj_factory.Create(id, x, y, skill, tex_name, rot));
}

/*
Todo:
	テンプレートでアップデート描画等を
	行えるように今後修正する
*/
//-----------------------------------
//　オブジェクトの更新
void ObjectManager::Update() {

	for (auto it : m_obj_list) {
		if (it.second->IsDelete()) {
			continue;
		}
		it.second->Update();
	}
}

//-----------------------------------
//　UIの更新
void ObjectManager::UpdateUI() {
	
	for (auto it : m_UI_list) {
		it.second->Update();
	}

}

//-----------------------------------
// オブジェクトの描画
void ObjectManager::Draw() {

	for (auto it : m_obj_list) {

		if (it.second->IsDelete()) {
			continue;
		}
		it.second->Draw();
	}
}

//-------------------------------------
// UIの描画
void ObjectManager::DrawUI() {
	for (auto it : m_UI_list) {
		it.second->Draw();
	}
}

//------------------------------------
//　オブジェクトの削除
void ObjectManager::Delete(StageObjectID id) {

	// idと相応する要素を取得
	auto itr = m_obj_list.find(id);

	if (itr != m_obj_list.end()) {
		ObjectBase* obj = itr->second;
		// フラグを削除状態にセットする
		obj->Delete();
	}
}

//------------------------------------
//　指定したUIを削除
void ObjectManager::DeleteUI(StageObjectID id) {

	auto itr = m_UI_list.find(id);

	if (itr != m_UI_list.end()) {
		ObjectBase* obj = itr->second;
		delete obj;
	}
	m_UI_list.erase(itr);
}

//------------------------------------
//　オブジェクトの全削除
void ObjectManager::AllDelete() {

	// 全要素にあるオブジェクトをすべて解放
	for (auto it : m_obj_list) {

		ObjectBase* obj = it.second;
		if (obj != nullptr) {
			delete obj;
		}
	}

	//　要素をすべて削除
	m_obj_list.clear();
}

//-----------------------------------
//　UIの削除
void ObjectManager::AllDeleteUI() {

	for (auto it : m_UI_list) {
		ObjectBase* UI = it.second;
		if (UI != nullptr) {
			delete UI;
		}
	}
	m_UI_list.clear();
}
//-----------------------------------
void ObjectManager::Create(
	StageObjectID id,
	StageObjectID new_id,
	float x, float y
) {

	StageObjectFactory factory;
	m_obj_list.emplace(new_id, factory.Create(id, x, y));
}

//------------------------------------
// IDで指定したオブジェクトを返す
ObjectBase* ObjectManager::FindObject(StageObjectID id) {

	//指定した型にキャストしたリストを作る
	auto it = m_obj_list.find(id);
	if (it != m_obj_list.end()) {

		ObjectBase* obj = it->second;
		return obj;
	}
	return nullptr;
}

