#include <bits/stdc++.h>

using namespace std;

typedef struct NODE{
	int dist;
	int ind;
}Node;

Node A[50000];
int globalN;

bool nodeCMP(Node a, Node b)
{
	return a.dist < b.dist;
}

void disp()
{
	for(int i = 0; i < globalN + 1; i++)
	{
		cout << A[i].dist << ' ' << A[i].ind << endl;
	}
	
	return;
 } 

int main()
{
	int M, N, L;
	
	cin >> L >> N >> M;
	
	globalN = N;
	
	int oldDist = 0;
	int newDist;
	
	for(int i = 0; i < N; i++)
	{
		cin >> newDist;
		A[i].dist = newDist - oldDist;
		oldDist = newDist; 
		A[i].ind = i;
	}
	A[N].dist = L - oldDist;
	A[N].ind = N;
	
	sort(A, A+1+N, nodeCMP);
	
	disp();
	
	
	
	return 0;
 } 
 
 
