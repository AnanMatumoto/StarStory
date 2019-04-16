#include "ObjectFactory.h"
#include "../StageObject/ObjectTest1.h"
#include "../StageObject/StarObject.h"
#include "../StageObject/StarChild.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* ObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	float rot
	) {


	switch (id)
	{
	case OBJ_TEST1:
		return new ObjectTest1(x,y);
		break;

	case STAR_OBJ:
		return new StarObject(x, y,rot);
		break;
	
	case STAR_CHILD1:
		return new StarChild(x, y, tex_name,rot);
		break;	

	case STAR_CHILD2:
		return new StarChild(x, y, tex_name,rot);
		break;

	case STAR_CHILD3:
		return new StarChild(x, y, tex_name, rot);
		break;

	case STAR_CHILD4:
		return new StarChild(x, y, tex_name, rot);
		break;

	case STAR_CHILD5:
		return new StarChild(x, y, tex_name, rot);
		break;

	}
	return nullptr;
}



