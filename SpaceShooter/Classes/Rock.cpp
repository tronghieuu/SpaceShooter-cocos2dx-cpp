#include "Rock.h"
#include "ResourceManager.h"

USING_NS_CC;

Rock::Rock()
{

}

Rock::Rock(Scene* scene)
{
	Init();
	scene->addChild(m_sprite);
}

Rock::~Rock()
{

}

void Rock::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(3));
}

void Rock::Update(float deltaTime)
{

}