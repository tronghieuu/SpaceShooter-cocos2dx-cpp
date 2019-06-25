#ifndef ROCK_H
#define ROCK_N

#include "MyObject.h"
#include "cocos2d.h"

class Rock :public MyObject
{
private:
	int speed;
public:
	Rock();
	Rock(cocos2d::Scene* scene);
	~Rock();
	void Init();
	void Update(float deltaTime);
	bool isVisible();
	void setPosition(float x, float y);
	void setVisible(bool b);
};

#endif
