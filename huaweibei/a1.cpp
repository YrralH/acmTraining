#include<iostream>

using namespace std;
 
int A[1000005];
 
int main()
{
	int N;
	int tmp;
	int value;
	int maxI;
	int minI;
	int maxV;
	int minV;
	int maxT;
	int minT;
	
	int out1;
	int out2;
	
	cin >> N;
	

	maxV = -3 * N;
	minV = 3 * N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		A[i] = tmp;
		value = tmp - (N - i);
		if(value >= maxV)
		{
			maxV = value;
			maxI = i;
			maxT = tmp;
		}
		
		
		if(value <= minV)
		{
			minV = value;
			minI = i;
			minT = tmp;
		}
	}
	
	cout << maxI << ' ' << minI << endl;
	
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		//cout << i << ' ' << A[i] << ' ' << minI << ' ' << maxI << ' ' << minT << ' ' << maxT << endl;
		if(i >= minI && i <= maxI && A[i] >= minT && A[i] <= maxT)
		{
			count++;
		}	
	}	
	cout << count;
	
	return 0;
 } 
