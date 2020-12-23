#include"RING.h"
template <class T> Ring<T>::Ring()
{
	this->Head = NULL;
	this->Curr = NULL;
	int lenght = 0;
}
template <class T> Ring<T>::Ring(T obj)
{
	this->Head = NULL;
	this->Curr = NULL;
	int lenght = 0;
	this->AddNode(obj);
}
template <class T> Ring<T>::Ring(const Ring<T>& obj)
{
	this->Head = NULL;
	this->Curr = NULL;
	int lenght = 0;
	NodeRing<T>* TempCurr = obj.Curr;
	for (int i = 0; i < obj.lenght; i++)
	{
		this->AddNode(TempCurr->information);
		TempCurr = TempCurr->next;
	}
}
template <class T> Ring<T>::~Ring()
{
	CleanOut();
}
template <class T> void Ring<T>::AddNode(T information)
{
	NodeRing<T>* NewNode;
	NewNode = new NodeRing<T>;
	NewNode->information = information;
	if (this->Curr == NULL)  // Если кольцо пусто
	{
		this->Head = NewNode;
		this->Curr = NewNode;
		this->Curr->next = NewNode;
		this->Curr->prev = NewNode;
	}
	else
	{
		NewNode->next = Curr->next;
		NewNode->next->prev = NewNode;
		this->Curr->next = NewNode;
		NewNode->prev = Curr;
	}
	this->lenght++;
	this->Curr = NewNode;
}
template <class T> T Ring<T>::RetrieveNode()
{
	//if (this->lenght == 0)
	//{
	//	std::cout << "Кольцо пусто!" << std::endl;
	//	break;
	//}
	if (this->lenght > 0)
	{
		T ret = this->Curr->information;
		NodeRing<T>* Ret = this->Curr;
		if (this->lenght == 1)
		{
			this->Curr = 0;
			this->Head = 0;
		}
		else
		{
			this->Curr->prev->next = this->Curr->next;
			this->Curr->next->prev = this->Curr->prev;
			this->Curr = Curr->next;
		}
		if (Ret == this->Head)
			this->Head = Head->next;
		lenght--;
		delete Ret;
		return ret;
	}
	else
		std::cout << "Действие невозможно! Кольцо пусто!" << std::endl;
}
template <class T> void Ring<T>::CleanOut()
{
	if(this->lenght==0)
		std::cout << "Действие невозможно! Кольцо пусто!" << std::endl;
	while(this->lenght!=0)
		this->RetrieveNode();
}
template <class T> void Ring<T>::RingOut()
{
	if (this->Head != NULL)
	{
		NodeRing<T>* temp = this->Head;
		for (int i = 0; i < this->lenght; i++)
		{
			std::cout << temp->information << std::endl;
			temp = temp->next;
		}
	}
	else
		std::cout << "Кольцо пусто!";
}
//template <class T> void Ring<T>::DelSoughtNode(T SoughtInform)
//{
//	if (this->Head != NULL)
//	{
//		NodeRing<T>* tmp = this->Curr;
//		for (int i = 0; i < this->lenght; i++)
//		{
//			if (this->Curr->information == SoughtInform)
//			{
//				if (this->Curr == tmp)
//					tmp = tmp->next;
//				RetrieveNode();
//			}
//			CurrNext();
//		}
//		this->Curr = tmp;
//	}
//}
//template <class T> void Ring<T>::BubleSortNodes() // Сортировка не работает!!!!!!
//{
//	T Temp;
//	int i, j;
//	int f = this->lenght;
//	for (j = 0; j < f - 1; j++)
//	{
//		CurrToHead();
//		for (i = 0; i < f - 1; i++)
//		{
//			if (this->Curr->information > this->Curr->next->information)
//			{
//				Temp = RetrieveNode();
//				AddNode(Temp);
//			}
//			else
//				CurrNext();
//		}
//		i = 0;
//	}
//}
//template <class T> Ring<T>& Ring<T>::FindSourgeParamNodes(T SourgeParam)
//{
//	Ring<T>* ret = new Ring<T>;
//	this->CurrToHead();
//	NodeRing<T>* Temp = this->Curr;
//	do
//	{
//		if (Temp->information == SourgeParam)
//		{
//			ret->AddNode(Temp->information);
//		}
//		Temp = Temp->next;
//	} while (Temp != this->Curr);
//	return *ret;
//}
