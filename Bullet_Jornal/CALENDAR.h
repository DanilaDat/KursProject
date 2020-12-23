#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
//��������� � ������� ������������ ������ Calendar
struct LocalData
{
	int Day;        // ����
	int Mounth;     // ����� ������
	int Year;       // ���
	int AfterWDays; // ���� ������
};
// ����� Calendar
// ������������ ��� ������ � ����������
class Calendar
{
private:
	int DaysInMounth;    // ���������� ���� � ������� ������
	LocalData YMDInform; // ��������� � ������� � ������� ����
	int Days[31];        // ������ � �������� ����
	int DayOfWeek[31];   // ������ � �������� ���� ������
public:
	Calendar();          // �����������
	~Calendar();         // ����������
	static const int DayOfWeekCons(const char* date);
	// ����� ���������� ��������� LocalData � ������� � ������� ����
	LocalData GetLocalData();
	// ����� ������ ���������
	void CalendarOutput() const;
	void SetAfterWDays(int dofweek) { this->YMDInform.AfterWDays = dofweek; }
	// ����� ��������� �������� ���
	int GetDay() { return this->YMDInform.Day; };
	// ����� ��������� �������� ������
	int GetMounth() { return this->YMDInform.Mounth; };
	// ����� ��������� �������� ����
	int GetYear() { return this->YMDInform.Year; };
	// ����� ��������� �������� ��� ������
	int GetAfterWDays() { return this->YMDInform.AfterWDays; };
	// ����� ��������� ���������� �������� �������� ������
	char* GetCharMounth();
	char* GetCharMounth(int mounth);
	// ����� ��������� ���������� �������� �������� ��� ������

	char* GetCharDayOfWeek(const int num);

	char* GetCharDayOfWeek();

	// ���������� ��������� ������
	friend std::ostream& operator<<(std::ostream& out, const Calendar& nfobj);
	// ���������� ��������� �����
	friend std::istream& operator>>(std::istream& in, Calendar& nfobj);
};