#pragma once

#include"../DiamondBase/DiamondBase.h"

/*----画像----*/
#define NORMAL_TEX "Resource/Player/player_1_normal.png"	// NORMAL
#define SPEED_TEX  "Resource/Player/player_1_accel.png"		// SPEED
#define JUMP_TEX   "Resource/Player/player_1_jump.png"		// JUMP
#define LIGHT_TEX  "Resource/Player/player_1_light.png"		// LIGHT
#define STOP_TEX   "Resource/Player/player_1_stop.png"		// STOP
/*----画像----*/

/*--定数--*/
/*--ひし形の各座標、角度--*/
// TOPの初期座標(x,y)と角度
const float TOP_POS_X = 632.f;
const float TOP_POS_Y = 282.f;
const float TOP_ANGLE = 0.f;

// TOP_RIGHTの初期座標(x,y)と角度
const float TOP_RIGHT_POS_X = TOP_POS_X + 100.f;
const float TOP_RIGHT_POS_Y = TOP_POS_Y + 72.f;
const float TOP_RIGHT_ANGLE = TOP_ANGLE + 1.25f;

// TOP_LEFTの初期座標(x,y)と角度
const float TOP_LEFT_POS_X = TOP_POS_X - 100.f;
const float TOP_LEFT_POS_Y = TOP_POS_Y + 72.f;
const float TOP_LEFT_ANGLE = TOP_ANGLE - 1.25f;

// BOTTOM_RIGHTの初期座標(x,y)と角度
const float BOTTOM_RIGHT_POS_X = TOP_POS_X + 92.f;
const float BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 287.f;
const float BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.51f;

// BOTTOM_LEFTの初期座標(x,y)と角度
const float BOTTOM_LEFT_POS_X = TOP_POS_X - 92.f;
const float BOTTOM_LEFT_POS_Y = TOP_POS_Y + 287.f;
const float BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.51f;
/*--ひし形の各座標、角度--*/
/*--定数--*/

// ひし形クラス
class Diamond :public DiamondBase {

public:
	// コンストラクタ
	Diamond(DiamondPart part);

	// デストラクタ
	~Diamond()override;

	/*----関数----*/
	void Update()override;		// 更新

	void Draw()override;		// 描画
	/*----関数----*/

	// スキルの受け渡しに使う予定
	/*----セッター----*/
	Skill SetSkill(Skill skill) {

		m_skill_id = skill;
	}
	/*----セッター----*/

private:
	/*----初期化関数----*/
	// 各ひし形の頂点の座標
	void InitVertexPos();

	// 各ひし形の座標(中心のx,y)と角度を初期化
	void InitDiamondInfo();
	/*----初期化関数----*/

	/*----更新用関数----*/
	// クリックされた時の当たり判定
	void IsHitMouse()override;

	// ひし形のスキルを判定して描画画像を変える
	void ChangeTex();
	/*----更新用関数----*/

	/*----描画用関数----*/
	// ひし形の描画
	void DrawDiamond()override;
	/*----描画用関数----*/

	/*----変数----*/
	Lib::Texture m_tex;		// ひし形の描画場が画像を入れるところ
	/*----変数----*/
};

