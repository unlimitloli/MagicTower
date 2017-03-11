#include "Hero.h"

USING_NS_CC;

const char *animation_name[4] = { "down", "left", "right", "up" };
const char *frame_name = "chengying_%d.png";

bool Hero::init()
{
	if (!Node::init())
		return false;

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plist/chengying.plist");
	initAnimation();

	m_sprite = Sprite::createWithSpriteFrameName("chengying_1.png");
	addChild(m_sprite);
	
	m_sprite->setAnchorPoint(Vec2::ZERO);
	m_sprite->setPosition(Vec2::ZERO);

	return true;
}

void Hero::initAnimation()
{
	SpriteFrameCache *frame_cache = SpriteFrameCache::getInstance();
	AnimationCache *animation_cache = AnimationCache::getInstance();

	for (int i = 0; i < 4; ++i)
	{
		Animation *animation = Animation::create();
		int static_index = i * 3 + 1;
		SpriteFrame *frame1 = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("chengying_%d.png", static_index));
		SpriteFrame *frame2 = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("chengying_%d.png", static_index - 1));
		SpriteFrame *frame3 = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("chengying_%d.png", static_index));
		SpriteFrame *frame4 = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("chengying_%d.png", static_index + 1));
		animation->addSpriteFrame(frame1);
		animation->addSpriteFrame(frame2);
		animation->addSpriteFrame(frame3);
		animation->addSpriteFrame(frame4);

		animation->setDelayPerUnit(0.3f);
		animation->setLoops(-1);
		animation->setRestoreOriginalFrame(true);

		animation_cache->addAnimation(animation, animation_name[i]);
	}
}

void Hero::run(int direction)
{
	if ((m_is_run == true) && (m_direction == direction))
		return;
	m_is_run = true;
	m_direction = direction;

	Animation *animation = AnimationCache::getInstance()->getAnimation(animation_name[direction]);
	Animate *animate = Animate::create(animation);
	animate->setTag(m_direction);
	
	m_sprite->stopAllActions();
	m_sprite->runAction(animate);
}

void Hero::stop()
{
	m_is_run = false;
	m_sprite->stopActionByTag(m_direction);
	m_sprite->setSpriteFrame(StringUtils::format("chengying_%d.png", m_direction * 3 + 1));
}
