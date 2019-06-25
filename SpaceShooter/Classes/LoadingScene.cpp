#include "LoadingScene.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"

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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	//Add background
	auto background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->removeFromParent();
	addChild(background, -5);
	
	//Add loading label
	auto loadingLabel = ResourceManager::GetInstance()->GetLabelById(0);
	loadingLabel->setString("Loading...");
	loadingLabel->setPosition(visibleSize.width / 2, visibleSize.height / 2.1);
	loadingLabel->removeFromParent();
	addChild(loadingLabel, -4);
	
	//Add loading frame
	loadingSprite = ResourceManager::GetInstance()->GetSpriteById(5);
	loadingSprite->setPosition(visibleSize.width / 2, visibleSize.height/2.4);
	loadingSprite->removeFromParent();
	addChild(loadingSprite, 0);

	//Add progress bar
	progressSprite = ResourceManager::GetInstance()->GetSpriteById(6);
	progressSprite->setPosition(Vec2(loadingSprite->getPositionX() - loadingSprite->getBoundingBox().size.width / 2, visibleSize.height / 2.4));
	progressSprite->setAnchorPoint(Vec2(0, 0.5));
	progressSprite->removeFromParent();
	addChild(progressSprite, -2);
	
	scheduleUpdate();

	return true;
}

void LoadingScene::update(float deltaTime)
{
	auto gotoNextScene = CallFunc::create([] {
		Director::getInstance()->replaceScene(MainMenuScene::CreateScene());
	});
	runAction(gotoNextScene);
}