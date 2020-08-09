#include<bits/stdc++.h>

using namespace std;

int main()
{
	int	a[200000];
	int b[200000];
	int tmpMax;
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	} 
	
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			a[0] = b[0];
			tmpMax = a[0];
			continue;
		}
		
		a[i] = tmpMax + b[i];
		
		if(a[i] > tmpMax)
		{
			tmpMax = a[i];
		}
		
	} 
	
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			cout << a[i];
			continue;
		}
		cout << ' ' << a[i];
	} 
	
	return 0;
 } 
