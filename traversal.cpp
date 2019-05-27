
#include<cstdio>
#include<stack>
#include<queue>
#include"binarytree.h"
using namespace std;
//void PreOrderTraversal2(BTree BT)
//{
//	stack<BTree> S;
//	BTree T = BT;
//	while (T || !S.empty())
//	{
//		while (T)
//		{
//			S.push(T);
//			printf("%c", T->data);
//			T = T->left;
//		}
//		if (!S.empty())
//		{
//			T = S.top();
//			S.pop();
//			T = T->right;
//		}
//	}
//}
void PreOrderTraversal2(BTree BT)
{
	stack<BTree> S;
	BTree T = BT;
	S.push(T);
	while (!S.empty())
	{
		T = S.top();
		printf("%c", T->data);
		S.pop();
		if (T->right)
			S.push(T->right);
		if (T->left)
			S.push(T->left);
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


void LevelTraversal(BTree BT)
{
	if (!BT)
		return;
	BTree T = BT;
	queue<BTree> Q;
	Q.push(T);
	while (!Q.empty())
	{
		T = Q.front();
		printf("%c", T->data);
		Q.pop();
		if (T->left)
			Q.push(T->left);
		if (T->right)
			Q.push(T->right);
	}
}
