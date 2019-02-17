#pragma once
#include "ResourceManager.h"
const size_t COMMON_SPRITE_SIZE = 32;
enum direction //������������ ������� ��������� � ���������
{
	left_, right_, top, down, left_top_angle, left_bottom_angle, right_top_angle, right_bottom_angle
};
class Content
{
protected:
	float x;//���������� ���������� � ��������� ������
	float y;
	//sf::Sprite * sprite = nullptr; //��������� �� ������, ������� ����� � ������� � ������ ResourceManager
	map<string, sf::Sprite>::iterator sprite_iterator;
	sf::FloatRect rect; //������������� �������. � ������� ���� �������������� �������� ������������ ��������� ������ intersects 
	
	bool collides;
	bool hitable;
public:

	Content();
    virtual void draw(sf::RenderWindow & win) = 0;
	virtual void update(float elapsedTime) = 0;
	bool isCollides();
	bool isHitable();
	virtual void updateRect(); //����� ��� ���������� ��������� �������������� �������
	sf::FloatRect getRect();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	float & getXDirectly();
	float & getYDirectly();
	~Content();
};

