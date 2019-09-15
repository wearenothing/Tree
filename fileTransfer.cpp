#include<iostream>
using namespace std;

int find(int S[], int k)
{
	while (S[k] > 0)
		k = S[k];
	return k;
}
void union2(int S[], int a, int b)
{
	int l = find(S, a);
	int r = find(S, b);
	if (l != r)
	{
		if (S[l] > 0)
			S[b] = a;
		else
			S[a] = b;
	}
		
}
bool isConnect(int S[], int a, int b)
{
	int l = find(S, a);
	int r = find(S, b);
	if (l == r && l != -1)
		return true;
	else
		return false;
}
int main()
{
	int S[10010];
	int N;
	cin >> N;
	for (int i = 1; i <=N; i++)
		S[i] = -1;
	char ch;
	cin >> ch;
	while (ch != 'S')
	{
		int a, b;
		cin >> a >> b;
		if (ch == 'I')
			union2(S, a, b);
		else
		{
			bool t = isConnect(S, a, b);
			if (t)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		cin >> ch;
	}
	int k=0;
	for (int i = 1; i <= N; i++)
	{
		if (S[i] < 0)
			k++;
	}
	if (k == 1)
		cout << "The network is connected.";
	else
		cout << "There are " << k  << " components.";
	
	return 0;
}
