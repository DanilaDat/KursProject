#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <cstring>
#include "NodeRing.cpp"
// ������������� ���� ����������
//template <class T> 
//struct NodeRing          
//{
//	T information;
//	NodeRing* next;
//	NodeRing* prev;
//};
// ���������
template <class T>
class Ring
{
private:
	NodeRing<T>* Head;  // ��������� �� ������
	NodeRing<T>* Curr;  // ��������� �� �����
	int lenght;         // ���������� ���������
public:

	NodeRing<T>* begin() { return this->Head; }; // ���� �� ����� ����
	NodeRing<T>* end() { if (this->Head != NULL)return this->Head->prev; else return NULL; };// ���� �� ����� ����!

	Ring();             // �����������
	Ring(T obj);        // ����������� � �����������
	// ����������� �����������
	Ring(const Ring<T>& obj);
	~Ring();            // ����������
    // �������� ����
	void AddNode(T information);  
	// ������� ����
	T RetrieveNode();     
	// �������� ������ ����
	T GetNode() { if (this->Head != NULL) return this->Curr->information; };
	// �������� ��� �������
	void CleanOut();
	// ������� �������
	void RingOut();
	// ���������� ��������� +
	void operator+(T adding) { this->AddNode(adding); };
	// ������� ��������� �� ������� ������� �� ��������
	void CurrToHead() { this->Curr = Head; };
	// ������� ��������� �� ������� � ����������
	void CurrNext() { if (this->Head != NULL)this->Curr = Curr->next; };
	// ������� ��������� �� ������� � �����������
	void CurrPrev() { if (this->Head != NULL)this->Curr = Curr->Prev; };
};
