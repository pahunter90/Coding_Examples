#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


void Q_init(Queue *q, size_t memSize)
{
	q->memSize = memSize;
	q->tail = NULL;
}

int enqueue(Queue *q, const void *data)
{
	QNode* newNode = (QNode *)malloc(sizeof(QNode));

	
