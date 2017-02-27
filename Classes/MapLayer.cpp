#include "MapLayer.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
		return false;

	auto pTMXTiledMap = TMXTiledMap::create("tmx/map.tmx");
	addChild(pTMXTiledMap);
	return true;
}
