#include "CustomScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../UI/UIManager.h"

#define CUSTOM_WINDOW	"Resource/Custom/UI_custom_window.png"		
#define CUSTOM_NORMAL	"Resource/Custom/UI_custom_normal.png"		
#define CUSTOM_JUMP		"Resource/Custom/UI_custom_jump.png"			
#define CUSTOM_ACCEL	"Resource/Custom/UI_custom_accel.png"		
#define CUSTOM_LIGHT	"Resource/Custom/UI_custom_light.png"		
#define CUSTOM_STOP		"Resource/Custom/UI_custom_stop.png"			
#define CUSTOM_WEAK		"Resource/Custom/UI_custom_weak.png"			
#define CUSTOM_STRONG	"Resource/Custom/UI_custom_strong.png"		
#define CUSTOM_COST1	"Resource/Custom/UI_custom_cost1.png"		
#define CUSTOM_COST2	"Resource/Custom/UI_custom_cost2.png"		
#define CUSTOM_COST3	"Resource/Custom/UI_custom_cost3.png"		
#define CUSTOM_DECISION "Resource/Custom/UI_custom_decision.png"			
#define CUSTOM_MAP		"Resource/Custom/UI_custom_map.png"			
#define CUSTOM_SERECT	"Resource/Custom/UI_custom_serect.png"		

//-----------------------------
//　カスタムシーン初期化
void CustomScene::Init() {

	m_state_id = SS_UPDATE;

	UIManager & UImng = UIManager::GetInstance();

	/*--UI描画--*/
	UImng.Register(CT_NORMAL, 1270, 190, CUSTOM_NORMAL);	// スキルなし
	UImng.Register(CT_JUMP, 1270, 310, CUSTOM_JUMP);		// ジャンプスキル
	UImng.Register(CT_ACCEL, 1270, 430, CUSTOM_ACCEL);		// 加速スキル
	UImng.Register(CT_LIGHT, 1270, 547, CUSTOM_LIGHT);		// 光るスキル
	UImng.Register(CT_STOP, 1270, 665, CUSTOM_STOP);		// 停止スキル

	//// 強弱スキル
	//float weak = 190;
	//for (int i = 0; i < 5; ++i) {

	//	UImng.Register(CT_WEAK, 1600, weak, CUSTOM_WEAK);
	//	weak += 118;
	//}

	//// コスト
	//float cost = 180;
	//for (int i = 0; i < 5; ++i) {

	//	UImng.Register(CT_COST1, 1670, cost, CUSTOM_COST1);
	//	cost += 119;
	//}

	UImng.Register(BT_CT_DECISION, 1445, 787, CUSTOM_DECISION);		// 決定ボタン
	UImng.Register(BT_CT_MAP, 1115, 787, CUSTOM_MAP);				// マップ確認ボタン
	UImng.Register(BT_CT_TOSELECT, 1115, 887, CUSTOM_SERECT);		// セレクト画面へ戻るボタン
	/*--UI描画--*/
}

//----------------------------
//　カスタムシーン更新
void CustomScene::Update() {

	// UI更新
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	//決定ボタンが押されたら
	if (ui_mng.FindClickedUI()==BT_CT_DECISION) {

		m_state_id = SS_END;
	}

	// マウス座標取得
	Lib::GetMousePoint(&mouse_x, &mouse_y);

	// マウス情報をカスタムシーンからカスタムスターに移す
  	custom_star.SetMousePos(mouse_x, mouse_y);

	// 星型の更新
	custom_star.Update();	
}

//----------------------------
// 　カスタムシーン終了
SceneID CustomScene::End() {

	m_state_id = SS_INIT;

	// UIをリストから削除
	UIManager::GetInstance().Delete(CT_NORMAL);
	UIManager::GetInstance().Delete(CT_JUMP);
	UIManager::GetInstance().Delete(CT_ACCEL);
	UIManager::GetInstance().Delete(CT_LIGHT);
	UIManager::GetInstance().Delete(CT_STOP);
	//UIManager::GetInstance().Delete(CT_WEAK);
	//UIManager::GetInstance().Delete(CT_COST1);
	UIManager::GetInstance().Delete(BT_CT_DECISION);
	UIManager::GetInstance().Delete(BT_CT_MAP);
	UIManager::GetInstance().Delete(BT_CT_TOSELECT);

	return SC_GAME;
}

//----------------------------
//	カスタムシーン状態管理
SceneID CustomScene::Control() {

	switch (m_state_id)
	{
	case SS_INIT:
		Init();
		break;

	case SS_UPDATE:
		Update();
		Draw();
		break;

	case SS_END:
		return End();
		break;
	}
	return SC_CUSTOM;
}

//----------------------------
//　カスタムシーン描画
void CustomScene::Draw() {

	// 「背景」
	Lib::DrawBox2D(CUSTOM_WINDOW,0, -20);

	// UI描画
	UIManager::GetInstance().Draw();

	// 「星型の描画」
	custom_star.Draw();
}

