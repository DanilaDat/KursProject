#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include"Notes.h"
#define MPDofWLen 14
using namespace std;
// Наследуется от класса Notes
// Предназначен для работы с планами пользователя на месяц
class MonthPlan : public Notes
{
private:
	int DayOfWeek; // День недели для которого создан план // Определение дл=ня недели
public:
	MonthPlan();   // Конструктор
	~MonthPlan();  // Деструктор
	void TablePrint(ostream& out) const;
	const int GetDayOfWeek() const { return this->DayOfWeek; };
	// Перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& out, const MonthPlan& mplobj);
	// Перегрузка оператора ввода
	friend std::istream& operator>>(std::istream& in, MonthPlan& mplobj);

	friend ofstream& operator<<(ofstream& out, MonthPlan& mplobj);
	friend ifstream& operator>>(ifstream& in, MonthPlan& mplobj);
};