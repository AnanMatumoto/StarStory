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
	CT_BASE,
	CT_NUM_1,
	CT_NUM_2,
	CT_NUM_3,
	CT_NUM_4,
	CT_NUM_5,
	CT_SKILL_TABLE_BASE,
	CT_NORMAL_SKILL,
	CT_JUMP_SKILL,
	CT_ACCEL_SKILL,
	CT_LIGHT_SKILL,
	CT_STOP_SKILL,
	BT_CT_WEAK,
	BT_CT_STRONG,
	BT_CT_DECISION,
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
