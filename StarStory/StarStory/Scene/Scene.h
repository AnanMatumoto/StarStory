#pragma once

#include "../Scene/ResultScene/ResultID.h"

//==============================
//　状態ID
//==============================
enum SceneState {

	SS_INIT,
	SS_UPDATE,
	SS_END,
};

//=============================
//　シーンID
//=============================
enum SceneID {

	NO_SCENE,
	SC_TITLE,
	SC_CUSTOM,
	SC_SELECT,
	SC_GAME,
	SC_RESULT,
	SC_END,
};

//=============================
//　シーン基底クラス
//=============================
class SceneBase {

//＜各シーンが継承する基底クラス＞

public:

	SceneBase() {}

	/*
	Init:
		シーン初期化処理
	*/
	virtual void Init()   = 0;
	
	/*
	Update:
		シーンの更新処理
	*/
	virtual void Update() = 0;
	
	/*
	End:
		シーンの終了処理
	*/
	virtual SceneID End() {
		return NO_SCENE;
	}

	/*
	Control:
		初期化から終了までの処理を
		m_state_id により遷移する
	*/
	virtual SceneID Control() {
		return NO_SCENE;
	}

	/*
	Draw:
		シーンの描画処理
	*/
	virtual void Draw()  = 0;

	/*
	SetResult:
		リザルト結果をセットする
	*/
	void SetResult(ResultID result) {
		m_result = result;
	}

	/*
	GetResult:
		リザルト結果を取得する
	*/
	const ResultID GetResult()const {
		return m_result;
	}

	//デストラクタ
	virtual ~SceneBase() {};


protected:

	int m_state_id;		//　自身の状態ID
	ResultID m_result;  //  リザルト結果保存変数
};


