#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
//Структура с данными необходимыми классу Calendar
struct LocalData
{
	int Day;        // День
	int Mounth;     // Номер месяца
	int Year;       // Год
	int AfterWDays; // День недели
};
// Класс Calendar
// Предназначен для работы с календарем
class Calendar
{
private:
	int DaysInMounth;    // Количество дней в текущем месяце
	LocalData YMDInform; // Структура с данными о текущей дате
	int Days[31];        // Массив с номерами дней
	int DayOfWeek[31];   // Массив с номерами дней недель
public:
	Calendar();          // Конструктор
	~Calendar();         // Деструктор
	static const int DayOfWeekCons(const char* date);
	// Метод заполнения структуры LocalData с данными о текущей дате
	LocalData GetLocalData();
	// Метод вывода календаря
	void CalendarOutput() const;
	void SetAfterWDays(int dofweek) { this->YMDInform.AfterWDays = dofweek; }
	// Метод получения текущего дня
	int GetDay() { return this->YMDInform.Day; };
	// Метод получения текущего месяца
	int GetMounth() { return this->YMDInform.Mounth; };
	// Метод получения текущего года
	int GetYear() { return this->YMDInform.Year; };
	// Метод получения текущего дня недели
	int GetAfterWDays() { return this->YMDInform.AfterWDays; };
	// Метод получения текстового варианта текущего месяца
	char* GetCharMounth();
	char* GetCharMounth(int mounth);
	// Метод получения текстового варианта текущего дня недели

	char* GetCharDayOfWeek(const int num);

	char* GetCharDayOfWeek();

	// Перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& out, const Calendar& nfobj);
	// Перегрузка оператора ввода
	friend std::istream& operator>>(std::istream& in, Calendar& nfobj);
};