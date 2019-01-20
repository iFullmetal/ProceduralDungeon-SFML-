#pragma once
//#include "Block.cpp"
#include "Block.h"
#include "Sublevel.h"
#include "AnimationManager.h"
//#include "Level.h"


//enum EntityType
//{
//	invisible, cross, snake, v_arrow_up, v_arrow_down, v_arrow_right, v_arrow_left 
//};

class Entity : public Content //����� ��������. ������������ ����� ������ � ������������ �������� �� ���������, ����� ���������, ��������� � ��������� �����
{
protected:
	float health;
	float damage;
	double speed;
	Sublevel * current_sublevel;
	AnimationManager am;
public:
	void move(float dirX, float dirY, float elapsedTime); //����� ������������ �� ������ � ��������� ������������
	void updateRect(); //����� ��� ���������� ��������� �������������� �������
	void hit(Entity * en); //��������� �����
	virtual void decreaseHealth(float value); //����� ���������� �������� ���� �������� �� ���������� ��������(�����������, ��������� ���������� ��� ������)
	bool damageDealing(); //����� �������� � ������� ������ ��������� �����. ���� ������������ � ��������, �������� ����� ������� �� ����������, �� ������ false
	Entity();
	~Entity();
};

