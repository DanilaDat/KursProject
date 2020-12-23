#include"MonthPlans.h"
MonthPlan::MonthPlan():Notes()
{
	this->DayOfWeek = 0;
}
MonthPlan::~MonthPlan()
{
}

void MonthPlan::TablePrint(std::ostream& out) const
{
	for (int i = 1; i < this->GetInfoNumber(); i++)
	{
		out << setw(MPDofWLen+NfsDateSize + 1 + IDFSize) << ' ' << setw(GIStrLen) << left << this->GetInfo(i) << '\n';
	}
}
std::ostream& operator<<(std::ostream& out, const MonthPlan& mplobj)
{
	Calendar obj;
	out << setw(MPDofWLen) << left << obj.GetCharDayOfWeek(mplobj.GetDayOfWeek())
		<< setw(NfsDateSize + 1) << left << mplobj.GetDate()
		<< setw(IDFSize) << left << mplobj.IdentifierBack()
		<< setw(GIStrLen) << left << mplobj.GetInfo(0) << '\n';
	mplobj.TablePrint(out);
	return out;
}
std::istream& operator>>(std::istream& in, MonthPlan& mplobj)
{
	Calendar calendar;
	in >> dynamic_cast<Notes&>(mplobj);// ѕодумать над изменением записи в Notes(все же это не заметка а план на мес€ц)
	 mplobj.DayOfWeek = calendar.DayOfWeekCons(mplobj.GetDate());  // ‘-ци€ ввода дн€ недели! (или по дате определить день недели???)
	return in;
}


ofstream& operator<<(ofstream& out, MonthPlan& mplobj)
{
	out << dynamic_cast<Notes&>(mplobj)
		<< mplobj.DayOfWeek << ' ';
	return out;
}

ifstream& operator>>(ifstream& in, MonthPlan& mplobj)
{
	in >> dynamic_cast<Notes&>(mplobj)
		>> mplobj.DayOfWeek;
	return in;
}