#pragma once
#include "Sublevel.h"
//#include "Entity.h"
//#include <windows.h>
const bool DEBUG_GENERATION_DRAW = false; //��������� ���������� �� ����� ������ ������������ ������

//void drawSublevel(Sublevel & sublevel, sf::RenderWindow & win, float elapsedTime)
//{
//	for (int i = 0; i < sublevel.getMap().size(); i++)
//	{
//		for (int j = 0; j < sublevel.getMap()[i].size(); j++)
//		{
//			sublevel.getMap()[i][j]->update(elapsedTime);
//			sublevel.getMap()[i][j]->draw(win);
//		}
//	}
//	if(DEBUG_GENERATION_DRAW) //����� �������� ������� ��� ������������
//	{
//		//Sleep(70);
//	}
//}
void drawSublevel(Sublevel & sublevel, sf::RenderWindow & win)
{
	for (int i = 0; i < sublevel.getMap().size(); i++)
	{
		for (int j = 0; j < sublevel.getMap()[i].size(); j++)
		{
			sublevel.getMap()[i][j]->draw(win);
		}
	}
}
void updateSublevel(Sublevel & sublevel, float elapsedTime)
{
	for (int i = 0; i < sublevel.getMap().size(); i++)
	{
		for (int j = 0; j < sublevel.getMap()[i].size(); j++)
		{
			sublevel.getMap()[i][j]->update(elapsedTime);
			
		}
	}

}
void drawLevel(vector<Sublevel> & level, sf::RenderWindow & win)
{
	for (int i = 0; i < level.size(); i++)
	{
		drawSublevel(level[i], win);
	}
}

enum sublevelLineState
{
	start, rightEnterLeftExit, leftEnterRightExit
};

class Level
{
protected:
	vector<Sublevel> level; //������ ����������, � ������� ������ ���������� �����, � ����� ���������� ��� ����������
	ResourceManager rm; //����� ��� ��������� ��������/�������� � �.�. ������ ����� ����� ������������ ���� � ��� �� ������. ���� ����� ���������� �� ��������������.
public:
	Level();
	Content * player;
	Sublevel & findSublevel(size_t x, size_t y);
	int levelLenght; //���������� ���������� �� �����������
	vector<Sublevel> & getLevelMap();
	void draw(sf::RenderWindow & win);
	void update(float elapsedTime);
	~Level();
};

