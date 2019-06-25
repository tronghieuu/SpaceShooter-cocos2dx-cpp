#include "Rock.h"
#include "ResourceManager.h"

USING_NS_CC;

Rock::Rock()
{

}

Rock::Rock(Scene* scene)
{
	speed = 5;
	Init();
	scene->addChild(m_sprite, 5);
}

Rock::~Rock()
{

}

void Rock::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(3));
	m_sprite->setVisible(false);
	m_sprite->setAnchorPoint(Vec2(0.5, 0));
}

void Rock::Update(float deltaTime)
{
	if (m_sprite->isVisible() && m_sprite->getPositionY() + m_sprite->getBoundingBox().size.height >= 0)
	{
		m_sprite->setPositionY(m_sprite->getPositionY() - (speed + deltaTime));
	}
	else
	{
		m_sprite->setVisible(false);
	}
}