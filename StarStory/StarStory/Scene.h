#pragma once

namespace Scene {

	extern int g_StateID;
	extern int g_SceneID;
};

//================================
//　状態ID
//=================================
enum SceneState {

	SS_INIT,
	SS_UPDATE,
	SS_END,
};

//===================================
//　シーンID
//===================================
enum SceneID {

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

	/*
	各シーンが継承する基底クラス
	Init  : 初期化処理
	Update: 更新処理
	End   : 終了処理
	Control	   : 一連の流れを管理する
*/

public:

	SceneBase() {}
	virtual void Init() {}
	virtual void Update() {}
	virtual void End() {}
	virtual void Control() {}
	virtual void Draw() {}
	~SceneBase() {}

protected:

	bool is_clear;
};

//==================================
// タイトル画面クラス
//==================================

class TitleScene : public SceneBase {

private:

	void Init()override;
	void Update()override;
	void End()override;
	void Control() override;
	void Draw()override;
	~TitleScene() {}
};

//==================================
//	ステージセレクト画面クラス
//==================================


class SelectScene : public SceneBase {

private:

	void Init()override;
	void Update()override;
	void End()override;
	void Control()override;
	void Draw() override;
	~SelectScene() {}
};

//=================================
//  カスタム画面クラス
//=================================

class CustomScene :public SceneBase {

private:

	void Init()override;
	void Update() override;
	void End() override;
	void Control() override;
	void Draw() override;
	~CustomScene() {}

};

//=================================
//　ゲーム画面クラス
//=================================

class GameScene : public SceneBase {

private:
	void Init() override;
	void Update()override;
	void End()override;
	void Control() override;
	void Draw() override;
	~GameScene() {}
	//StageBase* stage;
};


//=================================
// リザルト画面クラス
//=================================

class ResultScene : public SceneBase {

private:
	void Init() override;
	void Update() override;
	void End() override;
	void Control() override;
	void Draw() override;
	~ResultScene() {}

};