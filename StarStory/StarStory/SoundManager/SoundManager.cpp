﻿#include"SoundManager.h"

// コンストラクタ
SoundManager::SoundManager() : m_resource_id(TTITLE_BGM) {

}

// デストラクタ
SoundManager::~SoundManager() {

}

// インスタンス取得
SoundManager &SoundManager::GetInstanse() {

	static SoundManager sound_manager;
	return sound_manager;
}

// サウンドファイルの読み込み
void SoundManager::InitLoadResource() {

	for (int i = 0; i < SoundManager::MAX_RESOURCE_NUM; ++i) {

		RegisterResource(m_resource_id);

		m_resource_id = static_cast<ResourceID>(m_resource_id + 1);
	}
}

// リソースの登録
void SoundManager::RegisterResource(ResourceID id) {

	m_resource[id] = &Lib::AudioClip::GetInterface(Lib::hWnd);

	switch (id) {

	case TTITLE_BGM:

		m_resource_list.push_back((char*)"Resource/Audio/BGM/title_bgm.wav");
		break;

	case GAME_BGM:

		m_resource_list.push_back((char*)"Resource/Audio/BGM/game_main_bgm.wav");
		break;

	case STAR_ACCEL_SE:

		m_resource_list.push_back((char*)"Resource/Audio/SE/star_accel.wav");
		break;

	case STAR_JUMP_SE:

		m_resource_list.push_back((char*)"Resource/Audio/SE/star_jump.wav");
		break;

	case STAR_NORMAL_SE:

		m_resource_list.push_back((char*)"Resource/Audio/SE/star_normal.wav");
		break;

	case STAR_STOP_SE:

		m_resource_list.push_back((char*)"Resource/Audio/SE/star_stop.wav");
		break;

	default:

		m_resource_list.push_back(nullptr);
		break;
	}

	// サウンドファイルの読み込み
	m_resource[id]->LoadWaveFile(m_resource_list[id]);
}

