#include <bits/stdc++.h>

using namespace std;

typedef struct NODE{
	int val;
	int ind;
}Node;

bool nodeCMP(Node n1, Node n2)
{
	return n1.val < n2.val;
}

const int maxSize = 1000010;

Node A[maxSize]; 
Node B[maxSize];  
bool valid[maxSize]; 

int main()
{
	int n; 
	
	cin >> n;

	int aInd = 0;
	int count = 0;
	
	
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].val >> B[i].val;
		A[i].ind = i;
		B[i].ind = i;
	}
	
	for(int i = 0; i < n; i++)
	{
		valid[i] = 1;
	}
	
	//cout << "initialized" << endl;
	
	sort(A, A+n, nodeCMP);
	sort(B, B+n, nodeCMP);
	
	//cout << "sorted" << endl;
	
	
	int tmpI;
	
	for(int i = 0; i < n; i++)
	{
		tmpI = B[i].ind;
		if(!valid[tmpI])
		{
			continue;
		}
		
		count++;
		
		while(A[aInd].val < B[i].val && aInd <= n)
		{
			valid[A[aInd].ind] = 0;
			aInd++;
		} 
	}
	
	
	cout << count;
	
	
	
	return 0;
 } 
