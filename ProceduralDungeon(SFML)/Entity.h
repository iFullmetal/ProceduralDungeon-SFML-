#pragma once
//#include "Block.cpp"
#include "Block.h"
#include "Sublevel.h"
#include "AnimationManager.h"
//#include "Level.h"

class Entity : public Content //����� ��������. ������������ ����� ������ � ������������ �������� �� ���������, ����� ���������, ��������� � ��������� �����
{
protected:
	float health;
	float damage;
	double speed;
	static float speedMultiplier;
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
float Entity::speedMultiplier = 10;
