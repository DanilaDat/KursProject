#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"GlobalInformation.h"
#include "CALENDAR.h"
#include "EXCEPTION.h"
#include "Notificatons.h"
using namespace std;
// Наследуется от класса GlobalInformation
class Notes :public GlobalInformation
{
private:
	int Identifier;       // Иденификатро записи
	char Date[11];        // Дата записи
public:
	Notes();              // Конструктор
	~Notes();             // Деструктор
	int IdentifierChoise();
	const char IdentifierBack() const;
	const char* GetDate()const  { return this->Date; };
	const int GetIdentifier() const { return this->Identifier; };
	void SetDate(char* date) { strcpy(this->Date, date); };
	void SetIdentifier(int identifier) { this->Identifier = identifier; };
	// Вывод массива строк
	 void TablePrint (std::ostream& out) const;
	// Перегрузка оператора ввывода
	friend std::ostream& operator<<(std::ostream& out, const Notes& nfobj);
	// Перегрузка оператора ввода
	friend std::istream& operator>>(std::istream& in, Notes& nfobj);


	friend ofstream& operator<<(ofstream& out, Notes& nfobj);
	friend ifstream& operator>>(ifstream& in, Notes& nfobj);
};