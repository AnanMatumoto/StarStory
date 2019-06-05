#include "GameScene.h"
#include "../SceneManager/SceneManager.h"
#include "../../StageObject/ObjectManager/ObjectManager.h"
#include "../../StageObject/Player/StarObject.h"
#include "../../UI/UIManager/UIManager.h"
#include "../../Sound/SoundManager/SoundManager.h"

#include "../../SkillData/Skill_Data.h"
#include <iostream>
#include <fstream>

#define TEX_OBJ_192  "Resource/Game/object_192x192.png"
#define TEX_OBJ_128  "Resource/Game/object_128x128.png"
#define TEX_OBJ_64   "Resource/Game/object_64x64.png"

#define GAME_STAGE  "Resource/Game/stage1_background_1-1_1920×1080_ｄ (1).png"
#define GAME_UI_WND  "Resource/Game/ui_stage_base.png"
#define GAME_UI_FLAME "Resource/Game/ui_flame_557_102.png"
#define GAME_CUSTOM "Resource/Game/ui_stage_custom.png"
#define GAME_STOP   "Resource/Game/ui_stage_stop.png"
#define GAME_PLAY   "Resource/Game/ui_stage_x1.png"
#define GAME_DUBLE  "Resource/Game/ui_stage_x2.png"
#define GAME_OFF    "Resource/Game/ui_stage_skilloff.png"
#define GAME_ON     "Resource/Game/ui_stage_skillon.png"

#define GAME_FAILD    "Resource/Result/gameover_illustration.png"
#define GAME_CLEAR    "Resource/Result/gameclera_illustration.png"
#define RESULT_BACKIMG "Resource/Result/ui_result_base.png"
#define RESULT_CUSTOM "Resource/Result/ui_result_custom.png"
#define RESULT_SELECT "Resource/Result/ui_result_select.png"
#define RESULT_FLAME_R  "Resource/Result/ui_flame_262_63.png"
#define RESULT_FLAME_L "Resource/Result/ui_flame_262_63.png"
#define RESULT_CLEAR   "Resource/Result/GameClear .png"
#define RESULT_FAILD  "Resource/Result/GameOver.png"

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	m_state_id = SS_UPDATE;

	// BGM再生
	SoundManager::GetInstanse().SoundPlayer(GAME_BGM, SoundManager::PLAY);

	ObjectManager& mng = ObjectManager::GetInstance();
	UIManager & UImng = UIManager::GetInstance();

    //ステージオブジェクトの登録
	mng.Register(OBJ_1, 100,  600, false, TEX_OBJ_192);
	mng.Register(OBJ_2, 350,  650, false, TEX_OBJ_128);
	mng.Register(OBJ_3, 550,  700, false, TEX_OBJ_192);
	mng.Register(OBJ_4, 810,  600, false, TEX_OBJ_128);
	mng.Register(OBJ_5, 1000, 780, false, TEX_OBJ_192);
	mng.Register(OBJ_6, 1250, 700, false, TEX_OBJ_64);
	mng.Register(OBJ_7, 1350, 810, false, TEX_OBJ_192);
	mng.Register(OBJ_8, 1580, 680, true,  TEX_OBJ_128);
	
	//星のオブジェクト
	mng.Register(STAR_CHILD1, "./Resource/skill_data_01.dat",  0, -32, 0);
	mng.Register(STAR_CHILD2, "./Resource/skill_data_02.dat", 30, -10, 72);
	mng.Register(STAR_CHILD3, "./Resource/skill_data_03.dat", 19, 26, 144);
	mng.Register(STAR_CHILD4, "./Resource/skill_data_04.dat",-19, 26, 216);
	mng.Register(STAR_CHILD5, "./Resource/skill_data_05.dat",-30, -10, 288);
	mng.Register(STAR_OBJ, "none", 90, 500);

	//UIの登録
	UImng.Register(BT_GAME_BACK, 139,67,GAME_CUSTOM);
	UImng.Register(BT_GAME_STOP, 355, 65, GAME_STOP );
	m_result = NO_RESULT;
}

//------------------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	//　カスタムボタンが押された
	if (ui_mng.FindClickedUI() == BT_GAME_BACK) {
		m_state_id = SS_END;
		m_scene_id = SC_CUSTOM;
	}

	if (ui_mng.SwithOnUI(BT_GAME_STOP)==false) {
		// ステージオブジェクト更新
		ObjectManager::GetInstance().Update();
	}

	if (m_result > 0) {
		if (ui_mng.FindClickedUI() == BT_RESULT_BACK_CUSTOM) {
			m_state_id = SS_END;
			m_scene_id = SC_CUSTOM;
		}

		if (ui_mng.FindClickedUI() == BT_RESULT_BACK_SELECT) {
			m_state_id = SS_END;
			m_scene_id = SC_SELECT;
		}
	}

}

//------------------------------------------
//　ゲームシーン終了
SceneID GameScene::End() {

	m_state_id = SS_INIT;

	//UIをリストから削除
	UIManager::GetInstance().AllDelete();
	
	// オブジェクトの削除
	ObjectManager::GetInstance().AllDelete();

	//BGMの終了
	SoundManager::GetInstanse().SoundPlayer(GAME_BGM, SoundManager::STOP);

	return m_scene_id;
}

//-----------------------------------------
//　ゲームシーン状態更新
SceneID GameScene::Control() {

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
	return SC_GAME;
}

//-----------------------------------------
//　ゲームシーン描画
void GameScene::Draw() {

	UIManager& ui_mng = UIManager::GetInstance();

	//ステージ背景
	Lib::DrawPx2D(
		GAME_STAGE,
		0, 0,
		1920,1080,
		1.f
	);
	
	Lib::DrawBox2D(GAME_UI_WND, 60, 51);
	Lib::DrawBox2D(GAME_UI_FLAME, 5, 0);

	// ステージオブジェクト描画
	ObjectManager::GetInstance().Draw();
	UIManager::GetInstance().Draw();

	//リザルト描画
	if (m_result > 0) {
		DrawResult();
	}

}

//---------------------------------------
//リザルト結果を描画する
void GameScene::DrawResult() {


	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Register(BT_RESULT_BACK_CUSTOM, 788, 780, RESULT_CUSTOM);
	ui_mng.Register(BT_RESULT_BACK_SELECT, 1148, 780, RESULT_SELECT);

	Lib::DrawBoxAlpha(
		"over_ray",
		0, 0,
		Lib::CreateColor(1.f, 1.f, 1.f, 0.3f),
		1920, 1080
	);

	Lib::DrawBox2D(
		RESULT_BACKIMG,
		463, 193
	);

	Lib::DrawBox2D(RESULT_FLAME_R, 750, 738);
	Lib::DrawBox2D(RESULT_FLAME_L, 1108, 738);

	if (m_result == FAILD) {

		Lib::DrawBox2D(
			GAME_FAILD,
			648, 300
		);
		Lib::DrawPx2D(
			RESULT_FAILD,
			600, 578,
			700,200
		);
	}
	else {
		Lib::DrawBox2D(
			GAME_CLEAR,
			648, 300
		);
		Lib::DrawBox2D(
			RESULT_FAILD,
			600, 578,
			700, 200
		);
	}
	ui_mng.Draw();
}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

}