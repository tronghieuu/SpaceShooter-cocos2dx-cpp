#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "Rock.h"
#include "SpaceShip.h"
#include <vector>
#include "cocos2d.h"

class GamePlayScene :public cocos2d::Scene
{
private:
	std::vector<Rock*> m_rocks;
	float timeCount;
	SpaceShip* m_spaceship;
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);
	void GenerateRock();
	bool onTouchBegan(Touch*, Event*);
	bool onTouchEnded(Touch*, Event*);
	void onTouchMoved(Touch*, Event*);

	CREATE_FUNC(GamePlayScene);
};

#endif