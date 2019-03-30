#pragma once
class DebugInformation //����� ��� ����� ���������� � ������ ���������(� �������������� �������� Singleton)
{
private:
	DebugInformation() = default;
	~DebugInformation() = default;
public:
	int renderedEntitiesCounter = 0;
	int updatedEntitiesCounter = 0;

	DebugInformation(const DebugInformation&) = delete;
	DebugInformation& operator=(DebugInformation&) = delete;
	static DebugInformation & getInstance();
	void clear();
};

