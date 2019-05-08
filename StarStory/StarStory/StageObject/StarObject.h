#pragma once
#include "../Common/Common.h"
#include "ObjectBase.h"
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
	//　頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	// 自動操作
	void AutomaticMove();
	//  スキル発動
	void SkillActive(int skill_id);

	// 移動量を追加する
	void AddMoveAmount(
		float x=0.f, float y=0.f,
		float rot=1.f
	);

	// 移動量を座標に反映する
	void RefPosition();
	// ジャンプモーション
	void JumpMotion();
	// 停止モーション
	void StopMotion();

	void AdjustPosY();

private:

	Vec2  m_vel;						//移動量
	Vec2  m_temp_pos;					//保存用移動量
	float m_speed;						//速さ
	float m_jump_power;					//ジャンプ力
	float m_interval;				    //ジャンプ時間
	float m_inset_y;					//めり込みY座標
	bool  m_is_active;					//スキル発動中
	StarChild* m_cur_child;
	MapObject* m_cur_obj;
	std::vector<StarChild*> m_childs;
	
};

