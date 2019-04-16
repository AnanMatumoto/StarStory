#include "UIObjectFactory.h"
#include "ButtonUI.h"

ObjectBase* UIObjectFactory::Create(
	int id,
	float x, float y,
	float rotate
) {

	switch (id)
	{
	case BT_START:
		new ButtonUI(x,y);
		break;
	case BT_END:
		new ButtonUI(x, y);
		break;
	}
	return nullptr;
}