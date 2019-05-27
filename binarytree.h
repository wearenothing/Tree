#pragma once
typedef char ElemType;
typedef struct TNode* BTree;
struct TNode
{
	ElemType data;
	struct TNode* left;
	struct TNode* right;
};
