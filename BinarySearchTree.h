#ifndef BST
#define BST
#include<stdio.h>

struct TNode
{
	int info;
	TNode* left;
	TNode* right;
};

struct BSTree
{
	TNode* root;
};

TNode* createTNode(int x);
void initBTree(BSTree& bt);
int insertTNodeLeft(TNode* &T, TNode* p);
int insertTNodeRight(TNode* &T, TNode* p);
int insertTNode(TNode* &root, TNode* p);
void traverseLNR(TNode* root);
void createBSTree(TNode* &root);
TNode* findTNodeReplace(TNode* &p);
int deleteTNodeX(TNode* &root, int x);
void duyetTheoChieuRong(TNode* root);
void duyetTheoChieuSau(TNode* root);
#endif