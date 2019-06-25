#ifndef GAME_PLAY_SCENE_H
#define GAME_PLAY_SCENE_H

#include "MyObject.h"
#include "SpaceShip.h"
#include <vector>
#include "cocos2d.h"

class GamePlayScene :public cocos2d::Scene
{
private:
	std::vector<MyObject*> m_rocks;                                     //list rocks wiil be droped down on scene periodically
	float timeCount;                                                    //Counting time for generate rock
	SpaceShip* m_spaceship;                                             //SpaceShip object
public:
	static Scene* CreateScene();
	virtual bool init();
	void update(float deltaTime);                                       //call Update method of m_spaceship, couting time by timeCount to call generaterock method
	void GenerateRock();                                                //Generate a rock from the top of screen
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	CREATE_FUNC(GamePlayScene);
};

#endif