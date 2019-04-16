#pragma once

#include "../StageObject/Factory.h"
#include <string>


class UIObjectFactory :public Factory{

public:
	UIObjectFactory() {}
	~UIObjectFactory()override{}

private:
	ObjectBase * Create(
		int id,
		float x,
		float y,
		float rotate
	)override;

};