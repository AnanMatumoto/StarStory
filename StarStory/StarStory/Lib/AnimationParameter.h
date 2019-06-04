#pragma once

#include "../Common/Common.h"
#include <string>
//====================================
// アニメーション用パラメーター
//====================================

struct  AnimationParameter
{
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

	void SetParameter(
		int anim_length,
		int anim_speed,
		Vec2 ofset_,
		std::string effect_name_
	) {
		length = anim_length;
		speed = anim_speed;
		ofset = ofset_;
		name = effect_name_;
	}


	int   length;			//アニメーションの長さ
	int   speed;			//アニメーション速度
	Vec2  ofset;				//描画位置
	std::string name;	//エフェクト名


};