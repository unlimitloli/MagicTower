#include "GameScene.h"
#include "MapLayer.h"

USING_NS_CC;

bool GameScene::init()
{
	if (!Scene::init())
		return false;

	auto layer = MapLayer::create();
	addChild(layer);

	return true;
}