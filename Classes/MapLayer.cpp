#include "MapLayer.h"
#include "Hero.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
		return false;

	auto tiled = TMXTiledMap::create("tmx/map.tmx");
	addChild(tiled);

	auto objects = tiled->objectGroupNamed("objects");
	auto heroPoint = objects->objectNamed("hero");

	m_hero = Hero::create();
	addChild(m_hero);

	m_hero->setPosition(heroPoint["x"].asInt(), heroPoint["y"].asInt());

	MenuItemFont *menuDown = MenuItemFont::create("Down", [&](Ref *sender) {m_hero->run(0); });
	MenuItemFont *menuLeft = MenuItemFont::create("Left", [&](Ref *sender) {m_hero->run(1); });
	MenuItemFont *menuRight = MenuItemFont::create("Right", [&](Ref *sender) {m_hero->run(2); });
	MenuItemFont *menuUp = MenuItemFont::create("Up", [&](Ref *sender) {m_hero->run(3); });
	MenuItemFont *menuStop = MenuItemFont::create("Stop", [&](Ref *sender) {m_hero->stop(); });

	menuDown->setPosition(50, 20);
	menuLeft->setPosition(150, 20);
	menuRight->setPosition(250, 20);
	menuUp->setPosition(350, 20);
	menuStop->setPosition(450, 20);

	Menu *menu = Menu::create(menuDown, menuLeft, menuRight, menuUp, menuStop, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

	return true;
}
