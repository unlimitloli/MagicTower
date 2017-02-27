#include "MapLayer.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
		return false;

	auto tiled = TMXTiledMap::create("tmx/map.tmx");
	addChild(tiled);

	auto objects = tiled->objectGroupNamed("objects");
	auto heroPoint = objects->objectNamed("hero");

	auto sprite = Sprite::create("img/images/chengying_1.png");
	addChild(sprite);

	sprite->setPosition(heroPoint["x"].asInt(), heroPoint["y"].asInt());
	return true;
}
