#include "Lib.h"



//　以下テスト用
#define IMG_BACK "Resource/test_image/back_sample.jpg"
#define IMG_PLYR "Resource/test_image/Player.jpg"

void BackGraund() {

	Lib::DrawPx2D(
		IMG_BACK,
		0, 0,
		1920, 1080
	);

}

class Player {

public:
	void PlayerUpdate() {
		
		++flame;
		
		/*Lib::DrawTriangle2D(
			"Player.jpg",
			vtx,
			x, y
		);*/

		Lib::RotTriangle2D(
			IMG_PLYR,
			flame,
			x, y,
			128,128
			);
	}
	float x=500, y =500;
	Vertex vtx[3];
	int flame = 0;

	Player() {}
	~Player(){}
};

// メイン
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Lib::Init(1920, 1080, "StarStory");
	Player p;

	int c = 0;
	while (Lib::ProcessMessage()) {

		Lib::DrawBegin(0xe0e0ff);

		Lib::GetPoint(&p.x, &p.y);

		BackGraund();
		p.PlayerUpdate();
		Lib::DrawEnd();

	}
	Lib::AppEnd();
	return 0;
}