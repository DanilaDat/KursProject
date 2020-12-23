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
	cout << "Выбирайте идентификатор:\n"
		<< "'*' - задача, которую необходимо выполнить - 1\n"
		<< "'^' - встреча или событие - 2\n"
		<< "'-' - заметка - 3\n"
		<< "'&' - срочное дело - 4\n"
		<< "'!' - идея, которую нужно не забыть - 5\n"
		<< "'#' - открытия за день - 6\n"
		<< "'~' - рецепт - 7\n";
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
	cout << "Введите текст заметки:\n";
	in >> dynamic_cast<GlobalInformation&>(nfobj);
	cout << "Введите дату, для которой предназначена заметка:\n"; // Чтобы не вводились старые даты: Проверка!!!!
	strcpy(nfobj.Date, inex.DateInput(calendar.GetYear() + 5, calendar.GetYear(), NfsDateSize));
	nfobj.Identifier = nfobj.IdentifierChoise();            // Ф-ция ввода идентификатора
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