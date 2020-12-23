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
// Наследуется от класса GlobalInformation
// Предназначен для работы с уведомлениями пользователя
class Notifications: public GlobalInformation
{
private:
	int RemFor;              // За сколько дней необходимо напомнить
	char Date[NfsDateSize];  // Дата напоминания
	int Status;              // Статус напоминания
public:
	Notifications();         // Конструктор
	~Notifications();        // Деструктор
	void TablePrint(ostream& out) const;
	// Перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& out, const Notifications& nfobj);
	// Перешрузка оператора ввода
	friend std::istream& operator>>(std::istream& in,  Notifications& nfobj);

	friend ofstream& operator<<(ofstream& out, Notifications& nfobj);
	friend ifstream& operator>>(ifstream& in, Notifications& nfobj);
};