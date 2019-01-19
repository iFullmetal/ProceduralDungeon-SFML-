#pragma once
#include "Content.h"
//#include "draw.cpp"
//const int BLOCK_SIZE = 16; //������ = ������

enum BlockType
{
	none, brick
};
class Block : public Content
{
public:
	bool isRendered = 0; //���������� ��������� �� ����, ����� ��������� ������������������, ������ ��� �������������� ��� ����� �����������.
	BlockType type;
	Block();
	Block(size_t x, size_t y, BlockType type, ResourceManager & rm);
	void setBlockType(BlockType type, ResourceManager & rm);
	void draw(sf::RenderWindow & win);
	void update(float elapsedTime);
	~Block();
};

