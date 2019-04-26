#include "StageObjectFactory.h"
#include "MapObject.h"
#include "StarObject.h"
#include "StarChild.h"
#include "../Skill.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* StageObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	Skill skill,
	float rot
) {
	switch (id)
	{
	case OBJ_TEST1:
		return new MapObject(x, y,tex_name);
		break;

	case OBJ_TEST2:
		return new MapObject(x, y, tex_name);
		break;
	case STAR_OBJ:
		return new StarObject(x, y, rot);
		break;

	case STAR_CHILD1:
		return new StarChild(x, y, tex_name, skill, rot);
		break;

	case STAR_CHILD2:
		return new StarChild(x, y, tex_name, skill, rot);
		break;

	case STAR_CHILD3:
		return new StarChild(x, y, tex_name, skill, rot);
		break;

	case STAR_CHILD4:
		return new StarChild(x, y, tex_name, skill, rot);
		break;

	case STAR_CHILD5:
		return new StarChild(x, y, tex_name, skill, rot);
		break;

	}
	return nullptr;
}
