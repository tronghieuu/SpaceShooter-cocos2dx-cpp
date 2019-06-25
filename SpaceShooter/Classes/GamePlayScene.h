#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "MyObject.h"
#include "SpaceShip.h"
#include <vector>
#include "cocos2d.h"

class GamePlayScene :public cocos2d::Scene
{
private:
	std::vector<MyObject*> m_rocks;
	float timeCount;
	SpaceShip* m_spaceship;
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);
	void GenerateRock();
	/*bool onTouchBegan(Touch* t, Event* e);
	bool onTouchEnded(Touch* t, Event* e);
	void onTouchMoved(Touch* t, Event* e);*/

	CREATE_FUNC(GamePlayScene);
};

#endif