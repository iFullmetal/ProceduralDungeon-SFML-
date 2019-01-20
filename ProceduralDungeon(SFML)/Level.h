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
	Level(size_t levelWidth, size_t levelHeight);
	Content * player; //��������� �� ������, ����� ��� �������� ������� � ��� ����������� �����
	int getPlayerTries();//������� ��������� �������(������ ������)
	ResourceManager & getResourceManager();
	int levelLenght; //���������� ���������� �� �����������
	vector<Sublevel> & getLevelMap();
	void draw(sf::RenderWindow & win);
	void update(float elapsedTime);
	~Level();
};

