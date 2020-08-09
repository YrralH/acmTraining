#include<bits/stdc++.h>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	
	int n;
	
	for(int caseCount = 0; caseCount < numOfCases; caseCount++)
	{
		cin >> n;
		
		if(n == 1)
		{
			cout << -1 << endl;
			continue;
		}
		
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				cout << 2;
				continue;
			 } else{
			 	cout << 9;
			 }
		} 
		cout << endl;
		continue;
		
		
		
	}
	
	return 0;
 } 
