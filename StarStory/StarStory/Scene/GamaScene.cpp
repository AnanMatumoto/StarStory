#include "GameScene.h"
#include "SceneManager.h"
#include "../StageObject/ObjectManager.h"
#include "../StageObject/StarObject.h"
#include "../UI/UIManager.h"

#include "../SkillData/Skill_Data.h"
#include <iostream>
#include <fstream>

#define TEX_OBJ_192  "Resource/Game/object_192x192.png"
#define TEX_OBJ_128 "Resource/Game/object_128x128.png"

#define GAME_STAGE  "Resource/Game/stage1_background_1-1.png"
#define GAME_UI_WND "Resource/Game/ui_stage_base.png"
#define GAME_CUSTOM "Resource/Game/ui_stage_custom.png"
#define GAME_STOP   "Resource/Game/ui_stage_stop.png"
#define GAME_PLAY   "Resource/Game/ui_stage_x1.png"
#define GAME_DUBLE  "Resource/Game/ui_stage_x2.png"
#define GAME_OFF    "Resource/Game/ui_stage_skilloff.png"
#define GAME_ON     "Resource/Game/ui_stage_skillon.png"

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	m_state_id = SS_UPDATE;
	//stage = new StageBase();
	
	Lib::AudioClip& clip = Lib::AudioClip::GetInterface();
	clip.LoadWaveFile("Resource/Audio/BGM/game_main_bgm.wav");
	m_sound = new Lib::AudioPlayer();
	m_sound->Play("Resource/Audio/BGM/game_main_bgm.wav");
	m_sound->SetVolume(-1000);

	//-----------------------------------------------------
	//■■■■　実装され次第消す■■■■
	Skill_Data data[5];
	data[0] = { SPEED, "Resource/Player/player_1_accel.png","Resource/Audio/SE/star_accel.wav" };
	data[1] = { JUMP,   "Resource/Player/player_1_jump.png","Resource/Audio/SE/star_jump.wav"};
	data[2] = { NORMAL, "Resource/Player/player_1_normal.png","Resource/Audio/SE/star_normal.wav"};
	data[3] = { NORMAL, "Resource/Player/player_1_normal.png","Resource/Audio/SE/star_normal.wav"};
	data[4] = { NORMAL, "Resource/Player/player_1_normal.png","Resource/Audio/SE/star_normal.wav"};

	std::fstream file[5];
	file[0].open("./Resource/skill_data_01.dat", std::ios::binary | std::ios::out);
	file[0].write((char*)&data[0], sizeof(Skill_Data));
	file[0].close();

	file[1].open("./Resource/skill_data.02.dat", std::ios::binary | std::ios::out);
	file[1].write((char*)&data[1], sizeof(Skill_Data));
	file[1].close();


	file[2].open("./Resource/skill_data.03.dat", std::ios::binary | std::ios::out);
	file[2].write((char*)&data[2], sizeof(Skill_Data));
	file[2].close();

	file[3].open("./Resource/skill_data.04.dat", std::ios::binary | std::ios::out);
	file[3].write((char*)&data[3], sizeof(Skill_Data));
	file[3].close();

	file[4].open("./Resource/skill_data.05.dat", std::ios::binary | std::ios::out);
	file[4].write((char*)&data[4], sizeof(Skill_Data));
	file[4].close();
	//------------------------------------------------------------

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
	UImng.Register(BT_GM_WIND, 65, 35, GAME_UI_WND);
	UImng.Register(BT_GM_TOCUSTOM, 89,52,GAME_CUSTOM);
	UImng.Register(BT_GM_STOP, 525, 49, GAME_STOP );
	UImng.Register(BT_GM_ONOFF, 292, 52,GAME_OFF );

	m_result = NO_RESULT;

}

//------------------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	// プレーヤーがクリアまたはゲームオーバーである
	if (m_result > 0) {
		m_state_id = SS_END;
		m_scene_id = SC_RESULT;
	}

	//　カスタムボタンが押された
	if (ui_mng.FindClickedUI() == BT_GM_TOCUSTOM) {
		m_state_id = SS_END;
		m_scene_id = SC_CUSTOM;
	}

	if (ui_mng.SwithOnUI(BT_GM_STOP)==false) {
		// ステージオブジェクト更新
		ObjectManager::GetInstance().Update();
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
	m_sound->Stop();
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

}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

	delete m_sound;
}