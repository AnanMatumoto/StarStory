#pragma once

#include"ObjectBase.h"
#include "../Skill.h"
#include <unordered_map>
#include <string>

//==================================
// ステージオブジェクト管理クラス
//==================================

class ObjectManager {

public:
	//　インスタンス生成処理
	static ObjectManager& GetInstance();
	/*　
	   ステージオブジェクトの登録処理
	
		第1：オブジェクトID
		第2：X座標
		第3：Y座標
		第4：スキル名
		第5：画像名
		第6：回転角度
	*/
	void Register(
		StageObjectID id,
		float x, float y,
		Skill skill = NORMAL,
		std::string tex_name = "none",
		float rot = 0.f
	);
	//　更新処理
	void Update();

	//  描画処理
	void Draw();

	//  IDで指定したオブジェクトを削除する
	void Delete(StageObjectID id);

	//　リスト内にあるオブジェクトを全て削除する
	void AllDelete();

	//  複製処理
	void Create(
		StageObjectID id,
		StageObjectID new_id,
		float x, float y
	);

	//　引数でもらったidのオブジェクトを取得する
	ObjectBase* FindObject(StageObjectID id);

	//  引数でもらったidのオブジェクトをリストで取得
	template<class T>
	std::vector<T*> GetGameObjects() {

		std::vector<T*>list;
		for (auto& it : m_obj_list) {
			T*ptr = dynamic_cast<T*>(it.second);
			if (ptr != nullptr) {
				list.push_back(ptr);
			}
		}

		return list;
	}


private:

	std::unordered_map<StageObjectID, ObjectBase*> m_obj_list; // オブジェクトリスト

};
