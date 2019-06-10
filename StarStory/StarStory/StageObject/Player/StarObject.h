#pragma once
#include "../../Common/Common.h"
#include "../../Lib/AnimationParameter.h"
#include "../ObjectBase.h"
#include "../../Skill.h"
#include <vector>

class StarChild;
class MapObject;

//=================================
// 星オブジェクト親クラス
//=================================

class StarObject : public ObjectBase{

public:
	StarObject(float x, float y, float rot);
	~StarObject()override{}

private:

	// 更新処理
	void Update()override;

	//描画処理
	void Draw()override;
	
	//頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	
	//自動操作
	void AutomaticMove();

	/*
		マップオブジェクトの範囲内かを確認する

		第1：マップオブジェクト
		第2：子オブジェクト

	（マップオブジェクトの範囲外ならスキルフラグをOFF）

	*/
	void CheckOutSideTheMapObject(
		MapObject* map,
		StarChild* hit_child
	);

	/*
		スキル発動処理
	
		引数：スキルID

		（スキルIDで各処理を実行）
	*/
	void CauseToSkill(int skill_id);


	/*
		スキルごとのエフェクト描画
		
		引数：　スキルID
		
		（スキルIDと対応するエフェクトを描画）
	*/
	//void DrawSkillEffect(int skill_id);

	void ChangeHitChild(StarChild* skill);

	void ResetParameter();

	//-----------------------------
	//スキルモーション
	//-----------------------------

	// 移動量を追加する
	void AddForce(
		float vel_x = 0.f, float vel_y = 0.f,
		float rot_speed=1.f
	);

	// 移動量を座標に反映する
	void ReflectPosition();

	// ジャンプモーション
	void JumpMotion();

	//落下モーション
	void FallMotion();

	// 停止モーション
	void StopMotion();

private:

	Vec2 m_vel;				//移動量
	float m_speed;			//速さ
	float m_jump_power;		//ジャンプ力
	float m_interval;		//ジャンプ時間
	float m_rot_speed;		//回転速度
	float m_gravity;		//重力
	float m_cur_y;			//現在のｙ座標
	bool  m_is_active;		//スキル発動中
	bool  m_is_fall;		//落下状態フラグ
	Skill m_cur_skill;		//現在のスキル
	StarChild*  m_cur_child;//現在当たっている子オブジェクト
	MapObject*  m_map_obj;	//現在のマップオブジェクト
	std::vector<StarChild*> m_childs;   //子オブジェクトのリスト
	AnimationParameter	m_effect_anim;
};

