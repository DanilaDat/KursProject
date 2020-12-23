#pragma once
#include "File.h"
template <typename T>
class TxtFile :public File
{
protected:
	ifstream inputstream;
	ofstream outputstream;
public:

	TxtFile(char* filename);
	~TxtFile();

	bool IsOpen();
	bool IsROpen();
	bool IsWOpen();
	bool IfEOF();

	bool ROpen();
	bool WOpen();

	void RClose();
	void WClose();

	void Reading(T& obj);
	void Writing(T& obj);

};