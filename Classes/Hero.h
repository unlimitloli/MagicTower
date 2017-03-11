#pragma once
#include "cocos2d.h"

class Hero : public cocos2d::Node
{
public:
	CREATE_FUNC(Hero);
	virtual bool init() override;

	void initAnimation();
	void run(int direction);
	void stop();

	bool isRun() { return m_is_run; }
	int getDiretion() { return m_direction; }

protected:
	cocos2d::Sprite *m_sprite = nullptr;
	int m_direction = 0;
	bool m_is_run = false;
};