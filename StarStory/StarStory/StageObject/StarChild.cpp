#include "StarChild.h"
#include "StarObject.h"
#include "ObjectManager.h"
#include "MapObject.h"
#include "../Collision/Collision.h"

//------------------------------------
//　コンストラクタ
StarChild::StarChild(
	float x,
	float y,
	std::string tex_name,
	std::string se_name,
	Skill skill,
	float rot
) :ObjectBase(x, y, rot){

	m_width    = 46.f;
	m_height   = 64.f;
	m_tex_name = tex_name;
	m_parent   = ObjectManager::GetInstance().FindObject(STAR_OBJ);
	m_map_obj  = ObjectManager::GetInstance().GetGameObjects<MapObject>();
	m_obj_width = 0.f;
	is_hit     = false;
	m_skill    = skill;
	m_obj      = nullptr;
	m_se_name  = se_name;
	m_sound    = new Lib::AudioPlayer();
	m_one_flame = 0;
}

//------------------------------------
//　更新処理
void StarChild::Update() {

	HitToObject();
	IsHit();
	PlaySE();
}

//------------------------------------
//　描画処理
void StarChild::Draw() {

	SetVertex();
	Lib::DrawDiamond2D(
		m_tex_name.c_str(),
		m_vtx
	);
}

//-------------------------------------
//頂点の設定
void StarChild::SetVertex(DWORD color) {
	
	float ox = 0.5f;
	float oy = 0.5f;
	m_vtx[0] = { {(0.5f - ox),oy,0.f,1.f}, color,{0.31f,0.5f} };
	m_vtx[1] = { {ox,(0.5f + oy), 0.f,1.f},color,{0.5f,0.78f} };
	m_vtx[2] = { {(0.5f + ox),oy, 0.f, 1.f},color,{0.69f,0.5f} };
	m_vtx[3] = { {ox,(0.5f - oy), 0.f,1.f},color,{0.5f,0.228f} };

	DiamondLocalTransform(m_vtx, m_width, m_height);
	RefParentVertex(m_vtx);

}

//-------------------------------------
//親の座標を自身に反映する
void StarChild::RefParentVertex(Vertex vtx[4]) {
	
	//親の座標を取得
	float pos_x = m_parent->GetX();
	float pos_y = m_parent->GetY();
	
	//親の回転角を取得
	float sin = sinf(D3DXToRadian(m_parent->GetRot()));
	float cos = cosf(D3DXToRadian(m_parent->GetRot()));
	float vtx_pos_x = 0.f;
	float vtx_pos_y = 0.f;
	
	for (int i = 0; i < 4; ++i) {
		//ローカル座標XYを保存
		vtx_pos_x = vtx[i].pos.x;
		vtx_pos_y = vtx[i].pos.y;
		//回転を合成した新座標を設定
		float new_x = (vtx_pos_x * cos) + (vtx_pos_y * -sin);
		float new_y = (vtx_pos_x * sin) + (vtx_pos_y * cos);
		//相対座標を設定する
		vtx[i].pos.x = new_x + pos_x;
		vtx[i].pos.y = new_y + pos_y;
	}
}

//--------------------------------------
//　オブジェクトとの当たり判定を処理する
void StarChild::HitToObject() {

	SetVertex();
	//自身の頂点ベクトル
	Vec2 vec = { m_vtx[1].pos.x, m_vtx[1].pos.y };

	for (auto obj : m_map_obj) {
		float right = obj->GetVertex(1).pos.x;
		//頂点がオブジェクトの幅の中なら保存
		if (vec.x >= obj->GetX() && vec.x <= right) {
				m_obj = obj;
		}
	}
}

void StarChild::IsHit() {

	SetVertex();
	Vec2 vec = { m_vtx[1].pos.x, m_vtx[1].pos.y };
	if (m_obj != nullptr) {
		//マップと頂点が当たっているか
		if (IsHitToUpper(vec, m_obj)) {
			++m_one_flame;
			is_hit = true;
		}
		else {
			is_hit = false;
		}
	}
}

//-------------------------------
//　当たり判定用変数ゲッター
const bool StarChild::GetHit()const
{
	return is_hit;
}

//-------------------------------
//　スキル名ゲッター
const Skill StarChild::GetSkill()const {
	return m_skill;
}

//-------------------------------
// 当たったマップオブジェクトを返す
ObjectBase* StarChild::GetMapObj()const {
	if (m_obj != nullptr) {
		return m_obj;
	}
}

float StarChild::DistanceToCeiling() {

	if (m_obj != nullptr) {
		float obj_y = m_obj->GetVertex(0).pos.y;
		return obj_y - m_vtx[1].pos.y;
	}
}

//---------------------------------
// SE処理
void StarChild::PlaySE() {

	Lib::AudioClip& clip = Lib::AudioClip::GetInterface();
	clip.LoadWaveFile(m_se_name);

	if (m_one_flame == 1) {
		m_sound->Play(m_se_name);
		m_sound->SetVolume(-300);
	}

}