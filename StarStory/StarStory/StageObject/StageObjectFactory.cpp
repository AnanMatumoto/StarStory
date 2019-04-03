#include "StageObjectFactory.h"
#include "ObjectTest1.h"

//---------------------------------
//　ステージオブジェクト生成処理
ObjectBase* StageObjectFactory::Create(int id) {
	switch (id)
	{
	case OBJ_TEST1:
		return new ObjectTest1();
		break;
	}
	return nullptr;
}



