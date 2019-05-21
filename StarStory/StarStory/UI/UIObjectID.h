#pragma once

//============================
// UIオブジェクトの識別ID
//============================

enum UIObjectID {

	BT_NONE,

	/*----UI----*/
	// タイトルボタン
	BT_TT_START,		//タイトル画面スタート
	BT_TT_END,			//  　〃　　　終了

	// ステージセレクトボタン
	BT_SL_STAGE,
	BT_SL_BACK,

	/*----カスタム----*/
	CT_BASE,				// 背景
	BT_CT_TOSELECT,			// セレクトへ戻るボタン
	BT_CT_DECISION,			// 決定ボタン
	/*----カスタム----*/

	// ゲームボタン
	BT_GM_WIND,
	BT_GM_FRAME,
	BT_GM_TOCUSTOM,
	BT_GM_STOP,
	BT_GM_ONOFF,

	// リザルト
	BT_RS_SELECT,		//ステージセレクトへ
	BT_RS_CUSUTOM,		//カスタムへ
	BT_RS_TITLEBACK,    //タイトル画面へ
	BT_RS_CLEAR,
	BT_RS_FAILD,
	BT_RS_FLAME_R,
	BT_RS_FLAME_L,
	/*----UI----*/

	MAX_NUM
};
