#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include "MyObject.h"
#include "cocos2d.h"
#include <list>
#include <vector>

class SpaceShip :public MyObject
{
private:
	std::list<MyObject*> m_bullets;               //List bullets using for shooting rocks
	float timeCount;                              //Couting time for generate bullet periodically
public:
	SpaceShip();
	SpaceShip(cocos2d::Scene* scene);
	~SpaceShip();
	void Init();                                  //Init spaceship sprite, call in constructor
	void Update(float deltaTime);                 //Call shoot method depend on timeCount
	void Shoot();                                 //handle moving bullet and set false visible for bullet out of range
	void Collision(std::vector<MyObject*> rock);  //setvisible(false) for spaceship when hit rock and visible(false) for rock when hit bullet 
};

#endif
