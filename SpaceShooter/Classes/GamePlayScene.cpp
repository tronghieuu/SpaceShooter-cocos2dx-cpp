#include "GamePlayScene.h"
#include "ResourceManager.h"

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
		m_rocks.push_back(new Rock(this));
	}

	//Add background
	auto background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->removeFromParent();
	addChild(background, 0);

	m_spaceship = new SpaceShip(this);

	scheduleUpdate();

	return true;
}

void GamePlayScene::update(float deltaTime)
{
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
		if (m_rocks[i]->isVisible())
		{
			m_rocks[i]->Update(deltaTime);
		}
	}
	m_spaceship->Update(deltaTime);
}

void GamePlayScene::GenerateRock()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i < m_rocks.size(); i++)
	{
		if (!m_rocks[i]->isVisible())
		{
			m_rocks[i]->setPosition(random(0, (int)visibleSize.width), visibleSize.height);
			break;
		}
	}
}