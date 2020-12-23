#pragma once
#define _CRT_SECURE_NO_WARNING  // ����������� � ��������!!!!
#include <cstdio>
#include <Windows.h>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#define GIStr 10
#define GIStrLen 80
#define IDFSize 2
//#define IdentifierSize 2

using namespace std;

class GlobalInformation          
{
private:
	char Info[GIStr][GIStrLen];  // ������ �����
	int InfoNumber;              // ���������� ����������� �����
public:
	// �����������
	GlobalInformation();         
	// ����� ��������� ��������� �� ���� �� ����� �������
	const char* GetInfo(int i) const { return this->Info[i]; };
	// ����� ��������� ���������� ����������� �����
	const int GetInfoNumber() const { return this->InfoNumber; };
	// ����� ��������� ������� �����
	void SetInfo(char** info, int number) { 
		for (int i = 0; i < number; i++) 
			strcpy_s(this->Info[i], GIStrLen, info[i]);
		this->InfoNumber = number; };

	// ����� ��������� ���������� ����������� �����
	void SetInfoNumber(int number) { this->InfoNumber = number; };
	// ����������
	virtual ~GlobalInformation();
	// ���������� ��������� ������
	friend ostream& operator<<(ostream& out, const GlobalInformation& nfobj);
	// ���������� ��������� �����
	friend istream& operator>>(istream& in, GlobalInformation& nfobj);


	friend ofstream& operator<<(ofstream& out, GlobalInformation& nfobj);
	friend ifstream& operator>>(ifstream& in, GlobalInformation& nfobj);
};