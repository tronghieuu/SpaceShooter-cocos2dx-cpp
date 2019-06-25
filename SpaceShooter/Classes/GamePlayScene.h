#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "Rock.h"
#include <vector>
#include "cocos2d.h"

class GamePlayScene :public cocos2d::Scene
{
private:
	std::vector<Rock*> m_rocks;
	float timeCount;
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);
	void GenerateRock();

	CREATE_FUNC(GamePlayScene);
};

#endif