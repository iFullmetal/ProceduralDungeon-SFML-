#pragma once
#include "ResourceManager.h"
const size_t COMMON_SPRITE_SIZE = 16;
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

