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
// Наследуется от класса GlobalInformation
// Предназначен для работы с уведомлениями пользователя
class Message : public GlobalInformation
{
private:
	char Date[NfsDateSize];  // Дата сообщения
public:
	Message();         // Конструктор
	~Message();        // Деструктор
	void TablePrint(ostream& out) const ;
	// Перегрузка оператора вывода
	friend std::ostream& operator<<(ostream& out, const Message& msgobj);
	// Перешрузка оператора ввода
	friend std::istream& operator>>(istream& in, Message& msgobj);

	friend ofstream& operator<<(ofstream& out, Message& msgobj);
	friend ifstream& operator>>(ifstream& in, Message& msgobj);
};
