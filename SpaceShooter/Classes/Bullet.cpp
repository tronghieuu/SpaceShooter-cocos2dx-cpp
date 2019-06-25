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
	scene->addChild(m_sprite, 8);
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (m_sprite->isVisible() && m_sprite->getPositionY() <= visibleSize.height)
	{
		m_sprite->setPositionY(m_sprite->getPositionY() + deltaTime + speed);
	}
	else
	{
		m_sprite->setVisible(false);
	}
}