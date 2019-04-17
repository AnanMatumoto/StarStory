#include "StarChild.h"
#include "StarObject.h"
#include "ObjectManager.h"
#include "ObjectTest1.h"

DWORD red = 0;//※後で消す

			  //------------------------------------
//　コンストラクタ
StarChild::StarChild(
	float x,
	float y,
	std::string tex_name,
	float rot
) :ObjectBase(x, y, rot) {
	m_width = 46.f;
	m_height = 64.f;
	m_tex_name = tex_name;
	m_parent = ObjectManager::GetInstance().FindObject(STAR_OBJ);
	m_hit_obj = ObjectManager::GetInstance().GetGameObjects<ObjectTest1>();
	is_hit = false;
}

//------------------------------------
//　更新処理
void StarChild::Update() {

}

//------------------------------------
//　描画処理
void StarChild::Draw() {
	SetVertex(red);//※
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
	m_vtx[0] = { {(0.5f - ox),oy,0.f,1.f}, color,{0.f,0.5f} };
	m_vtx[1] = { {ox,(0.5f + oy), 0.f,1.f},color,{0.5f,1.f} };
	m_vtx[2] = { {(0.5f + ox),oy, 0.f, 1.f},color,{1.f,0.5f} };
	m_vtx[3] = { {ox,(0.5f - oy), 0.f,1.f},color,{0.5f,0.f} };
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

//---------------------------------------
//　当たり判定用フラグゲッター
void StarChild::IsHitToObject() {

	Vec2 vec = { m_vtx[1].pos.x, m_vtx[1].pos.y };

	for (auto it : m_hit_obj) {
		if (vec.x <= it->GetWidth()) {
			//オブジェクトの幅に頂点があるか
			if (IsHitToSurface(vec, it)) {
				//頂点が当たっているか
				red = 0x00ff0000;
				is_hit = true;
			}
			else {
				red = 0x00ff0000;
				is_hit = true;
			}
		}
		else {
			red = 0;//※
			is_hit = false;
		}
	}
}

//-------------------------------
//　当たり判定用変数ゲッター
const bool StarChild::GetHit()const {
	return is_hit;
}


//-------------------------------
//	当たり判定用変数セッター
void StarChild::SetHit(bool is_hit_) {
	is_hit = is_hit_;
}

