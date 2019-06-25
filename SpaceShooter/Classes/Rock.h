#ifndef ROCK_H
#define ROCK_N

#include "MyObject.h"
#include "cocos2d.h"

class Rock :public MyObject
{
private:
	int speed;                     //Speed of rock moving on scene
public:
	Rock();
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init();                   //Init rock sprite, set visible false, call in constructor
	void Update(float deltaTime);  //Handle moving rocks that are visible and set visible false for rock out of range
};

#endif
