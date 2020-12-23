#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"GlobalInformation.h"
#include "EXCEPTION.h"
#include "CALENDAR.h"
#define NFSStatusSize 15
#define NfsDateSize 11
#define NfsMaxRemFor 365
#define NfsMaxRemForLen 4
using namespace std;
// ����������� �� ������ GlobalInformation
// ������������ ��� ������ � ������������� ������������
class Notifications: public GlobalInformation
{
private:
	int RemFor;              // �� ������� ���� ���������� ���������
	char Date[NfsDateSize];  // ���� �����������
	int Status;              // ������ �����������
public:
	Notifications();         // �����������
	~Notifications();        // ����������
	void TablePrint(ostream& out) const;
	// ���������� ��������� ������
	friend std::ostream& operator<<(std::ostream& out, const Notifications& nfobj);
	// ���������� ��������� �����
	friend std::istream& operator>>(std::istream& in,  Notifications& nfobj);

	friend ofstream& operator<<(ofstream& out, Notifications& nfobj);
	friend ifstream& operator>>(ifstream& in, Notifications& nfobj);
};