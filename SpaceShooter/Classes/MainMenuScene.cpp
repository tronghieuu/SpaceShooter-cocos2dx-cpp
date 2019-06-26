#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "GamePlayScene.h"

USING_NS_CC;

Scene* MainMenuScene::CreateScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
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
	addChild(background, 0);

	//Add logo
	auto logo = ResourceManager::GetInstance()->GetSpriteById(1);
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3 * 2.2));
	logo->removeFromParent();
	addChild(logo, 1);

	//Add play button
	auto playButton = ResourceManager::GetInstance()->GetButtonById(0);
	playButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3));
	playButton->removeFromParent();
	addChild(playButton, 2);
	playButton->addClickEventListener([&](Ref* event) {
		auto gotoNextScene = CallFunc::create([] {
			Director::getInstance()->replaceScene(TransitionFadeDown::create(1, GamePlayScene::CreateScene()));
		});
		runAction(gotoNextScene);
	});

	return true;
}