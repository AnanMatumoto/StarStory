#include "GameScene.h"
#include "../../StageObject/ObjectManager/ObjectManager.h"
#include "../../UI/UIManager/UIManager.h"
#include "../../Sound/SoundManager/SoundManager.h"
#include "../../ResourceNameLoader/ResourceNameLoader.h"
#include <iostream>
#include <fstream>

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	m_state_id = SS_UPDATE;

	// BGM再生
	SoundManager::GetInstanse().SoundPlayer(GAME_BGM, SoundManager::PLAY);
	ObjectManager& mng = ObjectManager::GetInstance();
	UIManager & UImng  = UIManager::GetInstance();
	auto res           = ResourceNameLoader::GetInstance();

    //ステージオブジェクトの登録
	mng.Register(OBJ_1, 100,  600, false, res.GetName(PNG_GAME_OBJ_192));
	mng.Register(OBJ_2, 350,  650, false, res.GetName(PNG_GAME_OBJ_128));
	mng.Register(OBJ_3, 550,  700, false, res.GetName(PNG_GAME_OBJ_192));
	mng.Register(OBJ_4, 810,  600, false, res.GetName(PNG_GAME_OBJ_128));
	mng.Register(OBJ_5, 1000, 780, false, res.GetName(PNG_GAME_OBJ_192));
	mng.Register(OBJ_6, 1250, 700, false, res.GetName(PNG_GAME_OBJ_64));
	mng.Register(OBJ_7, 1350, 810, false, res.GetName(PNG_GAME_OBJ_192));
	mng.Register(OBJ_8, 1580, 680, true,  res.GetName(PNG_GAME_OBJ_128));
	
	//星のオブジェクト
	mng.Register(STAR_CHILD1, "./Resource/skill_data_01.dat",  0, -32, 0);
	mng.Register(STAR_CHILD2, "./Resource/skill_data_02.dat", 30, -10, 72);
	mng.Register(STAR_CHILD3, "./Resource/skill_data_03.dat", 19, 26, 144);
	mng.Register(STAR_CHILD4, "./Resource/skill_data_04.dat",-19, 26, 216);
	mng.Register(STAR_CHILD5, "./Resource/skill_data_05.dat",-30, -10, 288);
	mng.Register(STAR_OBJ, "none", 90, 500);

	//ボタンUIの登録
	UImng.Register(BT_GAME_BACK, 139,67,res.GetName(PNG_GAME_BACK));
	UImng.Register(BT_GAME_STOP, 355, 65, res.GetName(PNG_GAME_STOP));
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

	if (ui_mng.SwitchOnUI(BT_GAME_STOP)==false) {
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
	auto res = ResourceNameLoader::GetInstance();
	//ステージ背景
	Lib::DrawPx2D(res.GetName(PNG_GAME_BACK_GROUND),0, 0,1920,1080,1.f);
	Lib::DrawBox2D(res.GetName(PNG_GAME_WIND), 60, 51);
	Lib::DrawBox2D(res.GetName(PNG_GAME_FRAME), 5, 0);

	// ステージオブジェクト描画
	ObjectManager::GetInstance().Draw();
	UIManager::GetInstance().Draw();

	//リザルト描画
	if (m_result > NO_RESULT) {
		DrawResult();
	}

}

//---------------------------------------
//リザルト結果を描画する
void GameScene::DrawResult() {

	auto res = ResourceNameLoader::GetInstance();
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Register(BT_RESULT_BACK_CUSTOM, 788, 780,res.GetName(PNG_RESULT_TO_CUSTOM));
	ui_mng.Register(BT_RESULT_BACK_SELECT, 1148, 780, res.GetName(PNG_RESULT_TO_SELECT));

	Lib::DrawBoxAlpha(
		"over_ray",
		0, 0,
		Lib::CreateColor(1.f, 1.f, 1.f, 0.3f),
		1920, 1080
	);

	Lib::DrawBox2D(
		res.GetName(PNG_RESULT_WIND),
		463, 193
	);

	Lib::DrawBox2D(
		res.GetName(PNG_RESULT_FRAME_R),
		750, 738);

	Lib::DrawBox2D(
		res.GetName(PNG_RESULT_FRAME_L),
		1108, 738);

	if (m_result == FAILD) {
		Lib::DrawBox2D(
			res.GetName(PNG_RESULT_FAILD),
			648, 300
		);
		Lib::DrawPx2D(
			res.GetName(PNG_RESULT_ROGO_FAILD),
			600, 578,
			700,200);
	}
	else {
		Lib::DrawBox2D(
			res.GetName(PNG_RESULT_CLEAR),
			648, 300);

		Lib::DrawBox2D(
			res.GetName(PNG_RESULT_ROGO_CLEAR),
			600, 578,
			700, 200);
	}
	ui_mng.Draw();
}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

}

