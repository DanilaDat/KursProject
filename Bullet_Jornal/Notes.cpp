#include"Notes.h"
Notes::Notes():GlobalInformation()
{
	this->Date[0] = '\0';
	this->Identifier = 0;
}
Notes::~Notes()
{
}
int Notes::IdentifierChoise()
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
const char Notes::IdentifierBack() const
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
void Notes::TablePrint(std::ostream& out) const
{
	for (int i = 1; i < this->GetInfoNumber(); i++)
	{
		out << setw(NfsDateSize + 1 + IDFSize) << ' ' << setw(GIStrLen) << left << this->GetInfo(i) << '\n';
	}
}
std::ostream& operator<<(std::ostream& out, const Notes& nfobj)
{
	out << setw(NfsDateSize + 1) << left << nfobj.Date
		<< setw(IDFSize) << left << nfobj.IdentifierBack()
		<< setw(GIStrLen) << left << nfobj.GetInfo(0) << '\n';
	nfobj.TablePrint(out);
	return out;
}
std::istream& operator>>(std::istream& in, Notes& nfobj)
{
	InputException inex;
	Calendar calendar;
	rewind(stdin);
	cout << "������� ����� �������:\n";
	in >> dynamic_cast<GlobalInformation&>(nfobj);
	cout << "������� ����, ��� ������� ������������� �������:\n"; // ����� �� ��������� ������ ����: ��������!!!!
	strcpy(nfobj.Date, inex.DateInput(calendar.GetYear() + 5, calendar.GetYear(), NfsDateSize));
	nfobj.Identifier = nfobj.IdentifierChoise();            // �-��� ����� ��������������
	rewind(stdin);
	return in;
}

ofstream& operator<<(ofstream& out, Notes& nfobj)
{
	out << dynamic_cast<GlobalInformation&>(nfobj)
		<< nfobj.Identifier << ' ' << nfobj.Date << ' ';
	return out;
}

ifstream& operator>>(ifstream& in, Notes& nfobj)
{
	in >> dynamic_cast<GlobalInformation&>(nfobj)
		>> nfobj.Identifier >> nfobj.Date;
	return in;
}