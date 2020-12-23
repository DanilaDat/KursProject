#include "MyIterator.h"
template <class T>
T& MyIterator<T>::operator*()
{
	return this->following->information;
}
template <class T>
MyIterator<T> MyIterator<T>::operator+(int position)
{
	MyIterator<T> interim = this->following;
	for (int i = 0; i < position; i++)
		interim++;
	return interim;
}
template <class T>
MyIterator<T> MyIterator<T>::operator-(int position)
{
	MyIterator<T> interim = this->following;
	for (int i = 0; i < position; i++)
		interim--;
	return interim;
}
template <class T>
MyIterator<T> MyIterator<T>::operator+=(int position)
{
	this = this + position;
	return this;
}
template <class T>
MyIterator<T> MyIterator<T>::operator-=(int position)
{
	this = this - position;
	return this;
}
template <class T>
void MyIterator<T>::operator++()
{
	this->following = this->following->next;
}
template <class T>
void MyIterator<T>::operator--()
{
	this->following = this->following->prev;
}
template <class T>
void MyIterator<T>::operator=(T equal)
{
	this->following->information = equal;
}
template <class T>
void MyIterator<T>::operator=(NodeRing<T>* equal)
{
	this->following->information = equal->information;
}
template <class T>
void  MyIterator<T>::operator=(MyIterator<T>& equal)
{
	this->following->information = equal.following->information;
}
template <class T>
bool MyIterator<T>::operator== (NodeRing<T>* comparable)
{
	if (this->following == comparable)
		return true;
	return false;
}
template <class T>
bool MyIterator<T>::operator==(MyIterator<T>& comparable)
{
	if (this->following->information == comparable.following->information)
		return true;
	return false;
}
template <class T>
bool MyIterator<T>::operator!=(NodeRing<T>* comparable)
{
	if (this->following != comparable)
		return true;
	return false;
}
template <class T>
bool MyIterator<T>::operator!=(MyIterator<T>& comparable)
{
	if (this->following != comparable.following)
		return true;
	return false;
}
