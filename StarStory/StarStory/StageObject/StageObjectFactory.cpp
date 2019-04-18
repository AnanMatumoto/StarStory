#include "StageObjectFactory.h"
#include "ObjectTest1.h"
#include "StarObject.h"
#include "StarChild.h"
#include "../Skill.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* StageObjectFactory::Create(
	int id,
	float x, float y,
	Skill skill,
	std::string tex_name,
	float rot
) {
	switch (id)
	{
	case OBJ_TEST1:
		return new ObjectTest1(x, y);
		break;

	case STAR_OBJ:
		return new StarObject(x, y, rot);
		break;

	case STAR_CHILD1:
		return new StarChild(x, y, skill, tex_name, rot);
		break;

	case STAR_CHILD2:
		return new StarChild(x, y, skill, tex_name, rot);
		break;

	case STAR_CHILD3:
		return new StarChild(x, y, skill, tex_name, rot);
		break;

	case STAR_CHILD4:
		return new StarChild(x, y, skill, tex_name, rot);
		break;

	case STAR_CHILD5:
		return new StarChild(x, y, skill, tex_name, rot);
		break;

	}
	return nullptr;
}
