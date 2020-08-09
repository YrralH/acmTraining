#include<iostream>

using namespace std;

bool A[1024][1024];

int main()
{
	int N;
	cin >> N;
	
	A[0][0] = 0;
	int size = 1;
	
	for(int i = 0; i < N; i++)
	{
		for(int p = 0; p < size; p++)
		{
			for(int q = 0; q < size; q++)
			{
				if(A[p][q] == 1)
				{
					A[p+size][q] = 0;
					A[p][q+size] = 0;
					A[p+size][q+size] = 0;
				}
				else
				{
					A[p+size][q] = 1;
					A[p][q+size] = 1;
					A[p+size][q+size] = 1;
				}
			}
		}
		

		size = size*2;
	}
	
	for(int p = 0; p < size; p++)
	{
		for(int q = 0; q < size; q++)
		{
			cout << A[p][q] << ' ';
		}
		cout << endl;
	}
	
	
	return 0;
} 
