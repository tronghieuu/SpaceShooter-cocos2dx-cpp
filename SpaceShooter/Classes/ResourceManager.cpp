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
	auto sprite = m_sprites[id];
	sprite->retain();
	return sprite;
}

NS_CC::ui::Button* ResourceManager::GetButtonById(int id)
{
	auto button = m_buttons[id];
	button->retain();
	return button;
}

NS_CC::Label* ResourceManager::GetLabelById(int id)
{
	auto label = m_labels[id];
	label->retain();
	return label;
}