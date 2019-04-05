#include "StageObjectFactory.h"
#include "ObjectTest1.h"
#include "StarObject.h"
#include "StarChild.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* StageObjectFactory::Create(int id,float x, float y) {


	switch (id)
	{
	case OBJ_TEST1:
		return new ObjectTest1(x,y);
		break;

	case STAR_OBJ:
		return new StarObject(x, y);
		break;
	
	case STAR_CHILD1:
		return new StarChild(x, y);
		break;	
	}
	return nullptr;
}



