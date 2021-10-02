#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using namespace std;

char Prio[7][7] =
{
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','<'},
	{'>','>','>','>',' ','>','>'},
	{'<','<','<','<','<','>','='}
};

template<typename T>
struct Node
{
	T Data;
	Node<T>* pNext;
	Node(T obj, Node<T>* Next = NULL) :Data(obj), pNext(Next) {}
	Node(Node<T>* Next = NULL) :pNext(Next) {}
};

template<typename T>
class LinkStack
{
	Node<T>* top;
public:
	LinkStack();
	~LinkStack();
	void Push(T obj);
	T Pop();
	T Top();
	bool isEmpty();
};

template<typename T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
	Node<T>* p;
	Node<T>* q;
	p = top;
	while (p)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
}

template<typename T>
void LinkStack<T>::Push(T obj)
{
	Node<T>* s = new Node<T>;
	s->Data = obj;
	s->pNext = top;
	top = s;
}

template<typename T>
T LinkStack<T>::Pop()
{
	if (top == NULL)
	{
		cerr << "ÏÂÒç" << endl;
		exit(1);
	}
	T x = top->Data;
	Node<T>* p = top;
	top = top->pNext;
	delete p;

	return x;
}

template<typename T>
T LinkStack<T>::Top()
{
	if (top == NULL)
	{
		cerr << "ÏÂÒç" << endl;
		exit(1);
	}

	return top->Data;
}

template<typename T>
bool LinkStack<T>::isEmpty()
{
	return top == NULL;
}

char Precede(char pre_op, char c)
{
	int x=0, y=0;
	switch (pre_op)
	{
	case '+':
		x = 0;
		break;
	case '-':
		x = 1;
		break;
	case '*':
		x = 2;
		break;
	case '/':
		x = 3;
		break;
	case '(':
		x = 4;
		break;
	case ')':
		x = 5;
		break;
	case '@':
		x = 6;
		break;
	default:
		break;
	}
	switch (c)
	{
	case '+':
		y = 0;
		break;
	case '-':
		y = 1;
		break;
	case '*':
		y = 2;
		break;
	case '/':
		y = 3;
		break;
	case '(':
		y = 4;
		break;
	case ')':
		y = 5;
		break;
	case '@':
		y = 6;
		break;
	default:
		break;
	}

	return Prio[x][y];
}

double Operate(double a, char pre_op, double b)
{
	switch (pre_op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		break;
	}
}
#endif // !MYSTACK_H