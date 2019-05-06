#include "Lib.h"


#pragma comment(lib,"dxguid.lib")
#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "winmm.lib")

namespace Lib {

	//===============================================
	//	オーディオリソース管理
	//===============================================

	//----------------------------------------------
	// インスタンス
	 AudioClip& AudioClip::GetInterface(HWND hwnd) {
		static AudioClip clip(hwnd);
		return clip;
	 }

	 //--------------------------------------------
	 //　初回呼び出し用コンストラクタ
	 AudioClip::AudioClip(HWND hwnd) {

		 DirectSoundCreate8(nullptr, &m_ds8, nullptr);
		 m_ds8->SetCooperativeLevel(hwnd, DSSCL_NORMAL);

		 DSBUFFERDESC desc;
		 desc.dwSize          = sizeof(DSBUFFERDESC);
		 desc.dwFlags         = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
		 desc.dwBufferBytes   = 0;
		 desc.dwReserved      = 0;
		 desc.lpwfxFormat     = nullptr;
		 desc.guid3DAlgorithm = GUID_NULL;

		 m_ds8->CreateSoundBuffer(&desc, &m_prim_buf, nullptr);
	}
	//-------------------------------------
	//　データ読み込み
	IDirectSoundBuffer8* AudioClip::LoadWaveFile(std::string file_name){
		
		//既にリストに登録されている場合
		auto file = m_list.find(file_name);
		if (file != m_list.end()) {
			return file->second;
		}

		HMMIO hmmio = nullptr;
		MMIOINFO mminfo = {};
		hmmio = mmioOpen((LPSTR)file_name.c_str(), &mminfo, MMIO_READ);
		
		//ファイルのオープンに失敗した場合
		if (!hmmio) {
			ErrMsg("waveファイルのオープンに失敗");
			return nullptr;
		}

		MMRESULT result;
		MMCKINFO rif_chunk;
		rif_chunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		result = mmioDescend(hmmio, &rif_chunk, NULL, MMIO_FINDRIFF);
		
		//　リフチャンクの検索に失敗した場合
		if (result != MMSYSERR_NOERROR) {
			mmioClose(hmmio, 0);
			return nullptr;
		}

		MMCKINFO fmt_chunk;
		fmt_chunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
		result = mmioDescend(hmmio, &fmt_chunk, &rif_chunk, MMIO_FINDCHUNK);
		
		// フォーマットチャンクの検索に失敗した場合
		if (result != MMSYSERR_NOERROR) {
			mmioClose(hmmio, 0);
			return nullptr;
		}

		//音質やチャンネル数の情報を格納する
		WAVEFORMATEX format;
		DWORD fmsize = fmt_chunk.cksize;
		if (mmioRead(hmmio, (HPSTR)&format, fmsize) != fmsize) {
			mmioClose(hmmio, 0);
			return nullptr;
		}

		//データ検索の為一度戻る
		mmioAscend(hmmio, &fmt_chunk, 0);
		
		MMCKINFO data_chunk;
		data_chunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
		result = mmioDescend(hmmio, &data_chunk, &rif_chunk, MMIO_FINDCHUNK);
		// データチャンクの検索に失敗した場合
		if (result != MMSYSERR_NOERROR) {
			mmioClose(hmmio, 0);
			return nullptr;
		}

		// 波形データ
		DWORD data_size = data_chunk.cksize;
		BYTE* wav_data = new BYTE[data_chunk.cksize];
		if (mmioRead(hmmio, (HPSTR)wav_data, data_chunk.cksize) != data_chunk.cksize) {
			delete wav_data;
			return nullptr;
		}


		//正常読み込み
		mmioClose(hmmio, 0);

		// セカンダリバッファの設定
		DSBUFFERDESC desc = {};
		desc.dwSize = sizeof(DSBUFFERDESC);
		desc.dwFlags= DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS |
					  DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
		desc.dwBufferBytes = data_size;   //メモリサイズ
		desc.dwReserved	   = 0;			  //予約域
		desc.lpwfxFormat   = &format;     //WAVEフォーマット
		desc.guid3DAlgorithm = GUID_NULL; //3Dエフェクトを使用しない

		IDirectSoundBuffer*  buf = 0;
		IDirectSoundBuffer8* buf8;
		m_ds8->CreateSoundBuffer(&desc, &buf, nullptr);

		//戻り値がIDirectSoundBufferの為、IDirectSoundBuffer8に戻す
		buf->QueryInterface(IID_IDirectSoundBuffer8,(void**)&buf8);
		buf->Release();


		// WAVデータ書き込み
		LPVOID write_data;
		DWORD len;
		buf8->Lock(
			0,		     	//ロック開始位置
			0,			    //メモリサイズ
			&write_data,	//ロック位置のポインタ
			&len,		    //大きさ
			NULL,	  	    //範囲を超えた場合のメモリ領域指定
			NULL,		
			DSBLOCK_ENTIREBUFFER //指定の大きさだけロックする
		);
		
		memcpy(write_data, wav_data, len);
		buf8->Unlock(write_data, len, nullptr, 0);
		//　元音源を削除
		delete[] wav_data;

		m_list.emplace(file_name, buf8);
		
		return buf8;
	}


	//-------------------------------------
	// リソースを取得する
	IDirectSoundBuffer8* AudioClip::GetResourcre(std::string name) {

		auto file = m_list.find(name);
		if (file != m_list.end()) {
			IDirectSoundBuffer8* sb = file->second;
			return sb;
		}
		return nullptr;
	}

	//-----------------------------------
	//　デストラクタ
	AudioClip::~AudioClip() {

		for (auto& file : m_list) {
			while (file.second->Release() != 0);
		}
		m_ds8->Release();
	}


	//==========================================
	//  サウンドプレーヤー
	//==========================================
	
	//------------------------------------
	// 再生
	void AudioPlayer::Play(std::string sound_name) {
		
		AudioClip& clip = AudioClip::GetInterface();
		m_sec_buf = clip.GetResourcre(sound_name);
		m_sec_buf->SetVolume(-1000);
		m_sec_buf->Play(0, 0, 0);
		m_sec_buf->SetCurrentPosition(0);
	}

	//----------------------------------
	// ループ再生
	void AudioPlayer::LoopOnPlay(std::string sound_name) {

		AudioClip& clip = AudioClip::GetInterface();
		m_sec_buf = clip.GetResourcre(sound_name);
		m_sec_buf->SetVolume(-1000);
		m_sec_buf->Play(0, 0, DSBPLAY_LOOPING);
	}

	//----------------------------------
	// 停止
	void AudioPlayer::Stop() {

		m_sec_buf->Stop();
	}

	//----------------------------------
	// ボリューム調整
	void AudioPlayer::SetVolume(int volume) {

		m_sec_buf->SetVolume(volume);
	}

	//----------------------------------
	// デストラクタ
	AudioPlayer::~AudioPlayer() {
		m_sec_buf->Release();
	}
}