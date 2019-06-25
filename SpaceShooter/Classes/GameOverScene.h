#ifndef GAME_OVER_SCENE_H
#define GAME_OVER_SCENE_H

#include "cocos2d.h"

class GameOverScene :public cocos2d::Scene
{
public:
	static Scene* CreateScene();
	virtual bool init();

	CREATE_FUNC(GameOverScene);
};

#endif
