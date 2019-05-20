#include "GameScene.h"
#include "SceneManager.h"
#include "../StageObject/ObjectManager.h"
#include "../StageObject/StarObject.h"
#include "../UI/UIManager.h"
#include "../SoundManager/SoundManager.h"

#include "../SkillData/Skill_Data.h"
#include <iostream>
#include <fstream>

#define TEX_OBJ_192  "Resource/Game/object_192x192.png"
#define TEX_OBJ_128 "Resource/Game/object_128x128.png"

#define GAME_STAGE  "Resource/Game/stage1_background_1-1.png"
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

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	m_state_id = SS_UPDATE;
	//stage = new StageBase();
	
	/*Lib::AudioClip& clip = Lib::AudioClip::GetInterface();
	clip.LoadWaveFile("Resource/Audio/BGM/game_main_bgm.wav");
	m_sound = new Lib::AudioPlayer();
	m_sound->Play("Resource/Audio/BGM/game_main_bgm.wav");
	m_sound->SetVolume(-1000);*/

	// BGM再生
	SoundManager::GetInstanse().SoundPlayer(SoundManager::GAME_BGM, SoundManager::PLAY);

	ObjectManager& mng = ObjectManager::GetInstance();
	UIManager & UImng = UIManager::GetInstance();

    //ステージオブジェクトの登録
	mng.Register(OBJ_TEST1, 100, 600,TEX_OBJ_192);
	mng.Register(OBJ_TEST2, 400, 650,TEX_OBJ_128);
	mng.Register(OBJ_TEST3, 750, 700, TEX_OBJ_192);
	mng.Register(OBJ_TEST4, 1200, 600, TEX_OBJ_128);

	mng.Register(STAR_OBJ, 90, 500);
	mng.Register(STAR_CHILD1, "./Resource/skill_data_01.dat",  0, -32, 0);
	mng.Register(STAR_CHILD2, "./Resource/skill_data.02.dat", 30, -10, 72);
	mng.Register(STAR_CHILD3, "./Resource/skill_data.03.dat", 19, 26, 144);
	mng.Register(STAR_CHILD4, "./Resource/skill_data.04.dat",-19, 26, 216);
	mng.Register(STAR_CHILD5, "./Resource/skill_data.05.dat",-30, -10, 288);

	//UIの登録
	UImng.Register(BT_GM_WIND, 60, 51, GAME_UI_WND);
	UImng.Register(BT_GM_FRAME, 5, 0, GAME_UI_FLAME);
	UImng.Register(BT_GM_TOCUSTOM, 89,67,GAME_CUSTOM);
	UImng.Register(BT_GM_STOP, 525, 65, GAME_STOP );
	UImng.Register(BT_GM_ONOFF, 292, 67,GAME_OFF );
	m_result = NO_RESULT;
}

//------------------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	// プレーヤーがクリアまたはゲームオーバーである
	/*if (m_result > 0) {
		m_state_id = SS_END;
		m_scene_id = SC_RESULT;
	}*/

	//　カスタムボタンが押された
	if (ui_mng.FindClickedUI() == BT_GM_TOCUSTOM) {
		m_state_id = SS_END;
		m_scene_id = SC_CUSTOM;
	}

	if (ui_mng.SwithOnUI(BT_GM_STOP)==false) {
		// ステージオブジェクト更新
		ObjectManager::GetInstance().Update();
	}

	if (m_result > 0) {
		if (ui_mng.FindClickedUI() == BT_RS_CUSUTOM) {
			m_state_id = SS_END;
			m_scene_id = SC_CUSTOM;
		}

		if (ui_mng.FindClickedUI() == BT_RS_SELECT) {
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
	//m_sound->Stop();
	SoundManager::GetInstanse().SoundPlayer(SoundManager::GAME_BGM, SoundManager::STOP);

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
	ui_mng.Register(BT_RS_CUSUTOM, 788, 780, RESULT_CUSTOM);
	ui_mng.Register(BT_RS_SELECT, 1148, 780, RESULT_SELECT);
	ui_mng.Register(BT_RS_FLAME_R, 750, 738, RESULT_FLAME_R);
	ui_mng.Register(BT_RS_FLAME_L, 1108, 738, RESULT_FLAME_L);

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

	if (m_result == FAILD) {

		Lib::DrawBox2D(
			GAME_FAILD,
			640, 350
		);
	}
	else {
		Lib::DrawBox2D(
			GAME_CLEAR,
			463, 300
		);
	}
	ui_mng.Draw();
}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

	/*delete m_sound;*/
}