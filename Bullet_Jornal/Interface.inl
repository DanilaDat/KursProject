#include "INTERFACE.h"
template <typename T> 
void Interface::actionchoise(Ring<T>& ring, char* txtfilename)
{
	int actionchoise = 0;

	// �������� �� �����!!!
	// ������� � �������� � �������
/*
	T read;
	TxtFile<T> readfile(txtfilename);
	if(typeid(T)!=typeid(Message))
	if (readfile.ROpen())
		while (true) {
			readfile.Reading(read);
			ring.AddNode(read);
			if (readfile.IfEOF()) break;
		}
	if (typeid(T) == typeid(Message))
		if (readfile.ROpen())
			while (true) {
				readfile.Reading(read);
				if (readfile.IfEOF()) break;
				ring.AddNode(read);
			}
	*/

	while (actionchoise != 6)
	{
		cout << "��������� ��������:" << endl
			<< "1 - ��������" << endl
			<< "2 - �������" << endl
			<< "3 - �������������\n"
			<< "4 - �����������" << endl
			<< "5 - �������� ��������� ��������\n"
			<< "6 - �����" << endl;
		cin >> actionchoise;
		switch (actionchoise)
		{
		case 1:
		{
			cout << endl << "������� ����..." << endl;
			T obj;
			cin >> obj;
			ring.AddNode(obj);
			break;
		}
		case 2: {ring.CleanOut(); break; }// ������� ���� ������� ��� ���?
		case 3: {cout << endl; ring.RetrieveNode(); ring.RingOut(); cout << endl; break; } // �-��� ��������������
		case 4: {
			cout << endl; ring.RingOut(); cout << endl; break;
		}
		case 5: {
			// ������� ������ � ������� ����� 
			break; }
		case 6: {
			TxtFile<T> recfile(txtfilename);
			MyIterator<T> i = ring.begin();
			MyIterator<T> end = ring.end();
			if (end != NULL)
				++end;
			if (i != NULL)
				if (recfile.WOpen())
					do {
						recfile.Writing(*i);
						++i;
					} while (i != end); 
					ring.CleanOut();
					return; };
		}
	}	
}

template <> 
void Interface::actionchoise (Ring<Calendar>& ring, char* txtfilename)
{
	int actionchoise = 0;
	while (actionchoise != 2)
	{
		cout << "��������� ��������:" << endl
			<< "1 - ��������" << endl
			<< "2 - �����" << endl;
		cin >> actionchoise;
		switch (actionchoise)
		{
		case 1:
		{
			Calendar calendar;
			cout << calendar;
			break;
		}
		case 2: {return; }
		}
	}
}