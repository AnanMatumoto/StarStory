#pragma once

#define WINDOW_W 1920
#define WINDOW_H 1080


void ErrMsg(const char* _msg);

//２次元ヘルパー関数群
struct t_Float2 {

	float x, y;

	t_Float2() {};

	t_Float2(float _x, float _y);

	t_Float2 operator + (const t_Float2& r);

	t_Float2 operator - (const t_Float2& r);
	
	t_Float2 operator * (const t_Float2& r);

	t_Float2 operator * (float r)const;

	t_Float2 operator / (const t_Float2& r);

	t_Float2 operator / (float r) const;

	~t_Float2() {};
};

//t_Float2を点として再定義
typedef t_Float2 Point2D;

//2Dベクトル構造体（点にも使える）
struct Vec2 : public t_Float2 {

	Vec2(){}
	Vec2(float x_, float y_) :t_Float2(x_, y_){}
	//コピーコンストラクタ
	Vec2(const t_Float2& r) :t_Float2(r){}

	//点（ポイント）を持つベクトルを作りたいとき
	Vec2 operator = (const t_Float2& r);
	
	/* 
	   外積計算（線と点の当たりを数値で返す）

	   戻り値：０以上なら線の進行方向に対して右側
	   　　　  ０以下なら線の進行方向に対して左側

	*/
	float Cross(Vec2 v1, Vec2 v2, Vec2 point);

};

