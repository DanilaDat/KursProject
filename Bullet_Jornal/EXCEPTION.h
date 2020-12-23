#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define EXPMR 80

// Родительский класс для блока обработки исключений 
class Exception
{
protected:
	char MistakeReport[EXPMR];             // Информация об исключении
public:
	virtual char* MistakeInformation() = 0;// Метод вывода информации об исклюении
};
// Класс InputException наследуется от Exception
// Предназначен для работы с исключениями ввода
class InputException : public Exception
{
public:
	// Возврат описания ошибки
	char* MistakeInformation() { return MistakeReport; };   
	InputException()                      // Конструктор
	{
		strcpy(this->MistakeReport, "Ошибка. Исключение ввода!");
	};                                                          
	InputException(char* MistakeReport)   // Деструктор
	{
		strcpy(this->MistakeReport, MistakeReport);
	} 
	// Проверка корректности ввода числа
	int NumInput(int maxsize, int minsize);                
	// Проверка корректности ввода даты
	char* DateInput(int maxyear, int minyear, int datesize);
};