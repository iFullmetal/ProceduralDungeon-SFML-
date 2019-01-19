#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}
void ResourceManager::loadTexture(string path)
{
	if(textures.find(path) == textures.end()) //� ������, ���� ����� ��������� ���, �� �������� ��
	{
		sf::Texture texture;
		texture.loadFromFile(path);
		textures.emplace(path, texture);
	}
}
map<string, sf::Sprite>::iterator ResourceManager::loadSprite(string path, sf::IntRect rect)
{
	if (sprites.find(path) == sprites.end()) //���� ������ ������� ���, �� �������� ���
	{
		loadTexture(path); 
		sprites.emplace(path, sf::Sprite(textures.find(path)->second));
		sprites[path].setTextureRect(rect);
		sprites[path].setPosition(0, 0);
	}
	return sprites.find(path); //��������� ��������� �� ���� ������
}
ResourceManager::~ResourceManager()
{
}
