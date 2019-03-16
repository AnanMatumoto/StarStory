#include "Lib.h"
#include "SceneManager.h"


// メイン
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Lib::Init(1920, 1080, "StarStory");
	SceneManager* sm = new SceneManager();


	int c = 0;
	while (Lib::ProcessMessage()) {

		Lib::DrawBegin(0xe0e0ff);
		
		sm->Init();
		sm->Update();
		

		Lib::DrawEnd();

	}
	Lib::AppEnd();
	return 0;
}

