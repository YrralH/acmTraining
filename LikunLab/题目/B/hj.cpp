#include<iostream>

using namespace std;

long long a[500000];

int main()
{
	
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	
	for(int i = 3; i < 500000; i++)
	{
		a[i] = 2*a[i-1] + a[i-2] + 2*a[i-3];
		a[i] = a[i] % 998244353;
	}
	
	int numberOfCases;
	
	cin >> numberOfCases;
	int x;
	
	for(int caseCount = 0; caseCount < numberOfCases; caseCount++)
	{
		cin >> x;
		cout << a[x] << endl;
	}
	
	
	
	return 0;
}
