#include "GameScene.h"
#include "SceneManager.h"
#include "../Lib/Lib.h"
#include "../StageObject/ObjectManager.h"
#include "../StageObject/StarObject.h"
#include "../UI/UIManager.h"

#define TEX_SPEED  "Resource/Player/player_1_accel.png"
#define TEX_JUMP   "Resource/Player/player_1_jump.png"
#define TEX_LIGNHT "Resource/Player/player_1_light.png"
#define TEX_NOMAL  "Resource/Player/player_1_normal.png"
#define TEX_STOP   "Resource/Player/player_1_stop.png"

#define GAME_BACK   "Resource/Game/UI_stage.png"
#define GAME_STAGE  "Resource/Game/stage1_background.png"
#define GAME_UI_WND "Resource/Game/UI_stage_window.png"
#define GAME_CUSTOM "Resource/Game/UI_stage_custom.png"
#define GAME_STOP   "Resource/Game/UI_stage_sign.png"
#define GAME_ONOFF  "Resource/Game/UI_stage_skill.png"

//-------------------------------------------
//　ゲームシーン初期化
void GameScene::Init() {
	m_state_id = SS_UPDATE;
	//stage = new StageBase();

	// ToDo:スキル読み込み

	ObjectManager& mng = ObjectManager::GetInstance();
	UIManager & UImng = UIManager::GetInstance();

    //ステージオブジェクトの登録
	mng.Register(OBJ_TEST1, 0, 700);
	mng.Register(STAR_OBJ, 90, 600);
	mng.Register(STAR_CHILD1,   0,  0, SPEED,  TEX_SPEED,   0);
	mng.Register(STAR_CHILD2,  30, 23,   JUMP, TEX_JUMP,   72);
	mng.Register(STAR_CHILD3,  19, 60, NORMAL, TEX_NOMAL, 144);
	mng.Register(STAR_CHILD4, -19, 60, NORMAL, TEX_NOMAL, 216);
	mng.Register(STAR_CHILD5, -30, 23, NORMAL, TEX_NOMAL, 288);

	//UIの登録
	UImng.Register(BT_GM_WIND, 20, 50, GAME_UI_WND);
	UImng.Register(BT_GM_TOCUSTOM, 60,66,GAME_CUSTOM);
	UImng.Register(BT_GM_STOP, 250, 66, GAME_STOP );
	UImng.Register(BT_GM_ONOFF, 350, 66,GAME_ONOFF );

}

//------------------------------------------
//　ゲームシーン更新
void GameScene::Update() {

	// ステージオブジェクト更新
	ObjectManager::GetInstance().Update();
	UIManager& ui_mng = UIManager::GetInstance();
	ui_mng.Update();

	if (Lib::KeyPress(VK_SPACE))
	{
		m_state_id = SS_END;
	}

}

//------------------------------------------
//　ゲームシーン終了
SceneID GameScene::End() {

	/*if (stage->IsClear()) {
		is_clear = true;
	}*/
	m_state_id = SS_INIT;

	//UIをリストから削除
	UIManager::GetInstance().Delete(BT_GM_WIND);
	UIManager::GetInstance().Delete(BT_GM_TOCUSTOM);
	UIManager::GetInstance().Delete(BT_GM_STOP);
	UIManager::GetInstance().Delete(BT_GM_ONOFF);
	

	return SC_RESULT;
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

	
	Lib::DrawBox2D(
		GAME_BACK,
		0, 0
	);

	Lib::DrawBox2D(
		GAME_STAGE,
		0, 30
	);
	
	// ステージオブジェクト描画
	ObjectManager::GetInstance().Draw();
	UIManager::GetInstance().Draw();

}

//-----------------------------------------
// デストラクタ
GameScene::~GameScene() {

	// オブジェクトの削除
	ObjectManager::GetInstance().AllDelete();
}