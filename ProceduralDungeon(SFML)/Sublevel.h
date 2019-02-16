#pragma once
#include <vector>
#include "Block.h"

const size_t MIN_RAND_SIZE = 10; //8 ����������� ������ ���������
const size_t MAX_RAND_SIZE = 20; //20 ������������ ������ ���������
const size_t MAX_RAND_LOOP_COUNT = 40; //������������ ���������� �������� ����� ��������� �������� ���������

extern int randomNumber(int minNum, int maxNum);

enum LevelGenerationState  //������������, ���������� �� ��������� � �������� ������������ ����� � ������������� ����������. ���� ����� ���������, �� ���� ������� ����� ���������� ������.
{
	normal, restart
};
enum direction //������������ ������� ��������� � ���������
{
	left_, right_, top, down
};
enum HoleDestenation //������������ ��� ������ ���������� ���������. � ����� ������ ��� ������ ��������� ���������� 0-hight ��� 0-width � ������ ���
{
	x_sided, y_sided
};
enum holeMode //������������ ��� ����������� ������ ������������. ���� ������� ����, ���� ������� �����
{
	enter, exit_//�� exit ��� _ ��������
};
enum SublevelFillingType //������������ ����� ���������� ����������
{
	first, last, clean, guntrapped_vertical, guntrapped_horizontal, razer 
};
class Sublevel
{
private:
	size_t x, y; //���������� ��������� � ������
	size_t height, width; //������ � ������ ���������

	int enterPosX = -1; //���������� ����� ����� � ������
	int enterPosY = -1; // -1 ����� ��� ����������, ������� �� ����� ���� �� �����. ������ ��� ����� � ��������� ��������� ��������
	int exitPosX = -1;
	int exitPosY = -1;
	sf::FloatRect exitRect; //FloatRect - ����� ��������������, ������ ���� ����������. ��������� ��� ��� � ��������� ��� ��������� ������ � ����� �� ���������
	sf::FloatRect enterRect;
	SublevelFillingType fillingType;//��� ���������� ���������
	vector<vector<Content*>> map;//��������� ������, �������� ��� ����� ���������, ������������ ����� ����������� �������. ��� ����� ����� ����� � ����.
	//������� � ����� ����������, ����������� ��� ����������� ��������� ��������� �������� ���������
	//ResourceManager *& rm;
	void generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, direction holePosition); //������� ��������� ��������� ����� ��� ������, �������������� �������� ���������
	bool angle = 0;
	
public:
	static size_t X_SIZE;
	static size_t Y_SIZE;
	Sublevel * next = NULL;
	Sublevel * prev = NULL;
	Sublevel();
	~Sublevel();
	//������������ ������
	Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState, HoleDestenation holeDestenation, ResourceManager & rm); //����������� ��������� � ������������ �������
	//������������ � ������������������ ������������ �����/������, ������������� ������� � �������
	Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeTyp, LevelGenerationState & gStatee, ResourceManager & rm); //����������� ��� �������� ��������� � ����������� � ����� ������� � ������������� ���������(holeType = 0 - ����, 1 - �����)
	//������������ � ������������� ������������ �����/������, ������� � �������.
	Sublevel(size_t x, size_t y, direction holePosition, holeMode mode, LevelGenerationState & gState, ResourceManager & rm); //����������� ��������� � ������������ ����������� ��������� ��� ���������(������� �� mode)
	vector<vector<Content*>> & getMap();
	void addExit(direction holePosition, ResourceManager & rm); //������� ��� �������� ������ � ��� ��������� ���������
	void addEnter(direction holePosition, ResourceManager & rm);
	//get ������
	void getExitGlobalCoords(float & x, float & y); //������� ��� ��������� ���������� ��������� ������(� ������ �������� ���������� ������������ ������)
	void getEnterGlobalCoords(float & x, float & y); //������� ��� ��������� ���������� ��������� ������(� ������ �������� ���������� ������������ ������)
	vector<Content*>::iterator getContentIterator(Content * cont); //���������� �������� �� ������� � �������. ����� ��� ������ � �������� �������� �� ����� ������ �� ������ ��������
	void addContent(Content * c); //���������� �������� � ������ ���������(� �����)
	void makeItAngle();
	bool isAngle();
	void fill(SublevelFillingType ft, ResourceManager & rm);
	size_t getX();
	size_t getY();
	sf::FloatRect getExitRect();
	sf::FloatRect getEnterRect();
	size_t getHeight();
	size_t getWidth();
	size_t getEnterPosX();
	size_t getEnterPosY();
	size_t getExitPosX();
	size_t getExitPosY();
	void addPlayerToEnter(ResourceManager & rm);
	//Sublevel & operator =(const Sublevel & sub);
};
size_t Sublevel::X_SIZE;
size_t Sublevel::Y_SIZE;