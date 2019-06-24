#include "LoadingScene.h"
#include "ResourceManager.h"

USING_NS_CC;

Scene* LoadingScene::CreateScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto child = ResourceManager::GetInstance()->GetSpriteById(0);
	child->setPosition(Vec2(50, 50));
	this->addChild(child);

	return true;
}