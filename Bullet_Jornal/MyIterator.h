#pragma once
#include"NodeRing.cpp"
template <class T>
class MyIterator
{
public :
	NodeRing<T>* following;
public:
	MyIterator(NodeRing<T>* ptr) { this->following = ptr; }; // Конструктор со значением
	MyIterator() { this->following = nullptr; };             // Конструктор по умолчанию
	~MyIterator() {};                                        // Деструктор

	T& operator*();                            // Получение элемента, на который указывает итератор
	MyIterator<T> operator+(int position);     // Итератор, смешенный от текущего на position позиций вперед
	MyIterator<T> operator-(int position);     // Итератор, смешенный от текущего на position позиций назад
	MyIterator<T> operator+=(int position);    // Перемещение итератора на position позиций вперед
	MyIterator<T> operator-=(int position);    // Перемещение итератора на position позиций назад
	void operator++();                         // Перемещение итератора вперед
	void operator--();                         // Перемещение итератора назад
	void operator=(T equal);                   // Операция присваивания(итератору данные узла)
	void operator=(NodeRing<T>* equal);        // Операция присваивания(итератору узел)
	void operator=(MyIterator<T>& equal);
	bool operator==(NodeRing<T>* comparable);  // Операция сравнения(итератор с узлом)
	bool operator==(MyIterator<T>& comparable);// Операция сравнения(итератор с итератором)
	bool operator!=(NodeRing<T>* comparable);  // Операция сравнения(итератор с узлом)
	bool operator!=(MyIterator<T>& comparable);// Операция сравнения(итератор с итератором)

};