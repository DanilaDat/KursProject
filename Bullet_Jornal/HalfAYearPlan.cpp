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
	cout << "¬ыбирайте идентификатор:\n"
		<< "'*' - задача, которую необходимо выполнить - 1\n"
		<< "'^' - встреча или событие - 2\n"
		<< "'-' - заметка - 3\n"
		<< "'&' - срочное дело - 4\n"
		<< "'!' - иде€, которую нужно не забыть - 5\n"
		<< "'#' - открыти€ за день - 6\n"
		<< "'~' - рецепт - 7\n";
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
	cout << "¬ыбирайте мес€ц:\n"
		<< "1 - январь\n"
		<< "2 - ‘евраль\n"
		<< "3 - ћарт\n"
		<< "4 - јпрель\n"
		<< "5 - ћай\n"
		<< "6 - »юнь\n"
		<< "7 - »юль\n"
		<< "8 - јвгуст\n"
		<< "9 - —ент€брь\n"
		<< "10 - ќкт€брь\n"
		<< "11 - Ќо€брь\n"
		<< "12 - ƒекабрь\n";
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
	cout << "¬ведите мес€ц, дл€ которого создаетс€ план\n" ; // —оздать проверку мес€цев!!!
	hypobj.MounthChose();
	rewind(stdin);
	cout << "¬ведите идентификатор записи:\n";
	hypobj.Identifier = hypobj.IdentifierChoise();
	rewind(stdin);
	cout << "¬ведите запись на мес€ц за эти полгода:\n" ; 
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