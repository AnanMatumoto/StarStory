#include "ObjectManager.h"
#include "../Lib/Lib.h"

//-----------------------------------
// インスタンス生成
ObjectManager& ObjectManager::GetInstance() {

	static ObjectManager s_instance;
	return s_instance;
}

//----------------------------------
//　オブジェクト登録処理
void ObjectManager::Register(StageObjectID id) {

	m_factory = new StageObjectFactory();
	obj_list.emplace(id, m_factory->Create(id));
}

//-----------------------------------
//　オブジェクトの更新
void ObjectManager::Update() {

	for (auto it : obj_list) {
		if (it.second->IsDelete()) {
			continue;
		}
		it.second->Update();
	}

	if (Lib::KeyOn('A')) {
		Delete(OBJ_TEST1);
	}
}

//-----------------------------------
// オブジェクトの描画
void ObjectManager::Draw() {

	for (auto it : obj_list) {

		if (it.second->IsDelete()) {
			continue;
		}
		it.second->Draw();
	}
}

//------------------------------------
//　オブジェクトの削除
void ObjectManager::Delete(StageObjectID id) {

	// idと相応する要素を取得
	auto itr = obj_list.find(id);

	if (itr != obj_list.end()) {
		ObjectBase* obj = itr->second;

		if (obj->IsDelete()) {

			if (obj != nullptr) {
				delete obj;
			}
		}
		itr = obj_list.erase(itr);
	}
}

//------------------------------------
//　オブジェクトの全削除
void ObjectManager::AllDelete() {

	// 全要素にあるオブジェクトをすべて解放
	for (auto it : obj_list) {

		ObjectBase* obj = it.second;
		if (obj != nullptr) {
			delete obj;
		}
	}
	//　要素をすべて削除
	obj_list.clear();
}