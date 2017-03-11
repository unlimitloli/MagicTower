#pragma once
#include "cocos2d.h"

class Hero;

class MapLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MapLayer);
	virtual bool init() override;

	virtual void update(float dt) override;

protected:
	Hero *m_hero;
	cocos2d::TMXTiledMap *m_tiled_map;
	cocos2d::TMXLayer *m_collidable_layer;

	cocos2d::Vec2 transformPoint(const cocos2d::Vec2 &pos);
};