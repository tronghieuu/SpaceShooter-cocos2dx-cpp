#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "cocos2d.h"

class MainMenuScene :public cocos2d::Scene
{
public:
	static Scene* CreateScene();
	virtual bool init();

	CREATE_FUNC(MainMenuScene);
};

#endif
