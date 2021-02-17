#include "GlobalValues.h"
#include <fstream>
#include <string>

using namespace std;

GlobalValues::GlobalValues()
{
	ifstream ifs;
	ifs.open("config.cfg");
	if(!ifs.is_open()) //���� ����� ���, ������
	{
		ofstream ofs;
		ofs.open("config.cfg");
		ofs << "WindowWidth: 1280\nWindowHeight: 720\nFPSLimit: 60";
		windowWidth = 1280;
		windowHeight = 720;
		fpsLimit = 60;
	}
	else //���� ����, �� ����� � �������� � ���� ������
	{
		string buf;
		int pos = 0;
		while (getline(ifs, buf))
		{
			switch (pos)
			{
			case 0:
				windowWidth = atoi(buf.c_str() + 13);
				break;
			case 1:
				windowHeight = atoi(buf.c_str() + 14);
				break;
			case 2:
				fpsLimit = atoi(buf.c_str() + 10);
				break;
			default:
				break;
			}
			pos++;
		}
	}
	viewHeight = windowHeight;
	viewWidth = windowWidth;
}

int GlobalValues::getWindowWidth()
{
	return windowWidth;
}

int GlobalValues::getWindowHeight()
{
	return windowHeight;
}

int GlobalValues::getViewWidth()
{
	return viewWidth;
}
int GlobalValues::getViewHeight()
{
	return viewHeight;
}

void GlobalValues::setViewWidth(int width)
{
	viewWidth = width;
}
void GlobalValues::setViewHeight(int height)
{
	viewHeight = height;
}

int GlobalValues::getFpsLimit()
{
	return fpsLimit;
}




GlobalValues::~GlobalValues()
{
}
