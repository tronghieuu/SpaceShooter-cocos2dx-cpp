#ifndef BULLET_H
#define BULLET_H

#include "MyObject.h"
#include "cocos2d.h"

class Bullet :public MyObject
{
private:
	int speed;                      //Speed of Bullet
public:
	Bullet();
	Bullet(cocos2d::Scene* scene);
	~Bullet();
	void Init();                    //Init bullet sprite, set visible false, call in constructor
	void Update(float deltaTime);   //Handle moving bullets that are visible, set false visible for bullet out of range
};

#endif
