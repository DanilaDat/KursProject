#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define EXPMR 80

// ������������ ����� ��� ����� ��������� ���������� 
class Exception
{
protected:
	char MistakeReport[EXPMR];             // ���������� �� ����������
public:
	virtual char* MistakeInformation() = 0;// ����� ������ ���������� �� ���������
};
// ����� InputException ����������� �� Exception
// ������������ ��� ������ � ������������ �����
class InputException : public Exception
{
public:
	// ������� �������� ������
	char* MistakeInformation() { return MistakeReport; };   
	InputException()                      // �����������
	{
		strcpy(this->MistakeReport, "������. ���������� �����!");
	};                                                          
	InputException(char* MistakeReport)   // ����������
	{
		strcpy(this->MistakeReport, MistakeReport);
	} 
	// �������� ������������ ����� �����
	int NumInput(int maxsize, int minsize);                
	// �������� ������������ ����� ����
	char* DateInput(int maxyear, int minyear, int datesize);
};