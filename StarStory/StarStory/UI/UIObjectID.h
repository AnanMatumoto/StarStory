#pragma once

//============================
// UIオブジェクトの識別ID
//============================

enum UIObjectID {

	BT_NONE,

	//------UI---------
	//タイトルボタン
	BT_TT_START,		//タイトル画面スタート
	BT_TT_END,		//  　〃　　　終了

	//ステージセレクトボタン
	BT_SL_STAGE,
	BT_SL_BACK,

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
