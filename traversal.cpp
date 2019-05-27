
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
	stack<BTree> S;
	BTree T = BT;
	while (T || !S.empty())
	{
		while (T)
		{
			S.push(T);
			S.push(T);
			T = T->left;
		}
		
		T = S.top();
		S.pop();
		if (T->left == NULL && T->right == NULL)
			T = S.top();
		else if (T == S.top())
		{
			T = S.top()->right;
		}
		else
		{
			printf("%c", T->data);
			T = S.top();
			//直到找到一个相同的，没找到结束
			
		}
	}
}
