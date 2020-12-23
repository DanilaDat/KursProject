#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"Notes.h"
#define HAYPMounthLen 13
using namespace std;
// Наследуется от класса GlobalInformation
// Предназначен для работы с планами пользователя
// на полгода
class HalfAYearPlan :public GlobalInformation
{
private:
	int Mounth; // Название месяца, для которого записан план  (проверить длинну самого большого)
	int Identifier;             // Идентификатор плана
public:
	HalfAYearPlan();            // Конструктор 
	~HalfAYearPlan();           // Деструктор
	const char IdentifierBack() const;
	int IdentifierChoise();
	void TablePrint(std::ostream& out) const;
	int MounthChose();
	// Перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& out, const HalfAYearPlan& hypobj);
	// Перегрузка оператора ввода
	friend std::istream& operator>>(std::istream& in, HalfAYearPlan& hypobj);

	friend ofstream& operator<<(ofstream& out, HalfAYearPlan& hyobj);
	friend ifstream& operator>>(ifstream& in, HalfAYearPlan& hyobj);
};
