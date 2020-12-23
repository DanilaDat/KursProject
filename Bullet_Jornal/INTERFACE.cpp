#include "INTERFACE.h"
#include "CALENDAR.h"
#include "Notificatons.h"
#include"MonthPlans.h"
#include "HalfAYearPlan.h"
#include "Notes.h"
#include "Message.h"
// ���������������� ����
char Interface::StartScreen()
{
	Calendar calendar;
	cout << std::left << "������� ������� �����!" << endl << endl
		<< std::left << "������� " << std::left << std::setw(12)<< calendar.GetCharDayOfWeek()<< std::endl // ����� ��� ������
		<< std::setw(3) << std::left << calendar.GetDay() // ����� ���
		<< std::setw(8) << std::left << calendar.GetCharMounth() //����� �������� �������� ������
		<< std::setw(5) << std::left << calendar.GetYear()      // ����� ����
		<< " ����" << endl << endl;
	cout << calendar; // ����� ��������� ��� �������� ������
	std::cout << endl;
	char transition;
	cout  <<endl  <<"��� �������� � �������� ���� ������� >" << endl;
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
	int flag = 0;                                   // ����� �� ������������ ������ �������� � ����������
	int ActionSelection = 7;                        // ����� �������� �������������
	do
	{
		if (ActionSelection == 8)
			break;

		if (ActionSelection != 7)
		{
			cout << "��������� c ��� ��������:\n"           // ��������� ��� ������������
				<< "1 - ���������\n"
				<< "2 - �����������\n"
				<< "3 - ���������������� ���������\n"
				<< "4 - ������\n"
				<< "5 - �������� �����\n"
				<< "6 - ������������ �����\n"
				<< "7 - ��������� �� ��������� �����\n"
				<< "8 - ��������� ������\n";
			rewind(stdin);
			cin >> ActionSelection;        // ����� ��������� ���� � ������������  �������� ��������!!!
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




