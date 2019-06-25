#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include "MyObject.h"
#include "Bullet.h"
#include "Rock.h"
#include "cocos2d.h"
#include <list>
#include <vector>

class SpaceShip :public MyObject
{
private:
	std::list<Bullet*> m_bullets;
public:
	SpaceShip();
	SpaceShip(cocos2d::Scene* scene);
	~SpaceShip();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(std::vector<Rock*>);
};

#endif
