#include "MapLayer.h"
#include "Hero.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
		return false;

	m_tiled_map = TMXTiledMap::create("tmx/map.tmx");
	addChild(m_tiled_map);

	m_collidable_layer = m_tiled_map->layerNamed("collidable");
	m_collidable_layer->setVisible(false);

	auto objects = m_tiled_map->objectGroupNamed("objects");
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

	scheduleUpdate();

	return true;
}

void MapLayer::update(float dt)
{
	if (m_hero->isRun())
	{
		int diretcion = m_hero->getDiretion();
		float dx = 0.0f;
		float dy = 0.0f;
		float speed = 60.0f;
		switch (diretcion)
		{
		case 0:
			dy = -speed * dt;
			break;
		case 1:
			dx = -speed * dt;
			break;
		case 2:
			dx = speed * dt;
			break;
		case 3:
			dy = speed * dt;
		}

		Vec2 pos = m_hero->getPosition();
		Vec2 new_pos = pos + Vec2(dx, dy);

		int gid = m_collidable_layer->getTileGIDAt(transformPoint(new_pos));
		if (gid != 0)
		{
			auto properiteDist = m_tiled_map->getPropertiesForGID(gid).asValueMap();
			if (properiteDist["collidable"].asBool())
				return;
		}
		m_hero->setPosition(pos + Vec2(dx, dy));
		//Vec2 pos = m_tiled_map->getPosition();
		//m_tiled_map->setPosition(pos - Vec2(dx, dy));
	}
}

cocos2d::Vec2 MapLayer::transformPoint(const cocos2d::Vec2 & pos)
{
	Size map_size = m_tiled_map->getMapSize();
	Size item_size = m_tiled_map->getTileSize();

	int x = pos.x / item_size.width;
	int y = pos.y / item_size.height;

	return cocos2d::Vec2(x, map_size.height - y - 1);
}
