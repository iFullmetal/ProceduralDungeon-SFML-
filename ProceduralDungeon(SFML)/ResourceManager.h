#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iterator>
#include "DebugInformation.h"
//sf::Clock globalClock;
//int plUpdates = 0;
using namespace std;


const size_t COMMON_SPRITE_SIZE = 32;
class ResourceManager
{
private:
	map<string, sf::Texture> textures; 
	map<string, sf::Sprite> sprites;
	void loadTexture(string path);
public:
	ResourceManager();
	
	map<string, sf::Sprite>::iterator loadSprite(string path, sf::IntRect rect);
	~ResourceManager();
};

