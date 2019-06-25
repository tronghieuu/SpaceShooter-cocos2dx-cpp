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
	timeCount = 0;
	Init();
	for (int i = 0; i < 20; i++)
	{
		MyObject* obj = new Bullet(scene);
		m_bullets.push_back(obj);
	}
	scene->addChild(m_sprite, 6);
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::Init()
{
	m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
}

void SpaceShip::Update(float deltaTime)
{
	if (timeCount >= 0.3)
	{
		Shoot();
		timeCount = 0;
	}
	else
	{
		timeCount += deltaTime;
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
			(*i)->GetSprite()->setPosition(m_sprite->getPositionX(), m_sprite->getPositionY());
			break;
		}
	}
}