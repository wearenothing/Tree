#define MaxTree 10
#include<iostream>
using namespace std;

struct TreeNode
{
	char data;
	int Left;
	int Right;
} T1[MaxTree], T2[MaxTree];


int BuildTree(int N,struct TreeNode* T)
{
	int head=-1;
	int check[MaxTree];
	for (int i = 0; i < N; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> T[i].data;
		char left, right;
		cin >> left;
		if (left == '-')
			T[i].Left = -1;
		else
		{
			T[i].Left = left - '0';
			check[T[i].Left] = 1;	
		}
		cin >> right;
		if (right == '-')
			T[i].Right = -1;
		else
		{
			T[i].Right = right - '0';
			check[T[i].Right] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (check[i] == 0)
		{
			head = i;
			break;
		}
	}
	return head;
}
int sa(int r1, int r2)
{
	if (r1 == -1 && r2 == -1)
		return 1;
	if ((r1 == -1 && r2 != -1) || (r1 != -1 && r2 == -1))
		return 0;
	if (T1[r1].data != T2[r2].data)
		return 0;
	if (T1[r1].Left == -1 && T2[r2].Left == -1)
		return sa(T1[r1].Right, T2[r2].Right);
	if ((T1[r1].Left != -1 && T2[r2].Left != -1) && (T1[T1[r1].Left].data == T2[T2[r2].Left].data))
	{
		return sa(T1[r1].Left, T2[r2].Left) && sa(T1[r1].Right, T2[r2].Right);
	}
	else
	{
		return sa(T1[r1].Left, T2[r2].Right) && sa(T1[r1].Right, T2[r2].Left);
	}
	
}

int main()
{
	int N, M;
	int h1, h2;
	
	cin >> N;
	h1 = BuildTree(N,T1);

	cin >> M;
	h2 = BuildTree(M,T2);
	if (N != M)
	{
		cout << "No" << endl;
		return 0;
	}
	//if(N==0)
	if (sa(h1, h2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}