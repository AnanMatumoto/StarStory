#pragma once

#include<vector>

#include"../Lib/Lib.h"

class SoundManager {

public:

	// サウンドリソース一覧
	enum ResourceID {

		//OP,
		/*----Title----*/
		TTITLE_BGM,
		/*----Title----*/
		/*----Serect----*/
		/*----Serect----*/
		/*----Custom----*/
		/*----Custom----*/
		/*----Game----*/
		GAME_BGM,
		STAR_ACCEL_SE,
		STAR_JUMP_SE,
		STAR_NORMAL_SE,
		STAR_STOP_SE,
		/*----Game----*/
		/*----Result----*/
		/*----Result----*/

		MAX_RESOURCE_NUM
	};

public:

	SoundManager();		// コンストラクタ
	~SoundManager();	// デストラクタ

	static SoundManager &GetInstanse();

	/*
	// サウンドの再生
	sound = new Lib::AudioPlayer();
	sound->Play("Resource/Audio/BGM/title_bgm.wav");
	*/

	// 
	void InitLoadResource();

private:

	ResourceID m_resource_id;

	// リソースの登録
	void RegisterResource(ResourceID id);

	// リソース管理
	std::vector<char*> m_resource_list;

	// サウンドファイル読み込み用変数
	Lib::AudioClip* m_resource[MAX_RESOURCE_NUM];

	// サウンドプレイヤー
	std::vector<Lib::AudioPlayer*> m_sound;


};

