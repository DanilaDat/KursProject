#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "RING.cpp"
#include "CALENDAR.h"
#include "TxtFile.cpp"
#include "MyIterator.cpp"

using namespace std;

// ����� ��� �������������� � ������������
class Interface
{
public:
	// ���������������� ����
	void menu();
	// ��������� �����
	char StartScreen();
	// ������ � �����������
	template <typename T> void actionchoise(Ring<T>& ring, char* txtfilename);
	template <> void actionchoise(Ring<Calendar>& ring, char* txtfilename);
};
#include "Interface.inl"
