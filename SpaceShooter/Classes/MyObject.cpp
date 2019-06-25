#include "MyObject.h"

USING_NS_CC;

MyObject::MyObject() 
{
	//Init something
}

MyObject::~MyObject() 
{
	//Delete something
}

Sprite* MyObject::GetSprite()
{
	return m_sprite;
}