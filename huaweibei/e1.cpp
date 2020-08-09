#include<iostream>

using namespace std;

int A[1000005];
bool b[1000005];
bool c[1000005];

int main()
{
	int N;
	long long sum;
	cin >> N;
	
	int maxI;
	int maxV;
	
	maxV = 0;
	
	sum = 0;
	for(int i = 0; i < N; i++)
		b[i] = true;
	
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
		if(A[i] > maxV)
		{
			maxV = A[i];
			maxI = i;
		}
	}
	
	/*
	for(int i = 0; i < N; i++)
	{
		cout << A[i] << endl;
	}
	cout << maxV << endl << maxI << endl;
	cout << sum/2 << endl;
	cout << "test t" << endl;*/
	
	b[maxI] = false;
	for(int i = 0; i < N; i++)
		c[i] = false;
	
	long long sum2 = 0;
	int cnt2 = 0;
	for(int i = 0; i < N; i++)
	{
		sum2 += A[i];
		if(2*sum2 <= sum)
		{
			
			c[i] = true;
			b[i] = false;
			cnt2++;
		}else{
			sum2 -= A[i];
		}
		
	}
	
	cout << cnt2;
	for(int i = 0; i < N; i++)
	{
		if(c[i])
		{
			cout << ' '<< A[i];
		}
	}
	cout << endl;
	
	cout << N - cnt2 - 1;
	for(int i = 0; i < N; i++)
	{
		if(b[i])
		{
			cout << ' '<< A[i];
		}
	}
	cout << endl;
	
	return 0;
}
