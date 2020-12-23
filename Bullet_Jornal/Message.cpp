#include"Message.h"
Message::Message() :GlobalInformation()
{
	this->Date[0] = '\0';
}
Message::~Message()
{
}
void Message::TablePrint(ostream& out) const
{
	for (int i = 1; i < this->GetInfoNumber(); i++)
	{
		out << setw(NfsDateSize + 1) << ' ' ;
		out << setw(GIStrLen) << left << this->GetInfo(i);
		out << '\n';
	}
}
std::ostream& operator<<(ostream& out, const Message& msgobj)
{
	out << setw(NfsDateSize + 1) << left << msgobj.Date
		<< setw(GIStrLen) << left << msgobj.GetInfo(0) << '\n';
	msgobj.TablePrint(out);
	return out;
}
std::istream& operator>>(istream& in, Message& msgobj) 
{
	InputException inex;
	Calendar calendar;
	rewind(stdin);
	cout << "Введите текст запланированного сообщения:\n";
	in >> dynamic_cast<GlobalInformation&>(msgobj);
	cout << "Введите день, в который хотите получить запланированное сообщение:\n"; 
	strcpy(msgobj.Date, inex.DateInput(calendar.GetYear() + 5, calendar.GetYear(), NfsDateSize));
	return in;
}

ofstream& operator<<(ofstream& out, Message& msgobj)
{
	out << dynamic_cast<GlobalInformation&>(msgobj) << '\n'<<msgobj.Date << '\n';
	return out;
}

ifstream& operator>>(ifstream& in, Message& msgobj)
{
	in >> dynamic_cast<GlobalInformation&>(msgobj);
	in.get();
	in.getline(msgobj.Date,NfsDateSize,'\n');
	return in;
}
