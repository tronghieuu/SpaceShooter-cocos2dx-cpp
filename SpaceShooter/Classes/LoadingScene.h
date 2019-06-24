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
	cocos2d::Sprite* progressSprite;
	cocos2d::Sprite* loadingSprite;
};

#endif
