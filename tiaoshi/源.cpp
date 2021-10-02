#include "Listp.h"
#include <stddef.h>
#include <assert.h>
struct listNode
{
	listItemType Item;
	ptrType Next;
};

listClass::listClass():Size(0),Head(NULL)
{}
listClass::listClass(const listClass& L) : Size(L.Size)
{
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head = new listNode;
		assert(Head != NULL);
		Head->Item = L.Head->Item;
		ptrType NewPtr = Head;
		for (ptrType OrigPtr = L.Head->Next;OrigPtr != NULL;OrigPtr = OrigPtr->Next)
		{
			NewPtr->Next = new listNode;
			assert(NewPtr->Next != NULL);
			NewPtr = NewPtr->Next;
			NewPtr->Item = OrigPtr->Item;
		}
		NewPtr->Next = NULL;
	}
}
listClass::~listClass()
{
	bool Success;
	while (!ListIsEmpty())
		ListDelete(1, Success);
}
bool listClass::ListIsEmpty()const
{
	return bool(Size == 0);
}
int listClass::ListLength()const
{
	return Size;
}
ptrType listClass::PtrTo(int Position)const
{
	if ((Position < 1) || (Position > ListLength()))
		return NULL;
	else
	{
		ptrType Cur = Head;
		for (int skip = 1;skip < Position;skip++)
		{
			Cur = Cur->Next;
		}
		return Cur;
	}
}
void listClass::ListInsert(int NewPosition, listItemType NewItem, bool& Success)
{
	int NewLength = ListLength() + 1;
	Success = bool((NewPosition >= 1) && (NewPosition <= NewLength));
	if (Success)
	{
		ptrType NewPtr = new listNode;
		Success = bool(NewPtr != NULL);
		if (Success)
		{
			Size = NewLength;
			NewPtr->Item = NewItem;
			if (NewPosition == 1)
			{
				NewPtr->Next = Head;
				Head = NewPtr;
			}
			else
			{
				ptrType Prev = PtrTo(NewPosition - 1);
				NewPtr->Next = Prev->Next;
				Prev->Next = NewPtr;
			}
		}
	}
}
void listClass::ListDelete(int Position, bool& Success)
{
	ptrType Cur;
	Success = bool((Position >= 1) && (Position <= Size));
	if (Success)
	{
		Size--;
		if (Position == 1)
		{
			Cur = Head;
			Head = Head->Next;
		}
		else
		{
			ptrType Prev = PtrTo(Position - 1);
			Cur = Prev->Next;
			Prev = Cur->Next;
		}
		delete Cur;
		Cur = NULL;
	}
}
void listClass::ListRetrieve(int Position, listItemType& DataItem, bool& Success)const
{
	Success = bool((Position >= 1) && (Position <= Size));
	if (Success)
	{
		ptrType Cur = PtrTo(Position);
		DataItem = Cur->Item;
	}
}