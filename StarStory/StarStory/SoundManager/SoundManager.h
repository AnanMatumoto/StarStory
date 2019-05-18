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

	/*----初期化関数----*/
	// サウンドファイルの読み込み
	void InitLoadResource();
	/*----初期化関数----*/

	/*----更新関数----*/
	// 
	
	/*----更新関数----*/

private:
	/*----vector----*/
	// リソース管理
	std::vector<char*> m_resource_list;

	// サウンドプレイヤー
	std::vector<Lib::AudioPlayer*> m_sound;
	/*----vector----*/

	/*----変数----*/
	// サウンドファイル読み込み用
	Lib::AudioClip* m_resource;
	/*----変数----*/

	/*----関数----*/
	// リソースの登録
	void RegisterResource(ResourceID id);
	/*----関数----*/

	/*----enum----*/
	// リソース一覧
	ResourceID m_resource_id;
	/*----enum----*/
};

