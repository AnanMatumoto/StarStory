#include "SceneManager.h"
#include "../TitleScene/TitleScene.h"
#include "../CusutomScene/CustomScene.h"
#include "../SelectScene/SelectScene.h"
#include "../GameScene/GameScene.h"
#include "../ResultScene/ResultScene.h"
#include "../../ResourceNameLoader/ResourceNameLoader.h"
//---------------------------------
//インスタンス取得
SceneManager& SceneManager::GetInstance() {
	static SceneManager sm;
	return sm;
}

//--------------------------------
//  シーン初期化
void SceneManager::Init(SceneID id) {
	
	ResourceNameLoader::GetInstance().EntryResourceName();

	//シーンの登録
	scene_list.emplace(SC_TITLE,  new TitleScene());
	scene_list.emplace(SC_CUSTOM, new CustomScene());
	scene_list.emplace(SC_SELECT, new SelectScene());
	scene_list.emplace(SC_GAME,   new GameScene());
	scene_list.emplace(SC_RESULT, new ResultScene());

	/*----スキルID初期化----*/
	std::fstream file[5];

	Skill_Data skill_data{ Skill::NORMAL,SoundResourceID::STAR_NORMAL_SE,"Resource/Player/player_1_normal.png" };
	for (int i = 0; i < 5; ++i) {

		std::string dat = "./Resource/skill_data_0";
		dat += std::to_string(i + 1);
		dat += ".dat";

		file[i].open(dat, std::ios::binary | std::ios::out);
		file[i].write((char*)&skill_data, sizeof(Skill_Data));
		file[i].close();
	}
	/*----スキルID初期化----*/

	//初期設定でタイトルをセットする
	m_now_id = id;
	m_scene = scene_list[m_now_id];
}

//---------------------------------
//　シーン更新
void SceneManager::Update() {

	SceneID scene_id;

	scene_id = m_scene->Control();
	ChangeScene(scene_id);
}

//-------------------------------------
//　シーン遷移
void SceneManager::ChangeScene(SceneID scene_id) {
	
	if (scene_id != m_now_id) {
		//現在のシ―ンが終了に差しかかった時
		m_now_id = scene_id;
	}
	auto it = scene_list.find(m_now_id);
	m_scene = it->second;
}

//---------------------------------------
//　現行シーンを取得する
SceneBase* SceneManager::GetScene() {
	return m_scene;
}

//--------------------------------------
//　ウィンドウ終了フラグゲッター
void SceneManager::SetQuit(bool has_quit) {
	m_is_quit = has_quit;
}

//--------------------------------------
//シーン終了処理
bool SceneManager::GetQuitWindow() {
	return m_is_quit;
}

//--------------------------------------
//　デストラクタ
SceneManager::~SceneManager() {

	std::fstream file[5];

	Skill_Data skill_data{ Skill::NORMAL,SoundResourceID::STAR_NORMAL_SE,"Resource/Player/player_1_normal.png" };
	for (int i = 0; i < 5; ++i) {

		std::string dat = "./Resource/skill_data_0";
		dat += std::to_string(i + 1);
		dat += ".dat";

		file[i].open(dat, std::ios::binary | std::ios::out);
		file[i].write((char*)&skill_data, sizeof(Skill_Data));
		file[i].close();
	}
	/*file[0].open("./Resource/skill_data_01.dat", std::ios::binary | std::ios::out);
	file[0].write((char*)&skill_data, sizeof(Skill_Data));
	file[0].close();

	file[1].open("./Resource/skill_data_02.dat", std::ios::binary | std::ios::out);
	file[1].write((char*)&skill_data, sizeof(Skill_Data));
	file[1].close();

	file[2].open("./Resource/skill_data_03.dat", std::ios::binary | std::ios::out);
	file[2].write((char*)&skill_data, sizeof(Skill_Data));
	file[2].close();

	file[3].open("./Resource/skill_data_04.dat", std::ios::binary | std::ios::out);
	file[3].write((char*)&skill_data, sizeof(Skill_Data));
	file[3].close();

	file[4].open("./Resource/skill_data_05.dat", std::ios::binary | std::ios::out);
	file[4].write((char*)&skill_data, sizeof(Skill_Data));
	file[4].close();*/

	//リスト内の破棄
	for (auto & it : scene_list) {
		delete it.second;
	}
}


