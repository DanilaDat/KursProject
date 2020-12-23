#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"GlobalInformation.h"
#include "EXCEPTION.h"
#include "CALENDAR.h"
#define NfsDateSize 11
#define NfsMaxRemFor 365
#define NfsMaxRemForLen 4
using namespace std;
// ����������� �� ������ GlobalInformation
// ������������ ��� ������ � ������������� ������������
class Message : public GlobalInformation
{
private:
	char Date[NfsDateSize];  // ���� ���������
public:
	Message();         // �����������
	~Message();        // ����������
	void TablePrint(ostream& out) const ;
	// ���������� ��������� ������
	friend std::ostream& operator<<(ostream& out, const Message& msgobj);
	// ���������� ��������� �����
	friend std::istream& operator>>(istream& in, Message& msgobj);

	friend ofstream& operator<<(ofstream& out, Message& msgobj);
	friend ifstream& operator>>(ifstream& in, Message& msgobj);
};
