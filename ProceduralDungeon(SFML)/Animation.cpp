#include "Animation.h"



Animation::Animation()
{
	currentFrame = 0;
	angle = 0;
}
void Animation::addFrame(ResourceManager & rm, string path, sf::IntRect rect)
{
	frames.push_back(rm.loadSprite(path, rect));//��������� �������� ����� ResourceManager, �� ��������� ���� �� ���, ���� ���� �� ���� �������� �� ���, ���� ��� �� ��������� � ���� ���� ��������
	(*frames.back()).second.setOrigin(rect.width / 2, rect.height / 2); //������ �����, ������������ �������� ������� ���������� � ������ �������
}
map<string, sf::Sprite>::iterator & Animation::getCurrrentFrame()
{
	(*frames[int(currentFrame)]).second.setRotation(angle);//����� ���� ������� ������������� ���� �������� � ��������� ����
	return frames[int(currentFrame)]; 
}
void Animation::setAngle(int anlge)
{
	this->angle = anlge;
}
void Animation::tick()
{
	currentFrame += speed;//������ ������� ���� 
	if (currentFrame >= frames.size())  //� ������, ���� ���������� ����� �� ������ �������, �� ����������� � ������.(�������� ��������)
	{
		currentFrame = 0;
	}
}
Animation::~Animation()
{
}
