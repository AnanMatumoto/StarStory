#pragma once

#include "../Common/Common.h"
#include <string>
//====================================
// アニメーション用パラメーター
//====================================

struct  AnimationParameter
{
	//コンストラクタ
	AnimationParameter() {
		length = 0;
		speed = 0;
		ofset = { 0,0 };
		name = "none";
    }

	AnimationParameter(const AnimationParameter& param) {
		
		this->length = param.length;
		this->speed = param.speed;
		this->ofset = param.ofset;
		this->name = param.name;
	}

	/*
	UVアニメーションのパラメーターセット
	引数：
	　　anim_length (アニメーション枚数のの長さ)
	  　anim_speed  (アニメーション速度)
	    ofset       (描画位置x,y座標)
		anim_name   (アニメーション画像名)
	*/
	void SetParameter(
		int anim_length,
		int anim_speed,
		Vec2 ofset_,
		std::string anim_name_
	) {
		length = anim_length;
		speed = anim_speed;
		ofset = ofset_;
		name = anim_name_;
	}


	int   length;			//アニメーションの長さ
	int   speed;			//アニメーション速度
	Vec2  ofset;				//描画位置
	std::string name;	//エフェクト名


};