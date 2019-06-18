#include"SoundManager.h"

// コンストラクタ
SoundManager::SoundManager() : m_resource_id(TITLE_BGM) {

	// インターフェース登録
	m_resource = &Lib::AudioClip::GetInterface(Lib::hWnd);
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

	for (int i = 0; i < MAX_RESOURCE_NUM; ++i) {

		// リソースの登録
		RegisterResource(m_resource_id);

		// サウンドファイルの読み込み
		m_resource->LoadWaveFile(m_resource_list[m_resource_id]);

		// サウンドプレイヤー生成
		m_sound.push_back(new Lib::AudioPlayer());

		// enum加算
		m_resource_id = static_cast<SoundResourceID>(m_resource_id + 1);
	}
}

// リソースの登録
void SoundManager::RegisterResource(SoundResourceID id) {

	switch (id) {

	case TITLE_BGM:

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
}

// サウンドプレイヤー
void SoundManager::SoundPlayer(SoundResourceID id, PlayerType type, int volume) {

	// tyoeによって、処理を変える
	switch (type) {

	case PLAY:
		m_sound[id]->Play(m_resource_list[id]);
		m_sound[id]->SetVolume(volume);
		break;

	case LOOP_PLAY:
		m_sound[id]->LoopOnPlay(m_resource_list[id]);
		m_sound[id]->SetVolume(volume);
		break;

	case PAUSE:

		break;

	case STOP:
		m_sound[id]->Stop();
		break;
	}
}

