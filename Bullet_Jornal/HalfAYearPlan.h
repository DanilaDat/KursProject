#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"Notes.h"
#define HAYPMounthLen 13
using namespace std;
// ����������� �� ������ GlobalInformation
// ������������ ��� ������ � ������� ������������
// �� �������
class HalfAYearPlan :public GlobalInformation
{
private:
	int Mounth; // �������� ������, ��� �������� ������� ����  (��������� ������ ������ ��������)
	int Identifier;             // ������������� �����
public:
	HalfAYearPlan();            // ����������� 
	~HalfAYearPlan();           // ����������
	const char IdentifierBack() const;
	int IdentifierChoise();
	void TablePrint(std::ostream& out) const;
	int MounthChose();
	// ���������� ��������� ������
	friend std::ostream& operator<<(std::ostream& out, const HalfAYearPlan& hypobj);
	// ���������� ��������� �����
	friend std::istream& operator>>(std::istream& in, HalfAYearPlan& hypobj);

	friend ofstream& operator<<(ofstream& out, HalfAYearPlan& hyobj);
	friend ifstream& operator>>(ifstream& in, HalfAYearPlan& hyobj);
};
