#include "GameOverScene.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"

USING_NS_CC;

Scene* GameOverScene::CreateScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::create())
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

	//Add home button
	auto homeButton = ResourceManager::GetInstance()->GetButtonById(2);
	homeButton->setPosition(Vec2(visibleSize.width / 2 + homeButton->getBoundingBox().size.width, visibleSize.height / 3));
	homeButton->setOpacity(0);
	homeButton->removeFromParent();
	addChild(homeButton, 1);
	homeButton->addClickEventListener([&](Ref* event) {
		auto gotoMainMenu = CallFunc::create([] {
			Director::getInstance()->replaceScene(MainMenuScene::CreateScene());
		});
		runAction(gotoMainMenu);
	});

	//Add replay button
	auto replayButton = ResourceManager::GetInstance()->GetButtonById(1);
	replayButton->setPosition(Vec2(visibleSize.width / 2 - replayButton->getBoundingBox().size.width, visibleSize.height / 3));
	replayButton->setOpacity(0);
	replayButton->setScale(1);
	replayButton->setAnchorPoint(Vec2(0.5, 0.5));
	replayButton->removeFromParent();
	addChild(replayButton, 2);
	replayButton->addClickEventListener([&](Ref* event) {
		auto gotoGamePlay = CallFunc::create([] {
			Director::getInstance()->replaceScene(GamePlayScene::CreateScene());
		});
		runAction(gotoGamePlay);
	});

	//Add Gameover label
	auto gameoverLabel = ResourceManager::GetInstance()->GetLabelById(0);
	gameoverLabel->setPosition(visibleSize.width / 2, visibleSize.height / 1.5);
	gameoverLabel->setVisible(true);
	gameoverLabel->setAnchorPoint(Vec2(0.5, 0.5));
	gameoverLabel->setString("GAME OVER");
	gameoverLabel->setColor(Color3B(209, 18, 18));
	gameoverLabel->removeFromParent();
	addChild(gameoverLabel, 3);

	//Add your score label
	auto yourScoreLabel = ResourceManager::GetInstance()->GetLabelById(1);
	yourScoreLabel->setPosition(Vec2(visibleSize.width / 2, gameoverLabel->getPositionY() - gameoverLabel->getBoundingBox().size.height * 2));
	yourScoreLabel->setString("Your Score: " + std::to_string(UserDefault::getInstance()->getIntegerForKey("Score")));
	yourScoreLabel->setOpacity(0);
	yourScoreLabel->removeFromParent();
	addChild(yourScoreLabel, 4);

	auto objectAppear = FadeIn::create(5);
	yourScoreLabel->runAction(objectAppear);
	homeButton->runAction(objectAppear->clone());
	replayButton->runAction(objectAppear->clone());

	return true;
}