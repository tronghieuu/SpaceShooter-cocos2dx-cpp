#include "GamePlayScene.h"
#include "ResourceManager.h"
#include "Rock.h"
#include "SpaceShip.h"

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

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	m_spaceship = new SpaceShip(this);
	m_spaceship->GetSprite()->setPosition(visibleSize.width / 2, m_spaceship->GetSprite()->getBoundingBox().size.height);

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
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (m_rocks[i]->GetSprite()->isVisible())
		{
			m_rocks[i]->Update(deltaTime);
		}
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