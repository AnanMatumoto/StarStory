#pragma once

#include"../DiamondBase/DiamondBase.h"

// ひし形クラス
class Diamond :public DiamondBase {
public:
	// コンストラクタ
	Diamond(DiamondPart part, std::string data_file);
private:
	/*----初期化----*/
	// 各ひし形の頂点の座標
	void InitVertexPos();
	// 各ひし形の座標(中心のx,y)と角度を初期化
	void InitDiamondInfo(DiamondPart part);
	// スキルIDをバイナリファイルから読み込む
	void InitSkillID(std::string data_file);
	/*----初期化----*/
private:
	/*----更新----*/
	// 更新
	void Update()override;
	// スキルIDによって、画像を変更
	void UpdateSkillID();
	/*----更新----*/
private:
	/*----描画----*/
	// 描画
	void Draw()override;
	// ひし形のスキルを判定して描画画像を変える
	void ChangeTex();
	/*----描画----*/
private:
	/*----削除----*/
	// デストラクタ
	~Diamond()override;
	/*----削除----*/
private:
	/*--定数--*/
	/*--ひし形の各座標、角度--*/
	// TOPの初期座標(x,y)と角度
	static const float TOP_POS_X;
	static const float TOP_POS_Y;
	static const float TOP_ANGLE;
	// TOP_RIGHTの初期座標(x,y)と角度
	static const float TOP_RIGHT_POS_X;
	static const float TOP_RIGHT_POS_Y;
	static const float TOP_RIGHT_ANGLE;
	// TOP_LEFTの初期座標(x,y)と角度
	static const float TOP_LEFT_POS_X;
	static const float TOP_LEFT_POS_Y;
	static const float TOP_LEFT_ANGLE;
	// BOTTOM_RIGHTの初期座標(x,y)と角度
	static const float BOTTOM_RIGHT_POS_X;
	static const float BOTTOM_RIGHT_POS_Y;
	static const float BOTTOM_RIGHT_ANGLE;
	// BOTTOM_LEFTの初期座標(x,y)と角度
	static const float BOTTOM_LEFT_POS_X;
	static const float BOTTOM_LEFT_POS_Y;
	static const float BOTTOM_LEFT_ANGLE;
	/*--ひし形の各座標、角度--*/
	/*--定数--*/
};

