#pragma once

#include<vector>

#include"../Lib/Lib.h"

class SoundManager {

public:

	// サウンドリソース一覧
	enum ResourceID {

		OP,
		/*----Title----*/
		TTITLE_BGM,
		/*----Title----*/
		/*----Serect----*/
		/*----Serect----*/
		/*----Custom----*/
		/*----Custom----*/
		/*----Game----*/
		GAME_BGM,
		STAR_ACCEL,
		STAR_JUMP,
		STAR_NORMAL,
		STAR_STOP,
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
	void InitResource();

private:

	ResourceID resource_id;

	// リソースの登録
	void RegisterResource(ResourceID id);

	Lib::AudioClip* m_resource[MAX_RESOURCE_NUM];

	// サウンドプレイヤー
	std::vector<Lib::AudioPlayer*> m_sound;
};

