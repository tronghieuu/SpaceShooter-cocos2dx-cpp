#ifndef MY_OBJECT_H
#define MY_OBJECT_H

#include "cocos2d.h"

class MyObject
{
protected:
	cocos2d::Sprite* m_sprite;
public:
	MyObject();
	virtual ~MyObject();
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
};

#endif
