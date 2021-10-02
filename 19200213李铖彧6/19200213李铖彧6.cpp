#include <stdio.h>
#include <malloc.h>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

typedef int QDataType;
typedef double  QDataType1;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;
typedef struct QNode1
{
	struct QNode1* _pNext;
	QDataType1 _data;
}QNode1;
typedef struct Queue
{
	QNode* _front; // 指向队头元素 
	QNode* _back; // 指向队尾元素 
}Queue;

class QUEUE
{
	QNode1* _front; // 指向队头元素 
	QNode1* _back; // 指向队尾元素 
public:
	QUEUE()
	{
		_front = NULL;
		_back = NULL;
	}
	void QueuePush(QDataType1 data);
	void QueuePop();
	QDataType1 QueueFront();
	QDataType1 QueueBack();
	QDataType QueueSize();
	QDataType QueueEmpty();
	~QUEUE();
};

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
QDataType QueueSize(Queue* q);
QDataType QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);
void QueueTest();

QNode* BuyNode(QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		assert(0);
	}
	newnode->_data = data;
	newnode->_pNext = NULL;
	return newnode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* node = BuyNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_back = node;
	}
	else
	{
		q->_back->_pNext = node;
		q->_back = node;
	}
}
void QUEUE::QueuePush(QDataType1 data)
{
	QNode1* newnode = new QNode1;//(QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (_front == NULL)
	{
		_front = _back = newnode;
	}
	else
	{
		_back->_pNext = newnode;
		_back = newnode;
	}

}
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode* newhead = q->_front;
	//队列中只有一个元素
	if (q->_front->_pNext == NULL)
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = newhead->_pNext;

	}
	free(newhead);
}
void QUEUE::QueuePop()
{
	if (_front == NULL)
	{
		return;
	}
	QNode1* newhead = _front;
	//队列中只有一个元素
	if (_front->_pNext == NULL)
	{
		_front = _back = NULL;
	}
	else
	{
		_front = newhead->_pNext;

	}
	delete newhead;
}
QDataType QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return NULL;
	}
	return q->_front->_data;
}
QDataType1 QUEUE::QueueFront()
{
	if (_front == NULL)
	{
		return NULL;
	}
	return _front->_data;
}
QDataType QueueBack(Queue* q)
{
	if (q->_front == NULL)
	{
		return NULL;
	}
	return q->_back->_data;
}
QDataType1 QUEUE::QueueBack()
{
	if (_front == NULL)
	{
		return NULL;
	}
	return _back->_data;
}
int QueueSize(Queue* q)
{
	QNode* pCur = q->_front;
	int count = 0;
	while (pCur != NULL)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}
int QUEUE::QueueSize()
{
	QNode1* pCur = _front;
	int count = 0;
	while (pCur != NULL)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		return 1;
	}
	return -1;
}
int QUEUE::QueueEmpty()
{
	if (_front == NULL)
	{
		return 1;
	}
	return -1;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode* pCur = q->_front;
	while (pCur != NULL)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = NULL;
		pCur = q->_front;
	}
	q->_front = q->_back = NULL;
}
QUEUE::~QUEUE()
{
	if (_front == NULL)
	{
		return;
	}
	QNode1* pCur = _front;
	while (pCur != NULL)
	{
		_front = pCur->_pNext;
		delete pCur;
		pCur = _front;
	}
	_front = _back = NULL;
}


void QueueTest()
{
	Queue s;
	QueueInit(&s);

	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	QueuePush(&s, 4);

	//出队列
	QueuePop(&s);
	QueuePop(&s);
	QueuePop(&s);

	//查看当前元素个数
	printf("size=%d\n", QueueSize(&s));
}
void QueueTEST()
{
	QUEUE s;
	s.QueuePush(1.1);
	s.QueuePush(11.11);
	s.QueuePush(111.111);
	s.QueuePush(1111.111);
	printf("size=%d\n", s.QueueSize());
	//出队列
	s.QueuePop();
	s.QueuePop();
	s.QueuePop();

	//查看当前元素个数
	printf("size=%d\n", s.QueueSize());
}
int main()
{
	QueueTest();
	QueueTEST();
	return 0;
}