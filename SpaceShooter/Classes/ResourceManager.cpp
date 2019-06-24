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
	Load(m_dataFolderPath+"Data.bin");
}

void ResourceManager::Load(std::string fileName)
{
	int amount;
	int id;
	std::string tempStr1, tempStr2, tempStr3; //Using for temporary store data from file
	std::ifstream readingFile;
	readingFile.open(fileName);
	if (readingFile.is_open())
	{
		//Load Sprite resource
		getline(readingFile, tempStr1);
		amount = std::stoi(tempStr1.erase(0, strlen("#SPRITE ")));
		for (int i = 0; i < amount; i++)
		{
			getline(readingFile, tempStr1);
			id = std::stoi(tempStr1.erase(0, strlen("ID: ")));
			getline(readingFile, tempStr2);
			tempStr2.erase(0, strlen("PATH: "));
			tempStr2.replace(0, 2, "res");
			m_sprites.insert(std::pair<int, Sprite*>(id, Sprite::create(tempStr2)));
		}
		//Load Button resource
		getline(readingFile, tempStr1);
		amount = std::stoi(tempStr1.erase(0, strlen("#BUTTON ")));
		for (int i = 0; i < amount; i++)
		{
			getline(readingFile, tempStr1);
			id = std::stoi(tempStr1.erase(0, strlen("ID: ")));;
			getline(readingFile, tempStr2);
			tempStr2.erase(0, strlen("NORMAL_PATH: "));
			tempStr2.replace(0, 2, "res");
			getline(readingFile, tempStr3);
			tempStr3.erase(0, strlen("PRESSED_PATH: "));
			tempStr3.replace(0, 2, "res");
			m_buttons.insert(std::pair<int, ui::Button*>(id, ui::Button::create(tempStr2, tempStr3)));
		}
		//Load Font resource
		getline(readingFile, tempStr1);
		amount = std::stoi(tempStr1.erase(0, strlen("#FONT ")));
		for (int i = 0; i < amount; i++)
		{
			getline(readingFile, tempStr1);
			id = std::stoi(tempStr1.erase(0, strlen("ID: ")));
			getline(readingFile, tempStr2);
			tempStr2.erase(0, strlen("PATH: "));
			tempStr2.replace(0, 2, "res");
			m_labels.insert(std::pair<int, Label*>(id, Label::createWithTTF("sdfsd", tempStr2, 3)));
		}
		readingFile.close();
	}
}

cocos2d::Sprite* ResourceManager::GetSpriteById(int id)
{
	return m_sprites[id];
}

NS_CC::ui::Button* ResourceManager::GetButtonById(int id)
{
	return m_buttons[id];
}

NS_CC::Label* ResourceManager::GetLabelById(int id)
{
	return m_labels[id];
}