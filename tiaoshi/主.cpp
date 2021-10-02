/*
#include "ListP.h"
#include <iostream>
using namespace std;
void main()
{
	listClass L;
	listItemType DataItem;
	bool Success;
	L.ListInsert(1, 10, Success);
	L.ListInsert(2, 20, Success);
	L.ListInsert(3, 30, Success);
	for (int i = 1;i < L.ListLength();i++)
	{
		L.ListRetrieve(i, DataItem, Success);
		cout << DataItem << endl;//10,20
	}
	L.ListDelete(1, Success);
	for(int i=1;i<=L.ListLength();i++)
	{
		L.ListRetrieve(i, DataItem, Success);
		cout << DataItem << endl;//20,30
	}
	L.ListDelete(1, Success);
	for (int i = 1;i < L.ListLength();i++)
	{
		L.ListRetrieve(1, DataItem, Success);
		cout << DataItem << endl;
	}
}
*/
#include<iostream>
using namespace std;
class Node
{
	friend class LinkList;
	int data;
	Node* next;
public:
	Node(int x) :data(x) {}
};
class LinkList
{
	Node* head;
public:
	int Count;
	LinkList()
	{
		int n, number;
		cin >> n >> number;
		Count = n;
		head = new Node(number);
		Node* p = head;
		for (int i = 0;i < n - 1;i++)
		{
			cin >> number;
			Node* q = new Node(number);
			p->next = q;
			p = q;
		}
	}
	~LinkList() {}
	LinkList(LinkList& L1)
	{
		head = new Node(L1.head->data);
		Count = L1.Count;
		Node* p = head;
		Node* p2 = L1.head->next;
		for (int i = 0;i < Count - 1;i++)
		{
			Node* q = new Node(p2->data);
			p->next = q;
			p = q;
			p2 = p2->next;
		}
	}
	int& operator [](int i)
	{
		Node* tmp = head;
		for (int j = 0;j < i;j++)
		{
			tmp = tmp->next;
		}
		return tmp->data;
	}

};
int main()
{
	LinkList L1;
	LinkList L2(L1);
	int i;
	for (i = 0; i < L2.Count; i++)   L2[i] = L2[i] + 1;
	int L1Sum = 0;
	for (i = 0; i < L1.Count; i++)   L1Sum += L1[i];
	int L2Sum = 0;
	for (i = 0; i < L2.Count; i++)   L2Sum += L2[i];
	cout << L1Sum << " " << L2Sum << endl;
	return 0;
}
