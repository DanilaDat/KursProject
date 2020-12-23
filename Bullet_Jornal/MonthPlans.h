#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"Notes.h"
#define MPDofWLen 14
using namespace std;
// ����������� �� ������ Notes
// ������������ ��� ������ � ������� ������������ �� �����
class MonthPlan : public Notes
{
private:
	int DayOfWeek; // ���� ������ ��� �������� ������ ���� // ����������� ��=�� ������
public:
	MonthPlan();   // �����������
	~MonthPlan();  // ����������
	void TablePrint(ostream& out) const;
	const int GetDayOfWeek() const { return this->DayOfWeek; };
	// ���������� ��������� ������
	friend std::ostream& operator<<(std::ostream& out, const MonthPlan& mplobj);
	// ���������� ��������� �����
	friend std::istream& operator>>(std::istream& in, MonthPlan& mplobj);

	friend ofstream& operator<<(ofstream& out, MonthPlan& mplobj);
	friend ifstream& operator>>(ifstream& in, MonthPlan& mplobj);
};