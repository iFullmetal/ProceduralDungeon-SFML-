#pragma once
class GlobalValues //�����, �������� ���������� ����������� ����������, ������ � ������� �������������� � ������� ����������� �������. ���������� �������� �� ����� config.cfg
{
private:
	static int windowWidth;
	static int windowHeight;
	static int fpsLimit;
public:
	GlobalValues();
	static int getWindowWidth();
	static int getWindowHeight();
	static int getFpsLimit();
	~GlobalValues();
};
int GlobalValues::windowWidth = 1280;
int GlobalValues::windowHeight = 720;
int GlobalValues::fpsLimit = 60;


