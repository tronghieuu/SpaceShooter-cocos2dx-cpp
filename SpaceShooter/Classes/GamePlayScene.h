#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "cocos2d.h"

class GamePlayScene :public cocos2d::Scene
{
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);


	CREATE_FUNC(GamePlayScene);
};

#endif