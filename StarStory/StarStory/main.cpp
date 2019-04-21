#include "Lib/Lib.h"
#include "Scene/SceneManager.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

// メイン
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	Lib::Init(1920, 1080, "StarStory");
	SceneManager::GetInstance().Init();

	while (Lib::ProcessMessage()) {

		Lib::KeyUpdate();
		
		//　描画開始
		Lib::DrawBegin(0xe0e0ff);
		
	
		SceneManager::GetInstance().Update();
		if (SceneManager::GetInstance().IsQuitWindow()) {
			return 0;
		}


		//　描画終了
		Lib::DrawEnd();

	}
	Lib::AppEnd();

	return 0;
}
