#include "SpaceShip.h"
#include "ResourceManager.h"
#include "MyObject.h"
#include "Bullet.h"

USING_NS_CC;

SpaceShip::SpaceShip()
{

}

SpaceShip::SpaceShip(Scene* scene)
{
	score = 0;
	timeCount = 0;
	Init();
	for (int i = 0; i < 20; i++)
	{
		m_bullets.push_back((MyObject*) new Bullet(scene));
	}
	m_sprite->removeFromParent();
	scene->addChild(m_sprite, 4);
}

SpaceShip::~SpaceShip()
{
	//Delete something
}

void SpaceShip::Init()
{
	m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
	m_sprite->setAnchorPoint(Vec2(0.5, 1));
	m_sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, m_sprite->getBoundingBox().size.height);
}

void SpaceShip::Update(float deltaTime)
{
	timeCount += deltaTime;
	if (timeCount >= 0.3)
	{
		Shoot();
		timeCount = 0;
	}
	for (std::list<MyObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++)
	{
		if ((*i)->GetSprite()->isVisible())
		{
			(*i)->Update(deltaTime);
		}
	}
}

void SpaceShip::Shoot()
{
	for (std::list<MyObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++)
	{
		if (!(*i)->GetSprite()->isVisible())
		{
			(*i)->GetSprite()->setVisible(true);
			(*i)->GetSprite()->setPosition(m_sprite->getPosition());
			break;
		}
	}
}

void SpaceShip::Collision(std::vector<MyObject*> rock)
{
	for (int i = 0; i < rock.size(); i++)
	{
		if (rock[i]->GetSprite()->isVisible())
		{
			//Check spaceship hit rock
			if (m_sprite->getBoundingBox().intersectsRect(rock[i]->GetSprite()->getBoundingBox()))
			{
				m_sprite->setVisible(false);
				return;
			}
			//Check bullet hit rock
			for (std::list<MyObject*>::iterator j = m_bullets.begin(); j != m_bullets.end(); j++)
			{
				if ((*j)->GetSprite()->getBoundingBox().intersectsRect(rock[i]->GetSprite()->getBoundingBox()) && (*j)->GetSprite()->isVisible())
				{
					rock[i]->GetSprite()->setVisible(false);
					(*j)->GetSprite()->setVisible(false);
					score++;
					return;
				}
			}
		}
	}

}

int SpaceShip::GetScore()
{
	return score;
}