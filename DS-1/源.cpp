#include <iostream>
#include "CList.h"
#include "LList.h"
using namespace std;

void menu();
void fun1();
void fun2();

int main()
{
	menu();
	int choice;
	cin >> choice;
	while (choice != 3)
	{
		switch (choice)
		{
		case 1:
			cout << "case1" << endl;
			fun1();
			break;
		case 2:
			cout << "case2" << endl;
			fun2();
			break;
		default:
			cerr << "Invalid Input" << endl;
		}
		menu();
		cin >> choice;
	}
	cout << "EXIT" << endl;

	return 0;
}

void menu()
{
	cout << "Enter Numbers to Choose Function" << endl;
	cout << "1.Contiguous List		2.Linked List" << endl;
	cout << "3.Exit" << endl;
}

void fun1()
{
	int aa[] = { 1,3,7,10 };
	int bb[] = { 2,4,5,8,22 };
	CList<int, 10> a(aa,4);
	CList<int, 10> b(bb,5);
	CList<int, 10> c;
	int* p = c.Add(a, b);
	for (int i = 0;i < a.ListLength()+b.ListLength();i++)
		cout << p[i]<<"  ";
	cout << '\n';
}

void fun2()
{
	ListNode* head1 = new ListNode(1);
	ListNode* pCur = head1;
	for (int i = 3;i < 20;i += 2)
	{
		ListNode* NewNode = new ListNode(i);
		pCur->pNext = NewNode;
		pCur = NewNode;
	}

	ListNode* head2 = new ListNode(2);
	pCur = head2;
	for (int i = 4;i < 15;i += 2)
	{
		ListNode* NewNode = new ListNode(i);
		pCur->pNext = NewNode;
		pCur = NewNode;
	}

	ListNode* head = Add(head1, head2);
	while (head)
	{
		cout << head->Data << "  ";
		head = head->pNext;
	}
	cout << '\n';
}