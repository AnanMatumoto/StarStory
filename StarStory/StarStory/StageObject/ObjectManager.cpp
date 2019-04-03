#include "ObjectManager.h"
#include "Factory.h"
#include "StageObjectFactory.h"
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

	StageObjectFactory factory;
	m_obj_list.emplace(id, factory.Create(id));
}

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
// オブジェクトの描画
void ObjectManager::Draw() {

	for (auto it : m_obj_list) {

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
	auto itr = m_obj_list.find(id);

	if (itr != m_obj_list.end()) {
		ObjectBase* obj = itr->second;
		// フラグを削除状態にセットする
		obj->Delete();
	}
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
void ObjectManager::Create(StageObjectID id, StageObjectID new_id) {

	StageObjectFactory factory;
	m_obj_list.emplace(new_id, factory.Create(id));

}