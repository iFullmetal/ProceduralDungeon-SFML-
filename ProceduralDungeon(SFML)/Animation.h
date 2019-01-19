#pragma once
#include "ResourceManager.h"
#include <vector>
class Animation //����� �������� ������������ ����� ������ ���������� �� �������, ���������� � ResourceManager
{
private:
	vector<map<string, sf::Sprite>::iterator> frames;//������ ������ ��������
	float currentFrame;//������� ����, ������� ������ ���� ���������
	int angle; //���� �������
public:
	Animation();
	void addFrame(ResourceManager & rm, string path, sf::IntRect rect); //���������� ����� � �������
	map<string, sf::Sprite>::iterator & getCurrrentFrame(); //��������� �������� �����
	void tick(float elapsedTime);//��� ��������. ��������� ��� ��������� ��������(������� �� �������)
	void setAngle(int anlge);
	~Animation();
};

