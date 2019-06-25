#include "GamePlayScene.h"

USING_NS_CC;

Scene* GamePlayScene::CreateScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}