#include "INTERFACE.h"
#include "CALENDAR.h"
#include "Notificatons.h"
#include"MonthPlans.h"
#include "HalfAYearPlan.h"
#include "Notes.h"
#include "Message.h"
// Пользовательское меню
char Interface::StartScreen()
{
	Calendar calendar;
	cout << std::left << "Доброго времени суток!" << endl << endl
		<< std::left << "Сегодня " << std::left << std::setw(12)<< calendar.GetCharDayOfWeek()<< std::endl // Вывод дня недели
		<< std::setw(3) << std::left << calendar.GetDay() // Вывод дня
		<< std::setw(8) << std::left << calendar.GetCharMounth() //Вывод названия текущего месяца
		<< std::setw(5) << std::left << calendar.GetYear()      // Вывод года
		<< " года" << endl << endl;
	cout << calendar; // Вывод календаря для текущего месяца
	std::cout << endl;
	char transition;
	cout  <<endl  <<"Для перехода в основное меню введите >" << endl;
	rewind(stdin);
	cin >> transition;
	return transition;
}

void Interface::menu()
{
	Ring<Calendar> calendar;
	char* calendartxt = (char*)"calendar.txt";
	Ring<Notifications> notifications;
	char* notificationstxt = (char*)"notifications.txt";
	Ring<Notes> notes;
	char* notestxt = (char*)"notes.txt";
	Ring<MonthPlan> monthplan;
	char* monthplantxt = (char*)"monthplan.txt";
	Ring<HalfAYearPlan> halfayearplan;
	char* halfayearplantxt = (char*)"halfayearplan.txt";
	Ring<Message> message;
	char* messagetxt = (char*)"message.txt";
	int flag = 0;                                   // Хочет ли пользователь дальше работать с программой
	int ActionSelection = 7;                        // Выбор действия пользователем
	do
	{
		if (ActionSelection == 8)
			break;

		if (ActionSelection != 7)
		{
			cout << "Выбирайте c чем работать:\n"           // Сообщение для пользователя
				<< "1 - Календарь\n"
				<< "2 - Напоминания\n"
				<< "3 - Запланированииые сообщения\n"
				<< "4 - Записи\n"
				<< "5 - Месячные планы\n"
				<< "6 - Полугодичные планы\n"
				<< "7 - Вернуться на стартовый экран\n"
				<< "8 - Завершить работу\n";
			rewind(stdin);
			cin >> ActionSelection;        // После написания лабы с исключениями  добавить проверку!!!
		}
			switch (ActionSelection)
			{
			case 1:{ actionchoise(calendar, calendartxt); break;}
			case 2:{actionchoise(notifications, notificationstxt); break;}
			case 3:{actionchoise(message,messagetxt); break;}
			case 4:{actionchoise(notes, notestxt); break;}
			case 5:{actionchoise(monthplan, monthplantxt);break;}
			case 6:{actionchoise(halfayearplan, halfayearplantxt);break;}
			case 7:	{
				if (this->StartScreen() == '>'){ActionSelection = 0;break;}
			}
			case 8:{flag = 1;break; }
			}
	} while (flag == 0);
}




