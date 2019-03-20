#pragma once


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

	SC_TITLE,
	SC_CUSTOM,
	SC_SELECT,
	SC_GAME,
	SC_RESULT,
	SC_END,
	NO_SCENE
};

//=============================
//　シーン基底クラス
//=============================
class SceneBase {

/*
	＜各シーンが継承する基底クラス＞

		Init    : 初期化処理
		Update  : 更新処理
		End     : 終了処理
		Control	: 一連の流れを管理する
	　　Draw	: 描画処理
*/

public:

	SceneBase() {}
	virtual void Init()   = 0;
	virtual void Update() = 0;
	virtual SceneID End() {
		return NO_SCENE;
	}
	virtual SceneID Control() {
		return NO_SCENE;
	}
	virtual void Draw()  = 0;
	virtual ~SceneBase() {};

protected:

	//bool is_clear;	
	int state_id;	//　自身の状態ID
};


