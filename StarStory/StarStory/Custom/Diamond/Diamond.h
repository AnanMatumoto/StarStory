#pragma once

#include"../DiamondBase/DiamondBase.h"

// ひし形クラス
class Diamond :public DiamondBase {

public:
	// コンストラクタ
	Diamond(DiamondPart part, std::string data_file);

	// デストラクタ
	~Diamond()override;

	/*----関数----*/
	void Update()override;		// 更新

	void Draw()override;		// 描画
	/*----関数----*/

	/*----ゲッター----*/
	Skill_Data GetSkillDara();		// スキルデータを外部ファイルに保存する用
	/*----ゲッター----*/

private:
	/*----初期化関数----*/
	// 各ひし形の頂点の座標
	void InitVertexPos();

	// 各ひし形の座標(中心のx,y)と角度を初期化
	void InitDiamondInfo(DiamondPart part);

	// スキルIDの
	void InitSkillID(std::string data_file);
	/*----初期化関数----*/

	/*----更新用関数----*/
	// スキルIDを変更する関数
	void ChangeSkillID();

	// ひし形のスキルを判定して描画画像を変える
	void ChangeTex();
	/*----更新用関数----*/

private:
	/*--定数--*/
	/*--ひし形の各座標、角度--*/
	// TOPの初期座標(x,y)と角度
	const float TOP_POS_X = 632.f;
	const float TOP_POS_Y = 275.f;
	const float TOP_ANGLE = 0.f;

	// TOP_RIGHTの初期座標(x,y)と角度
	const float TOP_RIGHT_POS_X = TOP_POS_X + 99.f;
	const float TOP_RIGHT_POS_Y = TOP_POS_Y + 72.f;
	const float TOP_RIGHT_ANGLE = TOP_ANGLE + 1.26f;

	// TOP_LEFTの初期座標(x,y)と角度
	const float TOP_LEFT_POS_X = TOP_POS_X - 99.f;
	const float TOP_LEFT_POS_Y = TOP_POS_Y + 72.f;
	const float TOP_LEFT_ANGLE = TOP_ANGLE - 1.26f;

	// BOTTOM_RIGHTの初期座標(x,y)と角度
	const float BOTTOM_RIGHT_POS_X = TOP_POS_X + 61.f;
	const float BOTTOM_RIGHT_POS_Y = TOP_POS_Y + 189.f;
	const float BOTTOM_RIGHT_ANGLE = TOP_ANGLE + 2.51f;

	// BOTTOM_LEFTの初期座標(x,y)と角度
	const float BOTTOM_LEFT_POS_X = TOP_POS_X - 61.f;
	const float BOTTOM_LEFT_POS_Y = TOP_POS_Y + 189.f;
	const float BOTTOM_LEFT_ANGLE = TOP_ANGLE - 2.51f;
	/*--ひし形の各座標、角度--*/
	/*--定数--*/
};

