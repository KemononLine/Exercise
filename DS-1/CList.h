#ifndef CLIST_H
#define CLIST_H

#include <iostream>
using namespace std;

template<typename T,int MaxSize>
class CList
{
	T data[MaxSize];
	int length;
public:
	CList();
	CList(T a[], int n);
	int ListLength();
	T* Add(CList &a, CList &b);
};

template<typename T, int MaxSize>
CList<T, MaxSize>::CList()
{
	length = 0;
}

template<typename T, int MaxSize>
CList<T, MaxSize>::CList(T a[], int n)
{
	if (n > MaxSize)
	{
		cerr << "Invalid Input" << endl;
		exit(1);
	}
	for (int i = 0;i < n;i++)
		data[i] = a[i];
	length = n;
}

template<typename T, int MaxSize>
int CList<T,MaxSize>::ListLength()
{
	return length;
}

template<typename T, int MaxSize>
T* CList<T, MaxSize>::Add(CList& a, CList& b)
{
	if (a.length + b.length > MaxSize)
	{
		cerr << "OverFlow" << endl;
		exit(1);
	}
	for (int i =0;i <b.length;i++)
	{
		a.data[a.length+i] = b.data[i];
	}
	for (int i = 0;i < a.length + b.length;i++)
		for (int j = 0;j < a.length + b.length-1;j++)
			if (a.data[j] > a.data[j + 1])
				swap(a.data[j], a.data[j + 1]);
	return a.data;
}

#endif