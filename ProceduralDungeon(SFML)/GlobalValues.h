#pragma once
class GlobalValues //�����, �������� ���������� ����������� ����������, ������ � ������� �������������� � ������� ����������� �������. ���������� �������� �� ����� config.cfg
{
private:
	static int windowWidth;
	static int windowHeight;
	static int fpsLimit;
	static int viewWidth;
	static int viewHeight;
	
public:
	GlobalValues();
	static int getWindowWidth();
	static int getWindowHeight();

	static int getViewWidth();
	static int getViewHeight();

	static void setViewWidth(int width);
	static void setViewHeight(int height);

	static int getFpsLimit();

	static int zoomScaleFactor;

	~GlobalValues();
};
int GlobalValues::windowWidth = 1280;
int GlobalValues::windowHeight = 720;
int GlobalValues::fpsLimit = 60;
int GlobalValues::viewWidth = 1280;
int GlobalValues::viewHeight = 720;
int GlobalValues::zoomScaleFactor = 1;

