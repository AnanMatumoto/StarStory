#include "MapObject.h"
#include "../../Lib/Lib.h"

//---------------------------------
//　コンストラクタ
MapObject::MapObject(
	float x, float y,
	std::string tex_name,
	bool has_goal
): ObjectBase(x,y)
{
	Lib::Texture tex(tex_name.c_str());
	m_has_goal = has_goal;
	m_tex_name = tex_name;
	m_width    = tex.GetSize().x;
	m_height   = tex.GetSize().y;
}

//--------------------------------
//　更新処理
void MapObject::Update() {

}

//---------------------------------
// ゴールフラグゲッター
const bool MapObject::GetGoal()const {
	return m_has_goal;
}

//---------------------------------
//　描画処理
void MapObject::Draw() {

	SetVertex();
	Lib::DrawBox2D(
		m_tex_name.c_str(),
		m_vtx
	);

}

//　頂点座標をセットする
void MapObject::SetVertex(DWORD color) {

	m_vtx[0] = {{m_pos.x,  m_pos.y, 0.5f,1.f},color,{0.f,0.f}};
	m_vtx[1] = {{m_pos.x + m_width, m_pos.y, 0.5f,1.f},color,{1.f,0.f}};
	m_vtx[2] = { {m_pos.x + m_width, m_pos.y + m_height, 0.5f,1.f},color, {1.f,1.f}};
	m_vtx[3] = { {m_pos.x,  m_pos.y + m_height, 0.5f,1.f},color,{0.f,1.f}};

	BoxLocalTransform(m_vtx, m_width, m_height);
}

