#pragma once

//============================
// UIオブジェクトの識別ID
//============================

enum UIObjectID {

	BT_NONE,

	/*----タイトル----*/
	BT_TITLE_START,							
	BT_TITLE_END,				    

	/*---ステージセレクト----*/
	BT_SELECT_STAGE,				
	BT_SELECT_BACK,				   

	/*----カスタム----*/
	BT_CUSTOM_BACK,				
	BT_CUSTOM_DECISION,		
	/*----ゲーム本編---*/
	BT_GAME_WIND,
	BT_GAME_FRAME,
	BT_GAME_BACK,
	BT_GAME_STOP,
	BT_GAME_ONOFF,

	/*-----リザルト------*/
	BT_RESULT_BACK_SELECT,		
	BT_RESULT_BACK_CUSTOM,		
	BT_RESULT_BACK_TITLE,    
	BT_RESULT_CLEAR,
	BT_RESULT_FAILD,
	BT_RESULT_FRAME_R,
	BT_RESULT_FRAME_L,
	/*----UI----*/

	MAX_NUM
};
