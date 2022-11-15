#include<stdio.h>
#include"Queue.h"

Node* createNode(TNode* x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap phat\n");
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void pushQueue(Queue& qu, TNode* x)
{
	Node* p = createNode(x);
	if (qu.head == NULL)
		qu.head = qu.tail = p;
	else
	{
		qu.tail->next = p;
		qu.tail = p;
	}
}

void popQueue(Queue& qu)
{
	if (qu.head == NULL)
		return;
	else
	{
		Node* p = qu.head;
		qu.head = p->next;
		deleteNode(p);
	}
}

void deleteNode(Node* p)
{
	p->next = NULL;
	delete p;
}

int isEmptyQueue(Queue qu)
{
	if (qu.head == NULL)
		return 1;
	return 0;
}