#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include "MyObject.h"
#include "cocos2d.h"
#include <list>
#include <vector>

class SpaceShip :public MyObject
{
private:
	std::list<MyObject*> m_bullets;
	int timeCount;
public:
	SpaceShip();
	SpaceShip(cocos2d::Scene* scene);
	~SpaceShip();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(std::vector<MyObject*>);
};

#endif
