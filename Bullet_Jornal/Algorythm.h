#pragma once
#include "RING.cpp"
template <class T> void BubleSortNodes(MyIterator<T> begin, MyIterator<T> end)
{
	NodeRing<T>* current = begin.following;
	MyIterator<T> curnext = current->next;
	T temp;
	while (begin != end)
	{
		while (end != current)
		{
			if (current->information > * curnext)
			{
				temp = current->information;
				current->information = *curnext;
				curnext = temp;
			}
			current = current->next;
			++curnext;
		}
		current = curnext.following;
		++curnext;
		++begin;
	}
}
template <class T> Ring<T>& FindSourgeParamNodes(MyIterator<T> begin,T SourgeParam)
{
	MyIterator<T> current = begin;
	Ring<T>* ret = new Ring<T>;
	do
	{
		if (*begin == SourgeParam)
		{
			ret->AddNode(*begin);
		}
		++begin;
	} while (begin != current);
	return *ret;
}
template <class T> Ring<T>& CopyFTElem(MyIterator<T> begin, MyIterator<T> end, int from, int to)
{
	Ring<T>* copied = new Ring<T>;
	int fromreal = 1;
	while (begin != end)
	{
		while (fromreal < from && begin != end)
		{
			fromreal++;
			++begin;
		}
		do
		{
			copied->AddNode(*begin);
			++begin;
			fromreal++;
		} while (fromreal != to + 1 && begin != end.following->next);
		if (fromreal == to+1)
			break;
	}
	return *copied;
}
