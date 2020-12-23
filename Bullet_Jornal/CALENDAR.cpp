#include "CALENDAR.h"
Calendar::Calendar()
{	
	this->YMDInform = GetLocalData();
	if (this->YMDInform.Mounth == 1 || 3 || 5 || 7 || 8 || 10 || 12) //���� � ������ 31 ����
		this->DaysInMounth = 31;
	if (this->YMDInform.Mounth == 4 || 6 || 9 || 11) // ���� � ������ 30 ����
		this->DaysInMounth = 30;
	if (this->YMDInform.Mounth == 2) // ���� � ������ 28 ��� 29 ����
		if (this->YMDInform.Year % 4 == 0)
			this->DaysInMounth = 29;
		else
			this->DaysInMounth = 28;
	for (int i = 0; i < this->DaysInMounth; i++) // ���������� ������� ���� � ������
		this->Days[i] = i + 1;
	int ApD = this->YMDInform.Day - 1;
	int ApWD = this->YMDInform.AfterWDays - 1;
	while (ApD > 1)             // ���������� ��� ������ ������� ��� � ������
	{
		ApD--;
		if (ApWD != 0)
			ApWD--;
		else
			ApWD = 6;
	}
	int i = 0;
	while (i < this->DaysInMounth)// � ���� ���� ����� �������� �����
	{
			this->DayOfWeek[i] = ApWD;
			i++;
		if (ApWD != 6)
			ApWD++;
		else
			ApWD = 0;
	}
}
char* Calendar::GetCharDayOfWeek(const int num)
{
	switch (num)
	{
	case 1: {return (char*)"�����������"; }
	case 2: {return (char*)"�������"; }
	case 3: {return (char*)"�����"; }
	case 4: {return (char*)"�������"; }
	case 5: {return (char*)"�������"; }
	case 6: {return (char*)"�������"; }
	case 0: {return (char*)"�����������"; }
	}
}
const int Calendar::DayOfWeekCons(const char* date) 
{
	char str[5];
	for (int i = 6; i < 10; i++)
		str[i - 6] = date[i];
	str[4] = '\0';
	int Year = atoi(str);
	for (int i = 8; i < 10; i++)
		str[i - 8] = date[i];
	str[2] = '\0';
	int f2year = atoi(str);
	for(int i=3;i<5;i++)
		str[i - 3] = date[i];
	str[2] = '\0';
	int mounth = atoi(str);
	for (int i = 0; i < 3; i++)
		str[i] = date[i];
	str[2] = '\0';
	int day = atoi(str);
	int YearCode = (f2year / 4) + 1 + f2year;
	int MounthCode = 0;
	switch (mounth){
	case 1: {
		if (Year % 4 != 0)
			MounthCode = 5;
		else
			MounthCode = 4;
		break; }
	case 2: {
		if (Year % 4 != 0)
			MounthCode = 1;
		else
			MounthCode = 0;
		break; }
	case 3: {MounthCode = 1; break; }
	case 4: {MounthCode = 4; break; }
	case 5: {MounthCode = 6; break; }
	case 6: {MounthCode = 2; break; }
	case 7: {MounthCode = 4; break; }
	case 8: {MounthCode = 0; break; }
	case 9: {MounthCode = 3; break; }
	case 10: {MounthCode = 5; break; }
	case 11: {MounthCode = 1; break; }
	case 12: {MounthCode = 3; break; }
	}
	int dayofweek = ((day + MounthCode + YearCode) % 7);
	return dayofweek;
}
Calendar::~Calendar()
{
}
LocalData Calendar::GetLocalData()          //������� �������� ��������� ����������
{
	LocalData ReturningValue;               // ������������ ��������� � ������������ �������
	time_t Now = time(0);                   // ��������� ���� � ������� ������������ �������
	tm *LocalTime = localtime(&Now);        // �������������� ���� � ������� � ��������� ���� � �������
	// ������ ������ ���� � ������������ ���������
	ReturningValue.Year = LocalTime->tm_year + 1900;// ��� ��� ���������� �������� - ��� ����� 1900, ���������  1900 ��� ����������� �����������
	ReturningValue.Mounth = LocalTime->tm_mon +1; // ��� ��� ���������� �������� ������ ���������� � 0 ��� ����������� ���������� �������� 1
	ReturningValue.Day = LocalTime->tm_mday;
	ReturningValue.AfterWDays = LocalTime->tm_wday;
	return ReturningValue;
}
void Calendar::CalendarOutput() const
{
	cout << setw(3) << "��" << setw(3) << "��" 
		<< setw(3) << "��" << setw(3) << "��" 
		<< setw(3) << "��" << setw(3) << "��" 
		<< setw(3) << "��" << endl;
	this->DayOfWeek[0] == 0 ? cout << setw(((this->DayOfWeek[0]+6) * 3)) << " " : // ����� �������� ��� ������ ����
		cout << setw(((this->DayOfWeek[0]-1) * 3)) << " ";

	int i = 0;
	for (int y = 0; y < (this->DayOfWeek[0]==0? 1:(8-this->DayOfWeek[0])); y++) // ����� ���� ������ ������ ������
	{
		//if (this->Days[i] == this->YMDInform.Day)
		//{
		//	cout << setw(3) << this->Days[i];   // �������� ����!!!
		//}
		//else
		cout << setw(3) << this->Days[y];
		i++;                          //����������� ���������� ���� ������ ������ ������, ������� �� ������
	}

	int flg = 0;
	for (int WNum = 0; WNum < 5; WNum++)  // ���� �� ������ ��������� ���� ������
	{
		cout << endl;
		for (int t = 0; t < 7; t++)
		{
			if (this->Days[i]==this->DaysInMounth)
			{
				cout << setw(3) << this->Days[i];
				flg = 1;
				break;
			}
			//if (this->Days[i] == this->YMDInform.Day)
			//{
			//	cout << setw(3) << this->Days[i];   // �������� ����!!!
			//}
			//else
			cout << setw(3) << this->Days[i];
			i++;
		}
		if (flg == 1) break;
	}
}    
char* Calendar::GetCharMounth()
{
	switch (this->YMDInform.Mounth)
	{
	case 1: {return (char*)"������"; }
	case 2: {return (char*)"�������"; }
	case 3: {return (char*)"�����"; }
	case 4: {return (char*)"������"; }
	case 5: {return (char*)"���"; }
	case 6: {return (char*)"����"; }
	case 7: {return (char*)"����"; }
	case 8: {return (char*)"�������"; }
	case 9: {return (char*)"��������"; }
	case 10: {return (char*)"�������"; }
	case 11: {return (char*)"������"; }
	case 12: {return (char*)"�������"; }
	}
}
char* Calendar::GetCharMounth(int mounth)
{
	switch (mounth)
	{
	case 1: {return (char*)"������"; }
	case 2: {return (char*)"�������"; }
	case 3: {return (char*)"�����"; }
	case 4: {return (char*)"������"; }
	case 5: {return (char*)"���"; }
	case 6: {return (char*)"����"; }
	case 7: {return (char*)"����"; }
	case 8: {return (char*)"�������"; }
	case 9: {return (char*)"��������"; }
	case 10: {return (char*)"�������"; }
	case 11: {return (char*)"������"; }
	case 12: {return (char*)"�������"; }
	}
}
char* Calendar::GetCharDayOfWeek()
{
	switch (this->YMDInform.AfterWDays)
	{
	case 1: {return (char*)"�����������"; }
	case 2: {return (char*)"�������"; }
	case 3: {return (char*)"�����"; }
	case 4: {return (char*)"�������"; }
	case 5: {return (char*)"�������"; }
	case 6: {return (char*)"�������"; }
	case 0: {return (char*)"�����������"; }
	}
}
std::ostream& operator<<(std::ostream& out, const Calendar& nfobj)
{
	nfobj.CalendarOutput();
	return out;
}
std::istream& operator>>(std::istream& in, Calendar& nfobj)
{
	return in;
}

