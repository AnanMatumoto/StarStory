#include "UIObjectFactory.h"
#include "ButtonUI.h"


ObjectBase* UIObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	float rot
) {

	switch (id)
	{
	case BT_TT_START:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_TT_END:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_CT_DEC:
		return new ButtonUI(x, y, tex_name);
			break;
	case BT_CT_MAP:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_CT_TOSELECT:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_GM_WIND:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_GM_TOCUSTOM:
		return new ButtonUI(x,y,tex_name);
		break;
	case BT_GM_STOP:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_GM_ONOFF:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_RS_SELECT:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_RS_CUSUTOM:
		return new ButtonUI(x, y, tex_name);
		break;
	}
	return nullptr;
}