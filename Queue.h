#include<stdio.h>
#include"BinarySearchTree.h"

struct Node
{
	TNode* data;
	Node* next;
};

struct Queue
{
	Node* head;
	Node* tail;
};

Node* createNode(TNode* x);
void pushQueue(Queue& qu, TNode* x);
void deleteNode(Node* p);
void popQueue(Queue& qu);
int isEmptyQueue(Queue qu);