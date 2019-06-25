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
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	CREATE_FUNC(GamePlayScene);
};

#endif