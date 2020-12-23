#include"TxtFile.h"
template <class T>
TxtFile<T>::TxtFile(char* filename) : File(filename){}

template <class T>
TxtFile<T>::~TxtFile()
{
	this->RClose();
	this->WClose();
}

template <class T>
bool TxtFile<T>::IsOpen(){
	return (this->inputstream.is_open() | this->outputstream.is_open());
}

template <class T>
bool TxtFile<T>::IsROpen(){
	return (this->inputstream.is_open());
}

template <class T>
bool TxtFile<T>::IsWOpen(){
	return (this->outputstream.is_open());
}

template <class T>
bool TxtFile<T>::IfEOF(){
	return (this->inputstream.eof());
}

template <class T>
bool TxtFile<T>::ROpen()
{
	this->inputstream.open(this->filename,ios::in);
	if (this->IsROpen())
		return true;
	else
	{
		cout << "Файл не открылся для чтения!\n";
		return false;
	}
}
template <class T>
bool TxtFile<T>::WOpen()
{
	this->outputstream.open(this->filename, ios::out);
	if (this->IsWOpen())
		return true;
	else
	{
		cout << "Файл не открылся для чтения!\n";
		return false;
	}
}

template <class T>
void TxtFile<T>::RClose()
{
	if (this->IsROpen())
		this->inputstream.close();
}
template <class T>
void TxtFile<T>::WClose()
{
	if (this->IsWOpen())
		this->outputstream.close();
}

template <class T>
void TxtFile<T>::Reading(T& obj)
{
	this->inputstream >> obj;
}
template <class T>
void TxtFile<T>::Writing(T& obj)
{
	this->outputstream << obj /*<< '\n'*/;
}