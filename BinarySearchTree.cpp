#include<stdio.h>
#include<random>
#include"Stack.h"

TNode* createTNode(int x)
{
	TNode* p = new TNode;
	if(p==NULL)
		return NULL;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void initBTree(BSTree& bt)
{
	bt.root = NULL;
}

int insertTNodeLeft(TNode* &T, TNode* p)
{
	if(T == NULL || p == NULL)
		return 0;
	if(T->left != NULL)
		return 0;
	T->left = p;
	return 1;
}

int insertTNodeRight(TNode* &T, TNode* p)
{
	if(T == NULL || p == NULL)
		return 0;
	if(T->right != NULL)
		return 0;
	T->right = p;
	return 1;
}

int insertTNode(TNode* &root, TNode* p)
{
	if(p == NULL)
		return 0;
	if(root == NULL)
	{
		root = p;
		return 1;
	}
	if(root->info == p->info)
		return 0;
	if(p->info < root->info)
		insertTNode(root->left, p);
	else
		insertTNode(root->right, p);
	return 1;
}

void traverseLNR(TNode* root)
{
	if(root == NULL)
		return;
	traverseLNR(root->left);
	printf("%d\t", root->info);
	traverseLNR(root->right);
}

void createBSTree(TNode* &root)
{
	FILE* f = fopen("BSTree.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x;
		fscanf(f, "%d", &x);
		TNode* p = createTNode(x);
		insertTNode(root, p);
	}
	fclose(f);
}

TNode* findTNodeReplace(TNode* &p)
{
	TNode* f = p;
	TNode* q = p->right;
	while(q->left != NULL)
	{
		f = q;
		q = q->left;
	}
	p->info = q->info;
	if(f == p)
		f->right = q->right;
	else
		f->left = q->right;
	return q;
}

int deleteTNodeX(TNode* &root, int x)
{
	if(root == NULL)
		return 0;
	if(root->info > x)
		return deleteTNodeX(root->left, x);
	else
		if(root->info < x)
			return deleteTNodeX(root->right, x);
		else
		{
			TNode* p = root;
			if(root->left == NULL)
			{
				root = root->right;
				delete p;
			}
			else
				if(root->right == NULL)
				{
					root = root->left;
					delete p;
				}
				else
				{
					TNode* q = findTNodeReplace(p);
					delete q;
				}
				return 1;
		}
}

void duyetTheoChieuRong(TNode* root)
{
	if(root == NULL)
		return;
	Queue qu;
	qu.head = qu.tail = NULL;
	pushQueue(qu, root);
	while(isEmptyQueue(qu) == 0)
	{
		TNode* p = qu.head->data;
		printf("%d\t", p->info);
		popQueue(qu);
		if(p->left != NULL)
			pushQueue(qu, p->left);
		if(p->right != NULL)
			pushQueue(qu, p->right);
	}
}

void duyetTheoChieuSau(TNode* root)
{
	if (root == NULL)
		return;
	Stack t;
	t.top = NULL;
	pushS(t, root);
	while (isEmpty(t) == 0)
	{
		TNode* p = t.top->data;
		printf("%d\t", p->info);
		popS(t);
		if (p->right != NULL)
			pushS(t, p->right);
		if (p->left != NULL)
			pushS(t, p->left);
	}
}