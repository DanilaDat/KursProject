#include"HalfAYearPlan.h"
HalfAYearPlan::HalfAYearPlan() :GlobalInformation()
{
	this->Identifier = 0;
	this->Mounth = 0;
}
HalfAYearPlan::~HalfAYearPlan()
{
}
int HalfAYearPlan::IdentifierChoise()
{
	cout << "��������� �������������:\n"
		<< "'*' - ������, ������� ���������� ��������� - 1\n"
		<< "'^' - ������� ��� ������� - 2\n"
		<< "'-' - ������� - 3\n"
		<< "'&' - ������� ���� - 4\n"
		<< "'!' - ����, ������� ����� �� ������ - 5\n"
		<< "'#' - �������� �� ���� - 6\n"
		<< "'~' - ������ - 7\n";
	InputException exc;
	return exc.NumInput(7, 1);
}
const char HalfAYearPlan::IdentifierBack() const
{
	switch (this->Identifier)
	{
	case 1: {return '*'; }
	case 2: {return '^'; }
	case 3: {return '-'; }
	case 4: {return '&'; }
	case 5: {return '!'; }
	case 6: {return '#'; }
	case 7: {return '~'; }
	}
}
void HalfAYearPlan::TablePrint(std::ostream& out) const
{
	for (int i = 1; i < this->GetInfoNumber(); i++)
	{
		out << setw(HAYPMounthLen + IDFSize) << ' ' << setw(GIStrLen) << left << this->GetInfo(i) << '\n';
	}
}
int HalfAYearPlan::MounthChose()
{
	InputException inexc;
	cout << "��������� �����:\n"
		<< "1 - ������\n"
		<< "2 - �������\n"
		<< "3 - ����\n"
		<< "4 - ������\n"
		<< "5 - ���\n"
		<< "6 - ����\n"
		<< "7 - ����\n"
		<< "8 - ������\n"
		<< "9 - ��������\n"
		<< "10 - �������\n"
		<< "11 - ������\n"
		<< "12 - �������\n";
	this->Mounth = inexc.NumInput(12, 1);
	return  this->Mounth;
}
std::ostream& operator<<(std::ostream& out, const HalfAYearPlan& hypobj)
{
	Calendar calendar;
	int mounth = hypobj.Mounth;
	out << setw(HAYPMounthLen) <<left << calendar.GetCharMounth(mounth)
		<< setw(IDFSize) << left << hypobj.IdentifierBack()
		<< setw(GIStrLen) << left << hypobj.GetInfo(0) << '\n';
	hypobj.TablePrint(out);
	return out;
}
std::istream& operator>>(std::istream& in, HalfAYearPlan& hypobj)
{
	rewind(stdin);
	cout << "������� �����, ��� �������� ��������� ����\n" ; // ������� �������� �������!!!
	hypobj.MounthChose();
	rewind(stdin);
	cout << "������� ������������� ������:\n";
	hypobj.Identifier = hypobj.IdentifierChoise();
	rewind(stdin);
	cout << "������� ������ �� ����� �� ��� �������:\n" ; 
	in >> dynamic_cast<GlobalInformation&>(hypobj);
	return in;
}
ofstream& operator<<(ofstream& out, HalfAYearPlan& hypobj)
{
	out << dynamic_cast<GlobalInformation&>(hypobj)
		<< hypobj.Identifier << ' ' << hypobj.Mounth << ' ';
	return out;
}

ifstream& operator>>(ifstream& in, HalfAYearPlan& hypobj)
{
	in >> dynamic_cast<GlobalInformation&>(hypobj)
		>> hypobj.Identifier >> hypobj.Mounth ;
	return in;
}