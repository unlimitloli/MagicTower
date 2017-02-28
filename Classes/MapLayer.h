#pragma once
#include "cocos2d.h"

class Hero;

class MapLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MapLayer);
	virtual bool init() override;

protected:
	Hero *m_hero;
};