#include "Bullet.h"
#include "ResourceManager.h"

USING_NS_CC;

Bullet::Bullet()
{

}

Bullet::Bullet(Scene* scene)
{
	speed = 5;
	Init();
	scene->addChild(m_sprite, 5);
}

Bullet::~Bullet()
{
	//Delete something
}

void Bullet::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(2));
	m_sprite->setAnchorPoint(Vec2(0.5, 0));
	m_sprite->setVisible(false);
}

void Bullet::Update(float deltaTime)
{
	if (m_sprite->isVisible() && m_sprite->getPositionY() <= 1000)
	{
		m_sprite->setPositionY(m_sprite->getPositionY() + deltaTime + speed);
	}
	else
	{
		m_sprite->setVisible(false);
	}
}

bool Bullet::isVisible()
{
	return m_sprite->isVisible();
}

void Bullet::setVisible(bool b)
{
	m_sprite->setVisible(b);
}