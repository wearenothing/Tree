#include"binarytree.h"
#include<cstdio>
void PreOrderTraversal(BTree T)
{
	if (T)
	{
		printf("%c", T->data);
		PreOrderTraversal(T->left);
		PreOrderTraversal(T->right);
	}
}

void InOrderTraversal(BTree T)
{
	if (T)
	{
		InOrderTraversal(T->left);
		printf("%c", T->data);
		InOrderTraversal(T->right);
	}
}

void PostOrderTraversal(BTree T)
{
	if (T)
	{
		PostOrderTraversal(T->left);
		PostOrderTraversal(T->right);
		printf("%c", T->data);
	}
}