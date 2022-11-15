#include<stdio.h>
#include"Queue.h"

struct Stack
{
	Node* top;
};

int isEmpty(Stack t);
void pushS(Stack& t, TNode* x);
void popS(Stack& t);