#include<stdio.h>
#include"Stack.h"

int isEmpty(Stack t)
{
	if (t.top == NULL)
		return 1;
	return 0;
}

void popS(Stack& t)
{
	if (isEmpty(t) == 1)
		return;
	Node* p = t.top;
	/*x = t.top->info;*/
	t.top = t.top->next;
	delete p;
}

void pushS(Stack& t, TNode* x)
{
	Node* p = createNode(x);
	if (p != NULL)
		if (t.top == NULL)
		{
			t.top = p;
		}
		else
		{
			p->next = t.top;
			t.top = p;
		}
}