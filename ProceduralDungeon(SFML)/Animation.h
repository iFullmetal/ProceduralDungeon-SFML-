#pragma once
#include "ResourceManager.h"
#include <vector>
class Animation //����� �������� ������������ ����� ������ ���������� �� �������, ���������� � ResourceManager
{
private:
	vector<map<string, sf::Sprite>::iterator> frames;//������ ������ ��������
	float currentFrame;//������� ����, ������� ������ ���� ���������
	int angle; //���� �������
	float speed = 0.1;
public:
	Animation();
	void addFrame(ResourceManager & rm, string path, sf::IntRect rect); //���������� ����� � �������
	map<string, sf::Sprite>::iterator & getCurrrentFrame(); //��������� �������� �����
	void tick();//��� ��������. ��������� ��� ��������� ��������(������� �� �������)
	void setAngle(int anlge);
	~Animation();
};

