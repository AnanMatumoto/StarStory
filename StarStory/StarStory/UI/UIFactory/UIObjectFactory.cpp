#include "UIObjectFactory.h"
#include "../Button/Button.h"
#include "../UIManager/UIManager.h"
#include "../UIObjectID.h"

ObjectBase* UIObjectFactory::Create(
	int id,
	float x, float y,
	std::string tex_name,
	float rot
) {

	switch (id)
	{
	/*--TitleScene--*/
	case BT_TITLE_START:
	
	case BT_TITLE_END:

	/*--SelectScene--*/
	case BT_SELECT_STAGE:

	case BT_SELECT_BACK:

	/*--CustomScene--*/
	case BT_CUSTOM_DECISION:						

	case BT_CUSTOM_BACK:						

	/*--GameScene--*/
	case BT_GAME_WIND:

	case BT_GAME_FRAME:

	case BT_GAME_BACK:

	case BT_GAME_STOP:

	//case BT_GAME_ONOFF:

	/*--ResultScene--*/
	case BT_RESULT_BACK_SELECT:

	case BT_RESULT_BACK_CUSTOM:

	case BT_RESULT_BACK_TITLE:
		return new ButtonUI(x, y, tex_name);
		break;
	}
	return nullptr;
}