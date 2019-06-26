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

	//Add score label
	scoreLabel = ResourceManager::GetInstance()->GetLabelById(1);
	scoreLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3 * 2));
	scoreLabel->setString("0");
	scoreLabel->setColor(Color3B(206, 66, 244));
	scoreLabel->removeFromParent();
	scoreLabel->setVisible(true);
	addChild(scoreLabel, 6);

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
	scoreLabel->setString(std::to_string(m_spaceship->GetScore()));

	//Go to GameOverScene when spaceship hit a rock
	m_spaceship->Collision(m_rocks);
	if (!m_spaceship->GetSprite()->isVisible())
	{
		scoreLabel->setVisible(false);
		m_spaceship->GetSprite()->setVisible(true);
		UserDefault::getInstance()->setIntegerForKey("Score", m_spaceship->GetScore());
		auto gotoGameOver = CallFunc::create([] {
			Director::getInstance()->replaceScene(GameOverScene::CreateScene());
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
	m_spaceship->GetSprite()->setPosition(touch->getLocation());
	return true;
}

bool GamePlayScene::onTouchEnded(Touch* touch, Event* event)
{
	m_spaceship->GetSprite()->setPosition(touch->getLocation());
	return true;
}

void GamePlayScene::onTouchMoved(Touch* touch, Event* event)
{
	m_spaceship->GetSprite()->setPosition(touch->getLocation());
}