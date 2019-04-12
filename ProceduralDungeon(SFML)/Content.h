#pragma once
#include "ResourceManager.h"

enum direction //������������ ������� ��������� � ���������
{
	left_, right_, top, down, left_top_angle, left_bottom_angle, right_top_angle, right_bottom_angle
};
class Content
{
protected:
	float x;//���������� ���������� � ��������� ������
	float y;
	map<string, sf::Sprite>::iterator sprite_iterator;
	sf::FloatRect rect; //������������� �������. � ������� ���� �������������� �������� ������������ ��������� ������ intersects 
	string shader = "";
	bool collides; //����� �� ������ ��������
	bool hitable; //����� �� ��� �������
	bool independent; //����� �� �� ��� ������ �� ������� ������ ��� ��������� ����
public:

	Content();
    virtual void draw(sf::RenderTarget & win) = 0;
	virtual void update() = 0;
	bool isCollides();
	bool isHitable();
	bool isIndependent();
	virtual void updateRect(); //����� ��� ���������� ��������� �������������� �������
	sf::FloatRect getRect();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	string getShader();
	float & getXDirectly();
	float & getYDirectly();
	~Content();
};

