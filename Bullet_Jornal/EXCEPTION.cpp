#include "EXCEPTION.h"
int InputException::NumInput(int maxsize, int minsize)
{
	int fl = 0;
	int year;
	do
	{
		try
		{
			try
			{
				rewind(stdin);
				cin.clear();
				cin >> year;
				if (cin.get()!='\n')
					throw(InputException((char*)"������������ ����!"));
				if (year > maxsize || year < minsize)
					throw(InputException((char*)"������������ ��������!"));
			/*	throw "str";*/
				fl = 1; // ���� �������� ���������
			}
			catch (InputException& inexcp)
			{
				cout << inexcp.MistakeInformation() << endl << "��������� ����!" << endl;
			}
			catch (...)
			{
				cout << "�������� ���������� ����������!" << endl;
				throw;
			}
		}
		catch (...)
		{
			cout << "��������� �������������� ����������!" << endl;
			exit(0);
		}
	} while (fl == 0);
	return year;
}
char* InputException::DateInput(int maxsize, int minsize, int datesize)
{
	int fl = 0;
	char* str = new char [datesize];
	do
	{
		try
		{
			try
			{
				rewind(stdin);
				cin.clear();
				cin.getline(str, datesize);
				//char ResidueIn;
				//cin >> ResidueIn;
				//if (cin.peek() != '\n')                                          // ���� � ������ ���-�� ��������
				//	throw(InputException((char*)"������� �� ��� �������"));
				if (str[2] != '.' || str[5] != '.')
					throw(InputException((char*)"������������ ����!"));
				if (str[0] == '\0')                                                // ���� ������������ ������ �� ����
					throw(InputException((char*)"���������� ������ ������!"));
				for (int i = 0; i < strlen(str); i++)                              // ���� ���� �����-�� �������, ����� ���� � �����
					if ((str[i] < '0' || str[i]>'9') && str[i] != '.')
						throw(InputException((char*)"�������� ���� ������ �����"));
				char Cyear[5];                                                     // �������� ���������� ��������� ����
				for (int i = 0; i < 4; i++)
					Cyear[i] = str[i + 6];
				Cyear[4] = '\n';
				int Iyear = atoi(Cyear);

				if (Iyear<minsize || Iyear>maxsize)
					throw(InputException((char*)"������������ ���� ����!"));
				char Cmounth[3];
				for (int i = 0; i < 2; i++)
					Cmounth[i] = str[i + 3];
				Cmounth[2] = '\n';
				int Imounth = atoi(Cmounth);
				if (Imounth > 12 || Imounth <= 0)
					throw(InputException((char*)"������������ ���� ������!"));
				char CDay[3];
				for (int i = 0; i < 2; i++)
					CDay[i] = str[i];
				CDay[2] = '\n';
				int IDay = atoi(CDay);
				if (Imounth == 1 || 3 || 5 || 7 || 8 || 10 || 12)
				{
					if (IDay > 31 || IDay <= 0)
						throw(InputException((char*)"������������ ����!(��������� ���� ������ ���������� ��� ����� 0)"));
				}
				if (Imounth == 4 || 6 || 9 || 11)
				{
					if (IDay > 30 || IDay <= 0)
						throw(InputException((char*)"������������ ����!(��������� ���� ������ ���������� ��� ����� 0)"));
				}
				if (Imounth == 2)
				{
					if (Iyear % 4 == 0)
					{
						if (IDay > 29 || IDay == 0)
							throw(InputException((char*)"������������ ����!(��������� ���� ������ ���������� ��� ����� 0)"));
					}
					else
						if (IDay > 28 || IDay == 0)
							throw(InputException((char*)"������������ ����!(��������� ���� ������ ���������� ��� ����� 0)"));
				}
				fl = 1;                                                            // ���� �������� ���������
			}
			catch (InputException& inexcp)
			{
				cout << inexcp.MistakeInformation() << endl << "��������� ����!" << endl;
			}
			catch (...)
			{
				cout << "�������� ���������� ����������!" << endl;
				throw;
			}
		}
		catch (...)
		{
			cout << "��������� �������������� ����������!" << endl;
			exit(0);
		}

	} while (fl == 0);
	return str;
}
