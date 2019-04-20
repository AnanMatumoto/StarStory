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
		Skill skill,
		std::string tex_name,
		float rot
	);
	~StarChild()override {}

	// 当たり判定用変数ゲッター
	const bool GetHit()const;

	// スキル名ゲッター
	const Skill GetSkill()const;
	
	// 当たり判定判定処理
	void IsHitToObject();

private:
	
	// 更新処理
	void Update()override;
	
	// 描画処理
	void Draw()override;
	
	// 頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	
	// 親の座標を反映する
	void RefParentVertex(Vertex vtx[4]);

private:

	ObjectBase* m_parent;			    //親オブジェクト
	Skill       m_skill;			            //スキル
	std::string m_tex_name;				//画像名
	std::vector<MapObject*> m_hit_obj;//マップオブジェクトのリスト
	bool        is_hit;

};

