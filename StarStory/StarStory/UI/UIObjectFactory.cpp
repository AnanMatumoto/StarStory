#include "UIObjectFactory.h"
#include "Button.h"
#include "UIManager.h"
#include "UIObjectID.h"

ObjectBase* UIObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	float rot
) {

	switch (id)
	{
	/*--TitleScene--*/
	case BT_TT_START:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_TT_END:
		return new ButtonUI(x, y, tex_name);
		break;
	/*--TitleScene--*/

	/*--SelectScene--*/
	case BT_SL_STAGE:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_SL_BACK:
		return new ButtonUI(x, y, tex_name);
		break;

	/*--CustomScene--*/
	case BT_CT_DECISION:						// 決定ボタン
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_CT_TOSELECT:						// セレクトへ戻るボタン
		return new ButtonUI(x, y, tex_name);
		break;
	/*--CustomScene--*/

	/*--GameScene--*/
	case BT_GM_WIND:
		return new ButtonUI(x, y, tex_name);
		break;

	case BT_GM_FRAME:
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
	/*--GameScene--*/

	/*--ResultScene--*/
	case BT_RS_SELECT:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_RS_CUSUTOM:
		return new ButtonUI(x, y, tex_name);
		break;
	case BT_RS_TITLEBACK:
		return new ButtonUI(x, y, tex_name);
		break;

	case BT_RS_FLAME_R:
		return new ButtonUI(x, y, tex_name);
		break;

	case BT_RS_FLAME_L:
		return new ButtonUI(x, y, tex_name);
		break;
	/*--ResultScene--*/
	}
	return nullptr;
}