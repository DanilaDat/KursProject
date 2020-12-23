#include"GlobalInformation.h"

GlobalInformation::GlobalInformation()
{
	for (int i = 0; i < GIStr; i++)
		this->Info[i][0] = '\0';
	this->InfoNumber = 0;
}
GlobalInformation::~GlobalInformation() //Проверка на наличие указателя
{
}
ostream& operator<<(ostream& out, const GlobalInformation& nfobj)
{
	for (int i = 0; i < GIStr; i++)
	{
		if (nfobj.Info[i][0] == '\0')
			break;
		out << nfobj.Info[i] << '\n';
	}
	return out;
}
istream& operator>>(istream& in, GlobalInformation& nfobj)
{
	char buf[GIStrLen];
	int i = 0;
	while (buf[0] != '\0' && i < GIStr)
	{
		rewind(stdin);
		in.getline(buf, GIStrLen);
		strcpy_s(nfobj.Info[i], GIStrLen, buf);
		i++;
	} 
	nfobj.InfoNumber = i - 1;
	for (int i = nfobj.InfoNumber; i < GIStr; i++)
		nfobj.Info[i][0] = '\0';

	return in;
 }




ofstream& operator<<(ofstream& out, GlobalInformation& nfobj)
{
	for (int i = 0; i < GIStr; i++)
		out  << nfobj.Info[i] << '\n';
		out << nfobj.InfoNumber;
	return out;
}

ifstream& operator>>(ifstream& in, GlobalInformation& nfobj)
{
	for (int i = 0; i < GIStr; i++)
		in.getline(nfobj.Info[i], GIStrLen,'\n');
	in >> nfobj.InfoNumber;
	return in;
}