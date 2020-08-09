#include<iostream>

using namespace std;

const int MAX_SIZE = 100005;

long long A[MAX_SIZE];
long long sum[2][MAX_SIZE];
int choice;
int length;

int main()
{
	int N;
	long long K;
	int count;
	int previous_length;
	int previous_choice;
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	count = 0;
	
	
	for(int i = 0; i < N; i++)
	{
		if(A[i] < K)
		{
			count++;
		}
		
		sum[1][i] = A[i];
	}
	length = 1;
	
	
	for(length = 2, choice = 0; 
		length <= N; 
		length++, choice = 1 - choice)
	{
		previous_length = length - 1;
		previous_choice = 1 - choice;
		
		for(int i = 0; i < N - length + 1; i++)
		{
			sum[choice][i] = sum[previous_choice][i] + A[i + length - 1];
			if(sum[choice][i] < K)
			{
				count++;
			}
		}
		
	}
	
	cout << count;
	
	return 0;
 } 
