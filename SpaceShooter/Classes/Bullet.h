#ifndef BULLET_H
#define BULLET_H

#include "MyObject.h"
#include "cocos2d.h"

class Bullet :public MyObject
{
private:
	int speed;
public:
	Bullet();
	Bullet(cocos2d::Scene* scene);
	~Bullet();
	void Init();
	void Update(float deltaTime);
};

#endif
