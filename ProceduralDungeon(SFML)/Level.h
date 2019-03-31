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
public:
	Level();
	Level(size_t levelWidth, size_t levelHeight);
	Content * player; 
	int getPlayerTries();
	ResourceManager & getResourceManager();
	vector<Sublevel> & getLevelMap();
	bool isGameOver();
	bool isLevelPassed();
	void draw(sf::RenderWindow & win);
	void update(sf::FloatRect viewRect);
	~Level();
};

