#include <bits/stdc++.h>

using namespace std;

typedef struct NODE{
	int a;
	int b;
}Node;

bool nodeCMP(Node n1, Node n2)
{
	return n1.b < n2.b;
}

const int maxSize = 1000010;

Node No[maxSize];

int main()
{
	int n; 
	
	cin >> n;

	int aInd = 0;
	int count = 0;
	
	
	for(int i = 0; i < n; i++)
	{
		cin >> No[i].a >> No[i].b;
	}
	
	
	sort(No, No+n, nodeCMP);
	
	int tmpI;
	int lastB = -1;
	
	for(int i = 0; i < n; i++)
	{
		if(No[i].a < lastB)
		{
			continue;
		}
		lastB = No[i].b;
		count++;
	}
	
	cout << count;
	
	return 0;
 } 
