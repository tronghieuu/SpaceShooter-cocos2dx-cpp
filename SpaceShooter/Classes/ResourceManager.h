#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "cocos2d.h"
#include <string>
#include <map>
#include "ui/CocosGUI.h"

class ResourceManager
{
private:
	static ResourceManager* m_instance;
	std::string m_dataFolderPath;
	std::map<int, cocos2d::Sprite*> m_sprites;
	std::map<int, NS_CC::ui::Button*> m_buttons;
	std::map<int, NS_CC::Label*> m_labels;
	ResourceManager();
	~ResourceManager();
	void Load(std::string fileName);
public:
	static ResourceManager* GetInstance();
	void Init(const std::string &path);
	cocos2d::Sprite* GetSpriteById(int id);
	NS_CC::ui::Button* GetButtonById(int id);
	NS_CC::Label* GetLabelById(int id);
	cocos2d::Sprite* DuplicateSprite(cocos2d::Sprite* sprite);
};

#endif
