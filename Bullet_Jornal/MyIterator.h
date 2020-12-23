#pragma once
#include"NodeRing.cpp"
template <class T>
class MyIterator
{
public :
	NodeRing<T>* following;
public:
	MyIterator(NodeRing<T>* ptr) { this->following = ptr; }; // ����������� �� ���������
	MyIterator() { this->following = nullptr; };             // ����������� �� ���������
	~MyIterator() {};                                        // ����������

	T& operator*();                            // ��������� ��������, �� ������� ��������� ��������
	MyIterator<T> operator+(int position);     // ��������, ��������� �� �������� �� position ������� ������
	MyIterator<T> operator-(int position);     // ��������, ��������� �� �������� �� position ������� �����
	MyIterator<T> operator+=(int position);    // ����������� ��������� �� position ������� ������
	MyIterator<T> operator-=(int position);    // ����������� ��������� �� position ������� �����
	void operator++();                         // ����������� ��������� ������
	void operator--();                         // ����������� ��������� �����
	void operator=(T equal);                   // �������� ������������(��������� ������ ����)
	void operator=(NodeRing<T>* equal);        // �������� ������������(��������� ����)
	void operator=(MyIterator<T>& equal);
	bool operator==(NodeRing<T>* comparable);  // �������� ���������(�������� � �����)
	bool operator==(MyIterator<T>& comparable);// �������� ���������(�������� � ����������)
	bool operator!=(NodeRing<T>* comparable);  // �������� ���������(�������� � �����)
	bool operator!=(MyIterator<T>& comparable);// �������� ���������(�������� � ����������)

};