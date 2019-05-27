#include"binarytree.h"
#include<cstdio>
void PreOrderTraversal(BTree T);
void InOrderTraversal(BTree T);
void PostOrderTraversal(BTree T);
void PreOrderTraversal2(BTree T);
void InOrderTraversal2(BTree T);
void PostOrderTraversal2(BTree BT);
void PostOrderTraversal3(BTree BT);
void LevelTraversal(BTree BT);
int main()
{
	TNode A, B, C, D, E, F, G, H, I;
	A.data = 'A';
	B.data = 'B';
	C.data = 'C';
	D.data = 'D';
	E.data = 'E';
	F.data = 'F';
	G.data = 'G';
	H.data = 'H';
	I.data = 'I';

	A.left = &B;
	A.right = &C;

	B.left = &D;
	B.right = &F;

	C.left = &G;
	C.right = &I;

	D.left = NULL;
	D.right = NULL;

	E.left = NULL;
	E.right = NULL;

	F.left = &E;
	F.right = NULL;

	G.left = NULL;
	G.right = &H;

	H.left = NULL;
	H.right = NULL;

	I.left = NULL;
	I.right = NULL;

	BTree BT = &A;

	PreOrderTraversal(BT);
	printf("\n");
	//InOrderTraversal(BT);
	//printf("\n");
	//PostOrderTraversal(BT);
	//printf("\n");

	////non-recursion
	PreOrderTraversal2(BT);
	printf("\n");
	//InOrderTraversal2(BT);
	//printf("\n");
	//PostOrderTraversal2(BT);
	//printf("\n");
	LevelTraversal(BT);
	return 0;
}
