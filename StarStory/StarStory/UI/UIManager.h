﻿#pragma once

#include "../StageObject/ObjectBase.h"
#include <unordered_map>
#include <string>

enum UIObjectID {

	BT_NONE,

	//------UI---------
	//タイトルボタン
	BT_TT_START,		//タイトル画面スタート
	BT_TT_END,		//  　〃　　　終了

	//カスタム
	CT_NORMAL,
	CT_JUMP,
	CT_ACCEL,
	CT_LIGHT,
	CT_STOP,
	//CT_WEAK,
	//CT_STRONG
	//CT_COST1,
	//CT_COST2,
	//CT_COST3,
	BT_CT_DECISION,
	BT_CT_MAP,
	BT_CT_TOSELECT,

	//ゲームボタン
	BT_GM_WIND,
	BT_GM_TOCUSTOM,
	BT_GM_STOP,
	BT_GM_ONOFF,

	//リザルト
	BT_RS_SELECT,		//ステージセレクトへ
	BT_RS_CUSUTOM,		//カスタムへ
	BT_RS_TITLEBACK	    //タイトル画面へ
};



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

	//  IDで指定したオブジェクトを削除する
	void Delete(UIObjectID id);

	//　リスト内にあるオブジェクトを全て削除する
	void AllDelete();

	//クリックされたUIのIDを返す
	UIObjectID FindClickedUI();

private:

	std::unordered_map<UIObjectID, ObjectBase*>m_UI_list;//UIリスト
};