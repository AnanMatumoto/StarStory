#pragma once

#include "../Skill.h"
#include "ObjectBase.h"
#include <vector>
#include <string>

class MapObject;
class StarObject;

//====================================
// 星オブジェクトの子クラス
//====================================
class StarChild :public ObjectBase {
public:

	StarChild(
		float x,
		float y,
		std::string tex_name,
		Skill skill,
		float rot
	);
	~StarChild()override {}

	// 当たり判定用変数ゲッター
	const bool GetHit()const;

	// スキル名ゲッター
	const Skill GetSkill()const;
	
	float GetHitObjWidth();


private:
	
	// 更新処理
	void Update()override;
	
	// 描画処理
	void Draw()override;
	
	// 頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	
	// 親の座標を反映する
	void RefParentVertex(Vertex vtx[4]);

	void HitToObject();

	void IsHit();

private:

	ObjectBase* m_parent;			    //親オブジェクト
	Skill       m_skill;			            //スキル
	ObjectBase* m_obj;
	std::vector<MapObject*> m_map_obj; //マップオブジェクトのリスト
	float       m_obj_width;		   // マップオブジェクトの幅
	bool        is_hit;

};

