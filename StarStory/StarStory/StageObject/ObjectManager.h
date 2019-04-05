#pragma once

#include"ObjectBase.h"
#include <unordered_map>

//==================================
// ステージオブジェクト管理クラス
//==================================

class ObjectManager {

public:
	//　インスタンス生成処理
	static ObjectManager& GetInstance();
	//　ステージオブジェクトの登録処理
	void Register(
		StageObjectID id,
		float x, float y
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

	ObjectBase* GetPtr(StageObjectID id);

private:

	std::unordered_map<StageObjectID, ObjectBase*> m_obj_list; // オブジェクトリスト

};

