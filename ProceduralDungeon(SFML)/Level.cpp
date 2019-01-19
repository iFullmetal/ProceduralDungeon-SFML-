#include "Level.h"
#include "Player.h"
#include "Guntrap.h"

Level::Level() //� ���� ������������ ��������� �������� ����� ��������� ����������� ��������� �����. �� ��������� ����������, �� ������ ��������� �� ������� � �� ����, ������ ��� ������ ��� �� ��� �� ������������
{
	sublevelLineState state; //����� - ��������� ����� ���������� ��� ������������ �����, �� � ������� ������ �����.
	//rightEnterLeftExit - ��������� ����� ���������� � ������ ������� ������ � ������� ����� �����
	//leftEnterRightExit - ��������
	LevelGenerationState generationState = normal; //����������, ���������� �� ��������� � �������� ������������ ����� � ������������� ����������. ���� ����� ���������, �� ������� ����� ���������� ������.
	size_t lx;
	size_t ly;
	float enterX; //����������� ������� ������ �� ��������-����� � ��������� 
	float enterY;
	vector<int> sublevelHorizontalLineHeight; //������ ��� �������� ����� ����� ������� ��������� �� ���������. ��������� ��� ����, ����� ����� �� ����� ���������� �� y ������ ����������
	Sublevel sub;
	int lenght = 0; //����� ������ ����� �� ���������� �� �����������
	do //������ ���� ��������� ��� ��������� ��������� ������������� Sublevel � ��������� ������������ �����. ��� ������, ����� �� ���������� ������� ���������� � ��������� ����� ���������
		//��-�� ������������ �� ������. �� ����, � ����� �������� ��������� ���������� � ������� �������� ��������, � � ������ ������� ����������. � ����� ������ ����������� ��������� ����������
		// � generationState �������� restart � ������� �� �����. �� ��������� ���������� ����� normal, �� ������ ��� ��� do while ���� ���������� ���� ���.
	{
		if (DEBUG_GENERATION_DRAW == true)
		{
			system("cls");
		}
		state = start; //������ ��������� ������ ���� � �����
		generationState = normal; //������ ��������� ��������� � ����������
		lx = 0;
		ly = 0;
		enterX = -1; //���������� -1 �� ����� ����, �� ����� ��� ����� ����������� ����������� �����
		enterY = -1;
		level.clear();
		sublevelHorizontalLineHeight.clear();
		sub = Sublevel(lx, ly, right_, exit_, generationState, rm); //������ ������ ��������� �������, � ������� ����� ������ �����
		lenght = 0;
		if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
		{
			//drawSublevel(sub);
		}

		do //������ ���� ��������� ��� ����������� ����� �� ����������. �� ���� ���� ������ ������, ����� ����� ����� � ���� ����� ������ � ����� ������ �����
			//���� ��������� ��-�� ����, ��� ���������� ������� ������ ���������� ����� ���������� �� ������ �.�. �� �������� ���������� ����������� rightEnterLeftExit � leftEnterRightExit
			//start ���������� ���� ��� � ������ � ���� � ���� �� ������
		{
			switch (state)
			{
			case start: //�� ����� ������ ��������� ����� ������ ����� �� ���������� � ������������ ������� � �������. � ������ ������ ������������ ����� ������ ������.
			{
				while (lx < X_SIZE - 3)
				{
					level.push_back(sub);
					if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
					{
						//drawSublevel(sub);
					}
					sublevelHorizontalLineHeight.push_back(sub.getHeight()); //�������� ������ �����
					lx += sub.getWidth();
					enterX = sub.getExitPosX(); 
					enterY = sub.getExitPosY();
					sub = Sublevel(lx, ly, 0, enterY, 0, generationState, rm);

					if(generationState == restart)
					{
						break;
					}
					
					sub.addExit(right_, rm);
					lenght++;
				}
				if (generationState == restart)
				{
					break;
				}
				Block * block = (Block*)level[lenght - 1].getMap()[level[lenght - 1].getExitPosY()][level[lenght - 1].getExitPosX()]; //������ ������ ����� � ���, ������ ���� ������ �����
				block->setBlockType(brick, rm);
				level[lenght - 1].getMap()[level[lenght - 1].getExitPosY()][level[lenght - 1].getExitPosX()] = block;

				level[lenght - 1].addExit(down, rm); //������ ����� ����� ����� ��� ����
				level[lenght - 1].makeItAngle();
				if(DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
				{
					//drawSublevel(level[lenght - 1]);
				}
				state = rightEnterLeftExit;
				enterX = level[lenght - 1].getExitPosX();
				enterY = level[lenght - 1].getExitPosY();
			}
			break;
			case rightEnterLeftExit:
			{
				sub = Sublevel(level[lenght - 1].getX(), sublevelHorizontalLineHeight[lenght - 1], level[lenght - 1].getWidth(), enterX, 0, 0, generationState, y_sided, rm);
				sublevelHorizontalLineHeight[lenght - 1] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
				sub.addExit(left_, rm); //�������� ����� � ����� ������ ���������
				enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
				enterY = sub.getExitPosY();
				//level.insert(level.begin() + lenght, sub);
				if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
				{
					//drawSublevel(sub);
				}
				level.push_back(sub);
				for (int i = lenght - 2; i >= 0; i--)
				{
					sub.getExitGlobalCoords(enterX, enterY); //������� ���������� ������ �� �������� ��������� � �������� ����� ������(�� ����, �� ������������ ������ ���������)
					sub = Sublevel(level[i].getX(), sublevelHorizontalLineHeight[i], level[i].getWidth(), level[i].getWidth() - 1, enterY / COMMON_SPRITE_SIZE - sublevelHorizontalLineHeight[i], 0, generationState, x_sided, rm);
					//������ �������� ��� x ������� �������� ���������, 
					//������ ��� ������� ������� ������� �������� �� ������� �����, 
					//������ ��� ������ �������� ���������(� ��� ��� �� ����� ����������) � ������� �� ������
					//��������� ��� ������-1 �.�. ������� ����� � ���������� �� X(�� ���� ����� ������ ������)
					//����� ��� ������� ����� ���������� ����������� ������ �� �������� ��������� � ������� ������� ����� �������� ���������� - � ���������� ���������� ���������� ������������ ������ ����� ���������
					//������ 0 - ��� ������� � ��������� - ����
					//������������� ���������� ������/����� ����� ��-�� ����� � ������������ ���������, ������� ����������� ����� � ����������� �� ������� �������� i � j ������� ���������� �� ����
					if (generationState == restart)
					{
						break;
					}
					sublevelHorizontalLineHeight[i] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
					sub.addExit(left_, rm); //�������� ����� � ����� ����������
				//	level.insert(level.begin() + lenght + 1, sub); //�������� ����� ���������� � ������
					if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
					{
						//drawSublevel(sub);
					}
					level.push_back(sub);
				}
				if (generationState == restart)
				{
					break;
				}
				//������ ������ ����� �����, ������ ���� ����� ����� ����
				Block * block = (Block*)level[level.size()-1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()]; //������ ������ ����� � ���, ������ ���� ������ �����
				block->setBlockType(brick, rm);
				level[level.size() - 1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()] = block;

				level[level.size() - 1].makeItAngle();

				level[level.size() - 1].addExit(down, rm); //������ ����� ����� ����� ��� ����
				enterX = level[level.size() - 1].getExitPosX(); //������� ���������� ������ �� ����� ���������
				enterY = level[level.size() - 1].getExitPosY();
				state = leftEnterRightExit;//������� ��������� ����� ���������� �� ������ �����
				if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
				{
					//drawSublevel(level[level.size() - 1]);
				}
			}
				break;
			case leftEnterRightExit:
			{
				sub = Sublevel(level[0].getX(), sublevelHorizontalLineHeight[0], level[0].getWidth(), enterX, 0, 0, generationState, y_sided, rm);
				sublevelHorizontalLineHeight[0] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
				sub.addExit(right_, rm); //�������� ����� � ����� ������ ���������
				//level.insert(level.begin() + lenght, sub);
				level.push_back(sub);
				if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
				{
					//drawSublevel(sub);
				}
				for (int i = 1; i < lenght; i++)
				{
					sub.getExitGlobalCoords(enterX, enterY); //������� ���������� ������ �� �������� ��������� � �������� ����� ������(�� ����, �� ������������ ������ ���������)
					sub = Sublevel(level[i].getX(), sublevelHorizontalLineHeight[i], level[i].getWidth(), 0, enterY / COMMON_SPRITE_SIZE - sublevelHorizontalLineHeight[i], 0, generationState, x_sided, rm);
				
					//������ �������� ��� x ������� �������� ���������, 
					//������ ��� ������� ������� ������� �������� �� ������� �����, 
					//������ ��� ������ �������� ���������(� ��� ��� �� ����� ����������) � ������� �� ������
					//��������� ��� ������-1 �.�. ������� ����� � ���������� �� X(�� ���� ����� ������ ������)
					//����� ��� ������� ����� ���������� ����������� ������ �� �������� ��������� � ������� ������� ����� �������� ���������� - � ���������� ���������� ���������� ������������ ������ ����� ���������
					//������ 0 - ��� ������� � ��������� - ����
					//������������� ���������� ������/����� ����� ��-�� ����� � ������������ ���������, ������� ����������� ����� � ����������� �� ������� �������� i � j ������� ���������� �� ����
					if (generationState == restart)
					{
						break;
					}
					sublevelHorizontalLineHeight[i] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
					sub.addExit(right_, rm); //�������� ����� � ����� ����������
					enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
					enterY = sub.getExitPosY();
					//level.insert(level.begin() + lenght, sub); //�������� ����� ���������� � ������
					if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
					{
						//drawSublevel(sub);
					}
					level.push_back(sub);
				}
				if (generationState == restart)
				{
					break;
				}
				//����� ����� �� �������� � ������ ������
				Block * block = (Block*)level[level.size() - 1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()]; //������ ������ ����� � ���, ������ ���� ������ �����
				block->setBlockType(brick, rm);
				level[level.size() - 1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()] = block;

				level[level.size() - 1].addExit(down, rm); //������ ����� ����� ����� ��� ����

				level[level.size() - 1].makeItAngle();

				enterX = level[level.size() - 1].getExitPosX(); //������� ���������� ������ �� ����� ���������
				enterY = level[level.size() - 1].getExitPosY();
				state = rightEnterLeftExit;
				if (DEBUG_GENERATION_DRAW) //��������� ���������� ��������� ����� �� ����� �������� ������. ���������� ���� ����� ������ ��� ������ ��������� ����������� ����. �������, ������ ��� ������� �������� )
				{
					//drawSublevel(level[level.size() - 1]);
				}
			}
				break;
			default:
				break;
			}
		} while (sublevelHorizontalLineHeight[0] < Y_SIZE - 3 && generationState != restart);
		Block * block = (Block*)level[level.size() - 1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()]; //������ ������ �����
		block->setBlockType(brick, rm);
		level[level.size() - 1].makeItAngle();
		level[level.size() - 1].getMap()[level[level.size() - 1].getExitPosY()][level[level.size() - 1].getExitPosX()] = block;
	} while (generationState == restart);
	for(int i = 0; i < level.size()-1; i++)
	{
		level[i].next = level[i+1].getPointer();
	}
	for(int i = 0; i < level.size();i++)
	{
		if(!level[i].isAngle())
		{
			level[i].fill(guntrapped_vertical, rm);
		}
	}
	player = new Player((level[0].getWidth() / 2) * COMMON_SPRITE_SIZE, (level[0].getHeight() / 2) * COMMON_SPRITE_SIZE, &level[0], rm);
	level[0].addContent(player);
	
	/*level[0].addContent(new Guntrap((level[0].getWidth() / 2)*COMMON_SPRITE_SIZE, COMMON_SPRITE_SIZE, rm, top, &level[0]));
	level[0].addContent(new Guntrap((level[0].getWidth() / 2)*COMMON_SPRITE_SIZE, (level[0].getHeight()-1) * COMMON_SPRITE_SIZE, rm, down, &level[0]));
	level[0].addContent(new Guntrap(COMMON_SPRITE_SIZE, (level[0].getHeight() / 2) * COMMON_SPRITE_SIZE, rm, left_, &level[0]));*/
}
Sublevel & Level::findSublevel(size_t x, size_t y)
{
	for(int subIterator = 0; subIterator < level.size(); subIterator++)
	{
		for(int i = 0; i < level[subIterator].getMap().size(); i++)
		{
			for (int j = 0; j < level[subIterator].getMap()[i].size(); j++)
			{
				if(level[subIterator].getMap()[i][j]->getX() == x && level[subIterator].getMap()[i][j]->getY() == y)
				{
					return level[subIterator];
				}
			}
		}
	}
}
vector<Sublevel> & Level::getLevelMap()
{
	return level;
}

void Level::draw(sf::RenderWindow & win)
{
	for (int i = 0; i < level.size(); i++)
	{
		drawSublevel(level[i], win);
	}
}
void Level::update(float elapsedTime)
{
	for (int i = 0; i < level.size(); i++)
	{
		updateSublevel(level[i], elapsedTime);
	}
}
Level::~Level()
{
}
