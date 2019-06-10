#include "ObjectManager.h"
#include "../../SkillData/Skill_Data.h"
#include "../ObjectFactory/StageObjectFactory.h"
#include "../../Sound/SoundManager/SoundManager.h"
#include "../../Lib/Lib.h"
#include <vector>
#include <fstream>
#include <iostream>

//-----------------------------------
// インスタンス生成
ObjectManager& ObjectManager::GetInstance() {

	static ObjectManager s_instance;
	return s_instance;
}

//----------------------------------
//　オブジェクト登録処理
void ObjectManager::Register(
	StageObjectID id,
	float x, float y,
	bool has_goal,
	std::string tex_name
) {
	StageObjectFactory obj_factory;
	m_obj_list.emplace(
		id,
		obj_factory.CreateMap(id, x, y, has_goal, tex_name)
	);
}

//-----------------------------------
//　オブジェクトの登録処理（星生成用）
void ObjectManager::Register(
	StageObjectID id,
	std::string data_file,
	float x, float y,
	float rot
) {
	//取り出し用変数
	Skill_Data data;
	Skill skill;
	std::string tex_name;
	SoundResourceID se_name;

	//ファイルの読み取り
	std::fstream file;
	file.open(data_file,std::ios::binary|std::ios::in);
	file.read((char*)&data, sizeof(Skill_Data));

	//情報を移す
	skill    = data.m_skill;
	tex_name = data.m_tex_name;
	se_name  = data.m_sound_resource;

	file.close();

	StageObjectFactory obj_factory;
	m_obj_list.emplace(
		id, 
		obj_factory.Create(id,x, y, tex_name, se_name, skill, rot)
	);
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
// オブジェクトの複製処理
void ObjectManager::Create(
	StageObjectID id,
	StageObjectID new_id,
	float x, float y,
	bool has_goal
) {
	StageObjectFactory factory;
	m_obj_list.emplace(new_id, factory.CreateMap(id, x, y,has_goal));
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

