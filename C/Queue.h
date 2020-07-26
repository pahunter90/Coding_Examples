#ifndef QUEUE_H_DEFINED
#define QUEUE_H_DEFINED

typedef struct QNode
{
	void * data;
	struct Node * next;
}QNode;

typedef struct Queue
{
	size_t memSize;
	QNode* tail;
}Queue;

void Q_init(Queue*, size_t);

#endif
