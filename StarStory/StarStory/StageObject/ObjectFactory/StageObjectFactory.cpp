#include "StageObjectFactory.h"
#include "../StageObjectID.h"
#include "../../StageObject/Map/MapObject.h"
#include "../../StageObject/Player/StarObject.h"
#include "../../StageObject/Player/StarChild.h"
#include "../../Skill.h"

//---------------------------------
// 星オブジェクト生成処理
ObjectBase* StageObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	SoundResourceID se_name,
	Skill skill,
	float rot
) {
	switch (id)
	{
	case STAR_OBJ:
		return new StarObject(x, y, rot);
		break;

	case STAR_CHILD1:

	case STAR_CHILD2:
	
	case STAR_CHILD3:
	
	case STAR_CHILD4:
	
	case STAR_CHILD5:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;
	}
	return nullptr;
}

//-------------------------------------
// マップオブジェクト生成処理（オーバーロード）
ObjectBase* StageObjectFactory::CreateMap(
	int id,
	float x,
	float y,
	bool has_goal,
	std::string tex_name
) {
	switch (id)
	{
	case OBJ_1:
		
	case OBJ_2:

	case OBJ_3:

	case OBJ_4:

	case OBJ_5:
	
	case OBJ_6:
	
	case OBJ_7:
	
	case OBJ_8:
		return new MapObject(x, y, tex_name, has_goal);
		break;
	}
	return nullptr;
}