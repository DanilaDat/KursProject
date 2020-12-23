#include "INTERFACE.h"
template <typename T> 
void Interface::actionchoise(Ring<T>& ring, char* txtfilename)
{
	int actionchoise = 0;

	// Добавить из файла!!!
	// Считать и закинуть в очередь
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
		cout << "Выбирайте действие:" << endl
			<< "1 - Добавить" << endl
			<< "2 - Удалить" << endl
			<< "3 - Редактировать\n"
			<< "4 - Просмотреть" << endl
			<< "5 - Отменить последнее действие\n"
			<< "6 - Выйти" << endl;
		cin >> actionchoise;
		switch (actionchoise)
		{
		case 1:
		{
			cout << endl << "Введите узел..." << endl;
			T obj;
			cin >> obj;
			ring.AddNode(obj);
			break;
		}
		case 2: {ring.CleanOut(); break; }// Удалить один элемент или все?
		case 3: {cout << endl; ring.RetrieveNode(); ring.RingOut(); cout << endl; break; } // Ф-ция редактирования
		case 4: {
			cout << endl; ring.RingOut(); cout << endl; break;
		}
		case 5: {
			// Сделать отмену с помощью стека 
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
		cout << "Выбирайте действие:" << endl
			<< "1 - Добавить" << endl
			<< "2 - Выйти" << endl;
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