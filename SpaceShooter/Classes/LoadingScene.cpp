#include "LoadingScene.h"
USING_NS_CC;

Scene* LoadingScene::CreateScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!LoadingScene::init())
	{
		return false;
	}



	return true;
}