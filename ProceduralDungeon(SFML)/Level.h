#pragma once
#include "Sublevel.h"

enum sublevelLineState
{
	start, rightEnterLeftExit, leftEnterRightExit
};

class Level
{
protected:
	vector<Sublevel> level; //������ ����������, � ������� ������ ���������� �����, � ����� ���������� ��� ����������
	ResourceManager rm; //����� ��� ��������� ��������/�������� � �.�. ������ ����� ����� ������������ ���� � ��� �� ������. ���� ����� ���������� �� ��������������.
	size_t levelHeight; //��������� ������ � ������ ������
	size_t levelWidth;
	map<string, sf::Shader*>::iterator current_shader;
public:
	Level();
	Level(size_t levelWidth, size_t levelHeight);
	Content * player; 
	int getPlayerTries();
	ResourceManager & getResourceManager();
	vector<Sublevel> & getLevelMap();
	bool isGameOver();
	bool isLevelPassed();
	map<string, sf::Shader*>::iterator & getCurrentShader();
	void draw(sf::RenderWindow & win);
	void draw(sf::RenderTexture & rendTexture, vector<sf::Glsl::Vec2> & lightEmiters, sf::FloatRect viewRect);
	void update(sf::FloatRect viewRect);
	~Level();
};

