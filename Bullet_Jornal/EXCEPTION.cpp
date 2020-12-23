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
					throw(InputException((char*)"Недопустимый ввод!"));
				if (year > maxsize || year < minsize)
					throw(InputException((char*)"Недопустимое значение!"));
			/*	throw "str";*/
				fl = 1; // Ввод совершен корректно
			}
			catch (InputException& inexcp)
			{
				cout << inexcp.MistakeInformation() << endl << "Повторите ввод!" << endl;
			}
			catch (...)
			{
				cout << "Сработал абсолютный обработчик!" << endl;
				throw;
			}
		}
		catch (...)
		{
			cout << "Сработало переопределние исключений!" << endl;
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
				//if (cin.peek() != '\n')                                          // Если в потоке что-то осталось
				//	throw(InputException((char*)"Считаны не все символы"));
				if (str[2] != '.' || str[5] != '.')
					throw(InputException((char*)"Некорректный ввод!"));
				if (str[0] == '\0')                                                // Если пользователь ничего не ввел
					throw(InputException((char*)"Необходимо ввести данные!"));
				for (int i = 0; i < strlen(str); i++)                              // Если есть какие-то символы, кроме цифр и точек
					if ((str[i] < '0' || str[i]>'9') && str[i] != '.')
						throw(InputException((char*)"Разрешен ввод только чисел"));
				char Cyear[5];                                                     // Проверка реальности введенной даты
				for (int i = 0; i < 4; i++)
					Cyear[i] = str[i + 6];
				Cyear[4] = '\n';
				int Iyear = atoi(Cyear);

				if (Iyear<minsize || Iyear>maxsize)
					throw(InputException((char*)"Некорректный ввод года!"));
				char Cmounth[3];
				for (int i = 0; i < 2; i++)
					Cmounth[i] = str[i + 3];
				Cmounth[2] = '\n';
				int Imounth = atoi(Cmounth);
				if (Imounth > 12 || Imounth <= 0)
					throw(InputException((char*)"Некорректный ввод месяца!"));
				char CDay[3];
				for (int i = 0; i < 2; i++)
					CDay[i] = str[i];
				CDay[2] = '\n';
				int IDay = atoi(CDay);
				if (Imounth == 1 || 3 || 5 || 7 || 8 || 10 || 12)
				{
					if (IDay > 31 || IDay <= 0)
						throw(InputException((char*)"Некорректный день!(Введенный день больше возможного или равен 0)"));
				}
				if (Imounth == 4 || 6 || 9 || 11)
				{
					if (IDay > 30 || IDay <= 0)
						throw(InputException((char*)"Некорректный день!(Введенный день больше возможного или равен 0)"));
				}
				if (Imounth == 2)
				{
					if (Iyear % 4 == 0)
					{
						if (IDay > 29 || IDay == 0)
							throw(InputException((char*)"Некорректный день!(Введенный день больше возможного или равен 0)"));
					}
					else
						if (IDay > 28 || IDay == 0)
							throw(InputException((char*)"Некорректный день!(Введенный день больше возможного или равен 0)"));
				}
				fl = 1;                                                            // Ввод совершен корректно
			}
			catch (InputException& inexcp)
			{
				cout << inexcp.MistakeInformation() << endl << "Повторите ввод!" << endl;
			}
			catch (...)
			{
				cout << "Сработал абсолютный обработчик!" << endl;
				throw;
			}
		}
		catch (...)
		{
			cout << "Сработало переопределние исключений!" << endl;
			exit(0);
		}

	} while (fl == 0);
	return str;
}
