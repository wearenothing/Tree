
#include<cstdio>
#include<stack>
#include"binarytree.h"
using namespace std;
void PreOrderTraversal2(BTree BT)
{
	stack<BTree> S;
	BTree T = BT;
	while (T || !S.empty())
	{
		while (T)
		{
			S.push(T);
			printf("%c", T->data);
			T = T->left;
		}
		if (!S.empty())
		{
			T = S.top();
			S.pop();
			T = T->right;
		}
	}
}

void InOrderTraversal2(BTree BT)
{
	stack<BTree> S;
	BTree T = BT;
	while (T || !S.empty())
	{
		while (T)
		{
			S.push(T);
			T = T->left;
		}
		if (!S.empty())
		{
			T = S.top();
			printf("%c", T->data);
			S.pop(); 
			T = T->right;
		}
	}
}

void PostOrderTraversal2(BTree BT)
{
	if (!BT) return;
	stack<BTree> S;
	S.push(BT);
	S.push(BT);
	BTree T = BT;
	while (!S.empty())
	{
		T = S.top();
		S.pop();
		if (!S.empty()&&T == S.top())
		{
			if (T->right)
			{
				S.push(T->right);
				S.push(T->right);
			}
			if (T->left)
			{
				S.push(T->left);
				S.push(T->left);
			}
		}
		else
		{
			printf("%c", T->data);
		}
	}
}

void PostOrderTraversal3(BTree BT)
{
	if (!BT) return;
	stack<BTree> S;
	S.push(BT);
	BTree T = BT;
	BTree last = BT;
	while (!S.empty())
	{
		T = S.top();
		if ((T->left == NULL&&T->right==NULL)|| (T->left == NULL && T->right == last)|| (T->left == last && T->right == NULL))
		{
			printf("%c", T->data);
			last = T;
			S.pop();
		}
		else
		{
			if (T->right)
				S.push(T->right);
			if (T->left)
				S.push(T->left);
		}
	}
}
