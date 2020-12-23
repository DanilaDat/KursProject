#include"Notificatons.h"
Notifications::Notifications():GlobalInformation()
{
	this->RemFor = 0;
	this->Status = 0;
}
Notifications::~Notifications()
{
}
void Notifications::TablePrint(ostream& out) const
{
	for (int i = 1; i < this->GetInfoNumber(); i++)
	{
		out << setw(NfsDateSize + 1+NfsMaxRemForLen+NFSStatusSize) << ' '
			<< setw(GIStrLen) << left << this->GetInfo(i) << '\n';
	}
}
std::ostream& operator<<(std::ostream& out, const Notifications& nfobj)//����������� � ������� ��������� ������� �����
{
	out << setw(NfsDateSize + 1) << left << nfobj.Date
		<< setw(NfsMaxRemForLen) << left << nfobj.RemFor
		<< setw(NFSStatusSize) << left << (nfobj.Status == 1 ? "��������������" : "����������")
		<< setw(GIStrLen) << left << nfobj.GetInfo(0) << '\n';
	nfobj.TablePrint(out);
	return out;
}
std::istream& operator>>(std::istream& in, Notifications& nfobj) // ������: ���� �� ������ ��������� ���� ��� �����������, ��� ������� ��� "������"
{
	InputException inex;
	Calendar calendar;
	rewind(stdin);
	cout << "������� ����� �����������:\n";
	in >> dynamic_cast<GlobalInformation&>(nfobj);
	cout << "������� ����, � ������� ������ �������� �����������:\n"; // ����� �� ��������� ������ ����: ��������!!!!
	strcpy(nfobj.Date, inex.DateInput(calendar.GetYear() + 5, calendar.GetYear(), NfsDateSize));
	cout << "�� ������� ���� ���������?\n";
	nfobj.RemFor = inex.NumInput(NfsMaxRemFor, 0);
	cout << "�� ������ ����� ����������� ��������� ������ 1 ���?\n"
		<< "1 - ��\n" << "2 - ���\n";
	int choise = inex.NumInput(2, 1);
	if (choise == 1)
		nfobj.Status = 1; // �������������� �������
	else nfobj.Status = 0; // ������������� �������
	return in;
}

ofstream& operator<<(ofstream& out, Notifications& nfobj)
{
	out << dynamic_cast<GlobalInformation&>(nfobj)
		<< " " << nfobj.Date << " " << nfobj.RemFor << " " << nfobj.Status;
	return out;
}

ifstream& operator>>(ifstream& in, Notifications& nfobj)
{
	in >> dynamic_cast<GlobalInformation&>(nfobj)
		>> nfobj.Date >> nfobj.RemFor >> nfobj.Status;
	return in;
}