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
	std::string m_dataFolderPath;                                //Store data folder path for resource
	std::map<int, cocos2d::Sprite*> m_sprites;                   //Store sprites resource
	std::map<int, NS_CC::ui::Button*> m_buttons;                 //Store buttons resource
	std::map<int, NS_CC::Label*> m_labels;                       //Store labels resource
	ResourceManager();
	~ResourceManager();
	void Load(std::string fileName);                             //Load resource from Data.bin file
public:
	static ResourceManager* GetInstance();
	void Init(const std::string &path);                          //Passing path string for m_dataFolderPath, call Load method
	cocos2d::Sprite* GetSpriteById(int id);                      //Get sprite by id
	NS_CC::ui::Button* GetButtonById(int id);                    //Get button by id
	NS_CC::Label* GetLabelById(int id);                          //Get label by id
	cocos2d::Sprite* DuplicateSprite(cocos2d::Sprite* sprite);   //return a duplicated sprite from other sprite
};

#endif
