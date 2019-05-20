#include "StageObjectFactory.h"
#include "../StageObject/Map/MapObject.h"
#include "../StageObject/Player/StarObject.h"
#include "../StageObject/Player/StarChild.h"
#include "../Skill.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* StageObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	std::string se_name,
	Skill skill,
	float rot
) {
	switch (id)
	{
	case STAR_OBJ:
		return new StarObject(x, y, rot);
		break;

	case STAR_CHILD1:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;

	case STAR_CHILD2:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;

	case STAR_CHILD3:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;

	case STAR_CHILD4:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;

	case STAR_CHILD5:
		return new StarChild(x, y, tex_name, se_name, skill, rot);
		break;

	}
	return nullptr;
}

ObjectBase* StageObjectFactory::Create(
	int id,
	float x,
	float y,
	bool has_goal,
	std::string tex_name
) {
	switch (id)
	{
	case OBJ_1:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_2:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_3:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_4:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_5:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_6:
		return new MapObject(x, y, tex_name, has_goal);
		break;
	case OBJ_7:
		return new MapObject(x, y, tex_name, has_goal);
		break;

	case OBJ_8:
		return new MapObject(x, y, tex_name, has_goal);
		break;
	}
	return nullptr;
}