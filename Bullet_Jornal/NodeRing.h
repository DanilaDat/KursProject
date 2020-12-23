#pragma once
template <class T>
struct NodeRing
{
public:
	T information;
	NodeRing* next;
	NodeRing* prev;
};