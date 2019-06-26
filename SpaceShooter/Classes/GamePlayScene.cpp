#include "GamePlayScene.h"
#include "ResourceManager.h"
#include "Rock.h"
#include "SpaceShip.h"
#include "GameOverScene.h"

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

	timeCount = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//Init vector rocks
	for (int i = 0; i < 15; i++)
	{
		m_rocks.push_back((MyObject*) new Rock(this));
	}

	//Add background
	auto background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->removeFromParent();
	addChild(background, 0);

	//Touch eventlistener for spaceship
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//Add spaceship sprite
	m_spaceship = new SpaceShip(this);
	m_spaceship->GetSprite()->setVisible(true);

	//Add score label
	scoreLabel = ResourceManager::GetInstance()->GetLabelById(0);
	scoreLabel->setPosition(Vec2(visibleSize.width, visibleSize.height));
	scoreLabel->setString("Your Score: ");
	scoreLabel->setColor(Color3B(255, 255, 255));
	scoreLabel->setAnchorPoint(Vec2(1, 1));
	scoreLabel->removeFromParent();
	scoreLabel->setVisible(true);
	addChild(scoreLabel, 6);

	//Add pause button
	pauseButton = ResourceManager::GetInstance()->GetButtonById(3);
	pauseButton->setAnchorPoint(Vec2(0, 1));
	pauseButton->setPosition(Vec2(0, visibleSize.height));
	pauseButton->removeFromParent();
	addChild(pauseButton, 9);
	pauseButton->addClickEventListener([&](Ref* event) {
		pauseButton->setVisible(false);
		Director::getInstance()->getRunningScene()->pause();
	});

	//Add resume button
	resumeButton = ResourceManager::GetInstance()->GetButtonById(1);
	resumeButton->setAnchorPoint(Vec2(0, 1));
	resumeButton->setScale(0.75);
	resumeButton->setPosition(Vec2(0, visibleSize.height));
	resumeButton->removeFromParent();
	addChild(resumeButton, 7);
	resumeButton->addClickEventListener([&](Ref* event) {
		pauseButton->setVisible(true);
		Director::getInstance()->getRunningScene()->resume();
	});

	scheduleUpdate();
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	m_spaceship->Update(deltaTime);

	if (timeCount >= 0.2)
	{
		GenerateRock();
		timeCount = 0;
	}
	else
	{
		timeCount += deltaTime;
	}

	//Move all rocks that are visible
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (m_rocks[i]->GetSprite()->isVisible())
		{
			m_rocks[i]->Update(deltaTime);
		}
	}

	//Update score
	scoreLabel->setString("Your Score: " + std::to_string(m_spaceship->GetScore()));

	//Go to GameOverScene when spaceship hit a rock
	m_spaceship->Collision(m_rocks);
	if (!m_spaceship->GetSprite()->isVisible())
	{
		scoreLabel->setVisible(false);
		UserDefault::getInstance()->setIntegerForKey("Score", m_spaceship->GetScore());
		auto gotoGameOver = CallFunc::create([] {
			Director::getInstance()->getRunningScene()->pause();
			Director::getInstance()->replaceScene(TransitionCrossFade::create(2, GameOverScene::CreateScene()));
		});
		runAction(gotoGameOver);
	}
}

void GamePlayScene::GenerateRock()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (!m_rocks[i]->GetSprite()->isVisible())
		{
			m_rocks[i]->GetSprite()->setVisible(true);
			m_rocks[i]->GetSprite()->setPosition(random(0, (int)visibleSize.width), visibleSize.height);
			break;
		}
	}
}

bool GamePlayScene::onTouchBegan(Touch* touch, Event* event)
{
	if (m_spaceship->GetSprite()->getBoundingBox().containsPoint(touch->getLocation()))
	{
		return true;
	}
	return false;
}

bool GamePlayScene::onTouchEnded(Touch* touch, Event* event)
{
	if (m_spaceship->GetSprite()->getBoundingBox().containsPoint(touch->getLocation()))
	{
		return true;
	}
	return false;
}

void GamePlayScene::onTouchMoved(Touch* touch, Event* event)
{
	float x, y;
	x = touch->getLocation().x - touch->getPreviousLocation().x + m_spaceship->GetSprite()->getPositionX();
	y = touch->getLocation().y - touch->getPreviousLocation().y + m_spaceship->GetSprite()->getPositionY();
	if (x >= 0 && y >= m_spaceship->GetSprite()->getBoundingBox().size.height/2 && x <= Director::getInstance()->getVisibleSize().width&&y <= Director::getInstance()->getVisibleSize().height)
	{
		m_spaceship->GetSprite()->setPosition(Vec2(x, y));
	}
}