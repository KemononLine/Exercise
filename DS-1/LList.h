#ifndef LLIST_H
#define LLSIT_H

#include <iostream>
using namespace std;

typedef int typedata;
struct ListNode
{
	typedata Data;
	ListNode* pNext;
	ListNode(typedata value, ListNode* next = NULL) :Data(value), pNext(next) {}
};

ListNode* Add(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1 == NULL && head2 == NULL)
	{
		cerr << "Empty Linked List" << endl;
		exit(1);
	}
	ListNode* AddHead = NULL;
	if (head1->Data > head2->Data)
	{
		AddHead = head2;
		head2 = head2->pNext;
	}
	else
	{
		AddHead = head1;
		head1 = head1->pNext;
	}
	ListNode* NewNode = AddHead;
	while (head1 && head2)
	{
		if (head1->Data > head2->Data)
		{
			AddHead->pNext = head2;
			head2 = head2->pNext;
		}
		else
		{
			AddHead->pNext = head1;
			head1 = head1->pNext;
		}
		AddHead = AddHead->pNext;
	}
	if (head1)
		AddHead->pNext = head1;
	if (head2)
		AddHead->pNext = head2;

	return NewNode;
}

#endif // !LLIST_H
