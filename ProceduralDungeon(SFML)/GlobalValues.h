#pragma once
class GlobalValues //�����, �������� ���������� ����������� ����������, ������ � ������� �������������� � ������� ����������� �������. ���������� �������� �� ����� config.cfg
{
private:
	static int windowWidth;
	static int windowHeight;
public:
	GlobalValues();
	static int getWindowWidth();
	static int getWindowHeight();
	~GlobalValues();
};
int GlobalValues::windowWidth = 1280;
int GlobalValues::windowHeight = 720;


