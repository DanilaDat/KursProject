#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <cstring>
#include "NodeRing.cpp"
// Представление узла контейнера
//template <class T> 
//struct NodeRing          
//{
//	T information;
//	NodeRing* next;
//	NodeRing* prev;
//};
// Контейнер
template <class T>
class Ring
{
private:
	NodeRing<T>* Head;  // Указатель на голову
	NodeRing<T>* Curr;  // Указатель на хвост
	int lenght;         // Количество элементов
public:

	NodeRing<T>* begin() { return this->Head; }; // Если не равно нулю
	NodeRing<T>* end() { if (this->Head != NULL)return this->Head->prev; else return NULL; };// Если не равно нклю!

	Ring();             // Конструктор
	Ring(T obj);        // Конструктор с параметрами
	// Конструктор копирования
	Ring(const Ring<T>& obj);
	~Ring();            // Деструктор
    // Добавить узел
	void AddNode(T information);  
	// Извлечь узел
	T RetrieveNode();     
	// Получить данные узла
	T GetNode() { if (this->Head != NULL) return this->Curr->information; };
	// Очистить всю очередь
	void CleanOut();
	// Вывести очередь
	void RingOut();
	// Перегрузка оператора +
	void operator+(T adding) { this->AddNode(adding); };
	// Переход указателя на текущий элемент на головной
	void CurrToHead() { this->Curr = Head; };
	// Переход указателя на текущий к следующему
	void CurrNext() { if (this->Head != NULL)this->Curr = Curr->next; };
	// Переход указателя на текущий к предыдущему
	void CurrPrev() { if (this->Head != NULL)this->Curr = Curr->Prev; };
};
