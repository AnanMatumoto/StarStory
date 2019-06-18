#pragma once

#include<vector>

#include"../../Lib/Lib.h"

// サウンドリソース一覧
enum SoundResourceID {

	//OP,
	/*----Title----*/
	TITLE_BGM,
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

	MAX_RESOURCE_NUM
};

/*	[現状の使い方]
	
	1, SoundResourceIDにIDを追加する

	2, RegisterResourceの中にリソースを追加していく

	3, SoundPlayer(リソースID,プレイヤーの種類,ボリューム);
*/

// サウンドマネージャー
class SoundManager {

public:

	// サウンドプレイヤーの種類
	enum PlayerType {

		PLAY,			// 再生
		LOOP_PLAY,		// ループ再生
		PAUSE,			// 一時停止
		STOP			// 停止
	};

public:

	// インスタンス取得
	static SoundManager &GetInstanse();

	/*----初期化関数----*/
	// サウンドファイルの読み込み
	void InitLoadResource();
	/*----初期化関数----*/

	/*----更新関数----*/
	// サウンドプレイヤー
	void SoundPlayer(SoundResourceID id, PlayerType type, int volume = 0);
	/*----更新関数----*/

private:

	SoundManager();		// コンストラクタ
	~SoundManager();	// デストラクタ

	/*----vector----*/
	// リソース管理
	std::vector<char*> m_resource_list;

	// サウンドプレイヤー
	std::vector<Lib::AudioPlayer*> m_sound;
	//Lib::AudioPlayer* m_sound;
	/*----vector----*/

	/*----変数----*/
	// サウンドファイル読み込み用
	Lib::AudioClip* m_resource;
	/*----変数----*/

	/*----関数----*/
	// リソースの登録
	void RegisterResource(SoundResourceID id);
	/*----関数----*/

	/*----enum----*/
	// リソース一覧
	SoundResourceID m_resource_id;
	/*----enum----*/
};

