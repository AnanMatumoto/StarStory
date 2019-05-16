#include"SoundManager.h"

// コンストラクタ
SoundManager::SoundManager() : resource_id(OP) {

}

// デストラクタ
SoundManager::~SoundManager() {

}

// 
SoundManager &SoundManager::GetInstanse() {

	static SoundManager sound_manager;
	return sound_manager;
}

// サウンドファイルの読み込み
void SoundManager::InitResource() {

	for (int i = 0; i < SoundManager::MAX_RESOURCE_NUM; ++i) {

		RegisterResource(resource_id);

		resource_id = static_cast<ResourceID>(resource_id + 1);
	}
}

// リソースの登録
/*
	サウンドの定数名を決めて、音を入れておく
*/
void SoundManager::RegisterResource(ResourceID id) {

	Lib::AudioClip& resource = m_resource[id]->GetInterface(Lib::hWnd);

	m_resource[id] = &resource.GetInterface(Lib::hWnd);

	switch (id) {

	case TTITLE_BGM:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/title_bgm.wav");
		break;

	case GAME_BGM:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/game_main_bgm.wav");
		break;

	case STAR_ACCEL:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/star_accel.wav");
		break;

	case STAR_JUMP:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/star_jump.wav");
		break;

	case STAR_NORMAL:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/star_normal.wav");
		break;

	case STAR_STOP:

		m_resource[id]->LoadWaveFile("Resource/Audio/BGM/star_stop.wav");
		break;

	default:


		break;
	}
}

