#pragma once
#include "cocos2d.h"

class MapLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MapLayer);
	virtual bool init() override;
};