#pragma once

#define WINDOW_H 1920
#define WINDOW_W 1080


void ErrMsg(const char* _msg);

//２次元ヘルパー関数群
struct t_Float2 {

	float m_x, m_y;

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
	//垂直判定
	bool IsVertical(const Vec2& r) const{
	
		float t = (m_x * r.m_y) + (m_y*r.m_x);
		if (t <= 0.0001) {
			return true;
		}
		return false;

	}
	//ベクトルが平行であるか（線上に点があるか）
	bool IsHorizontal(const Vec2& r) const{
		
		float t = (m_x*r.m_x) - (r.m_x*m_y);

		if (t <= 0.0001) {
			//ほぼ０に近いとみなす（floatの為）
			return true;
		}
		 return false;
	}
	//鈍角判定
	bool IsObtuseAngle(const Vec2& r)const{
		
	
	}

};

