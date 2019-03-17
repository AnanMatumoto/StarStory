#include "Lib/Lib.h"
#include "Scene/SceneManager.h"


// メイン
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Lib::Init(1920, 1080, "StarStory");
	SceneManager* sm = new SceneManager();
	sm->Init();

	int c = 0;
	while (Lib::ProcessMessage()) {

		Lib::KeyUpdate();
		
		//　描画開始
		Lib::DrawBegin(0xe0e0ff);
		
	
		sm->Update();
		
		//　描画終了
		Lib::DrawEnd();

	}
	Lib::AppEnd();
	return 0;
}

