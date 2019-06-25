#include "ResourceManager.h"
#include <fstream>

USING_NS_CC;

ResourceManager* ResourceManager::m_instance = NULL;

ResourceManager::ResourceManager() {}

ResourceManager* ResourceManager::GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new ResourceManager();
	}

	return m_instance;
}

ResourceManager::~ResourceManager()
{
	//something
}

void ResourceManager::Init(const std::string &path)
{
	m_dataFolderPath = path;
	Load("Data.bin");
}

void ResourceManager::Load(std::string fileName)
{
	int amount;
	int id;
	std::string tempStr1, tempStr2; //Using for temporary store data from file
	std::ifstream readingFile;
	readingFile.open(m_dataFolderPath+fileName);
	if (readingFile.is_open())
	{
		//Load Sprite resource
		readingFile >> tempStr1 >> tempStr1;
		amount = std::stoi(tempStr1);
		for (int i = 0; i < amount; i++)
		{
			readingFile >> tempStr1 >> tempStr1;
			id = std::stoi(tempStr1);
			readingFile >> tempStr1 >> tempStr1;
			tempStr1.replace(0, 2, "res");
			m_sprites.insert(std::pair<int, Sprite*>(id, Sprite::create(tempStr1)));
			m_sprites[id]->retain();
		}
		//Load Button resource
		readingFile >> tempStr1 >> tempStr1;
		amount = std::stoi(tempStr1);
		for (int i = 0; i < amount; i++)
		{
			readingFile >> tempStr1 >> tempStr1;
			id = std::stoi(tempStr1);
			readingFile >> tempStr1 >> tempStr1;
			tempStr1.replace(0, 2, "res");
			readingFile >> tempStr2 >> tempStr2;
			tempStr2.replace(0, 2, "res");
			m_buttons.insert(std::pair<int, ui::Button*>(id, ui::Button::create(tempStr1, tempStr2)));
			m_buttons[id]->retain();
		}
		//Load Font resource
		readingFile >> tempStr1 >> tempStr1;
		amount = std::stoi(tempStr1);
		for (int i = 0; i < amount; i++)
		{
			readingFile >> tempStr1 >> tempStr1;
			id = std::stoi(tempStr1);
			readingFile >> tempStr1 >> tempStr1;
			tempStr1.replace(0, 2, "res");
			m_labels.insert(std::pair<int, Label*>(id, Label::createWithTTF("", tempStr1, 40)));
			m_labels[id]->retain();
		}
		readingFile.close();
	}
	else
	{
		log("error");
	}
}

cocos2d::Sprite* ResourceManager::GetSpriteById(int id)
{
	return m_sprites[id];
}

ui::Button* ResourceManager::GetButtonById(int id)
{
	return m_buttons[id];
}

Label* ResourceManager::GetLabelById(int id)
{
	return m_labels[id];
}

Sprite* ResourceManager::DuplicateSprite(Sprite* sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}
