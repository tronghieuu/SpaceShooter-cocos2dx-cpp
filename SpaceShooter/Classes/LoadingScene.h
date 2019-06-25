#ifndef LOADING_SCENE_H
#define LOADING_SCENE_H

#include "cocos2d.h"

class LoadingScene:public cocos2d::Scene
{
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);

	CREATE_FUNC(LoadingScene);
private:
	float timeCount;                 //Couting time to go to next scene through deltaTime
	cocos2d::Sprite* progressSprite; //Declare to can be adjusting in update method
};

#endif
