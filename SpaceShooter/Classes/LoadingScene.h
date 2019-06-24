#ifndef LOADING_SCENE_H
#define LOADING_SCENE_H

#include "cocos2d.h"

class LoadingScene:public cocos2d::Scene
{
public:
	static Scene* CreateScene();
	virtual bool init();

	CREATE_FUNC(LoadingScene);
};

#endif
