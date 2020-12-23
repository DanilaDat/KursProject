#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <fstream>

using namespace std;

#define FStrSize 80
class File
{
protected:
	char filename[FStrSize];
public:
	File(char* filename) { strcpy(this->filename, filename); };
};