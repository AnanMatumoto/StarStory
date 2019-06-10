#pragma once

#include "../../StageObject/ObjectBase.h"
#include "../UIObjectID.h"
#include <unordered_map>
#include <string>


//=================================
// UI管理クラス
//=================================

class UIManager {

public:
	// インスタンス生成処理
	static UIManager& GetInstance();

	/*
	   UIの登録

	   第1：UIのID
	   第2：X座標
	   第3：Y座標
	   第4：画像名
	
	*/
	void Register(
		UIObjectID id,
		float x, float y,
		std::string tex_name
	);

	//更新処理
	void Update();

	//  描画処理
	void Draw();

	/* 
	IDで指定したオブジェクトを削除する
	引数：
	　　id(UIオブジェクトのID)
	*/
	void Delete(UIObjectID id);

	//　リスト内にあるオブジェクトを全て削除する
	void AllDelete();

	//  クリックされたUIのIDを返す
	UIObjectID FindClickedUI();

	/* 
	スイッチ式のUIに対するONとOFF状態を判定する
	引数：
	　id(判定対象のUIオブジェクトID)
	*/
	bool SwitchOnUI(UIObjectID id);


private:

	std::unordered_map<UIObjectID, ObjectBase*>m_UI_list;//UIリスト

};