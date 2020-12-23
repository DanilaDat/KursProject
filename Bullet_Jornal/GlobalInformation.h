#pragma once
#define _CRT_SECURE_NO_WARNING  // Разобраться с ошибками!!!!
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
	char Info[GIStr][GIStrLen];  // Массив строк
	int InfoNumber;              // Количество заполненных строк
public:
	// Конструктор
	GlobalInformation();         
	// Метод получения указателя на одну из строк массива
	const char* GetInfo(int i) const { return this->Info[i]; };
	// Метод получения количества заполненных строк
	const int GetInfoNumber() const { return this->InfoNumber; };
	// Метод изменения массива строк
	void SetInfo(char** info, int number) { 
		for (int i = 0; i < number; i++) 
			strcpy_s(this->Info[i], GIStrLen, info[i]);
		this->InfoNumber = number; };

	// Метод изменения количества заполненных строк
	void SetInfoNumber(int number) { this->InfoNumber = number; };
	// Деструктор
	virtual ~GlobalInformation();
	// Перегрузка оператора вывода
	friend ostream& operator<<(ostream& out, const GlobalInformation& nfobj);
	// Перегрузка оператора ввода
	friend istream& operator>>(istream& in, GlobalInformation& nfobj);


	friend ofstream& operator<<(ofstream& out, GlobalInformation& nfobj);
	friend ifstream& operator>>(ifstream& in, GlobalInformation& nfobj);
};