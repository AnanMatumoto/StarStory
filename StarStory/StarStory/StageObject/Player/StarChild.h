#pragma once

#include "../../Skill.h"
#include "../..//Lib/Lib.h"
#include "../ObjectBase.h"
#include "../../Sound/SoundManager/SoundManager.h"
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
		SoundResourceID se_name,
		Skill skill,
		float rot
	);
	~StarChild()override {}

	// 当たり判定用変数ゲッター
	const bool GetHit()const;

	// スキル名ゲッター
	const Skill GetSkill()const;
	
	//現在当たっているマップオブジェクトゲッター
	ObjectBase* GetMapObj() const;

	//オブジェクトの上の辺とめり込んだ距離を取得
	float GetDistanceToCeiling();

private:
	
	// 更新処理
	void Update()override;
	
	// 描画処理
	void Draw()override;
	
	// 頂点座標の設定
	void SetVertex(DWORD color = 0x00ffffff)override;
	
	// 親の座標を反映する
	void RefParentVertex(Vertex vtx[4]);

	//当たったオブジェクトを取得する
	void HitToObject();
	
	//当たり判定状態フラグゲッター
	void IsHit();

	//SE再生処理
	void PlaySE();

private:

	ObjectBase* m_parent;			    //親オブジェクト
	Skill       m_skill;			    //スキル
	ObjectBase* m_cur_obj;				//現在のマップオブジェクト
	float       m_obj_width;		    //マップオブジェクトの幅
	bool        is_hit;					//当たり判定状態フラグ
	int			m_one_flame;			//一フレーム取得用変数
	std::vector<MapObject*> m_map_obj;  //マップオブジェクトのリスト
	SoundResourceID m_se_id;
};

