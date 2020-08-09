#include<iostream>
#include<algorithm> 

using namespace std;

typedef struct NODE{
	int index;
	bool type;//true for a, false for b
}Node;

bool myCompare(Node a1, Node a2)
{
	return a1.index < a2.index;
}


Node A[200000];

int main()
{
	int N;
	int present_index;
	int present_value;
	int a, b;
	
	
	cin >> N;
	while(N != 0)
	{
		for(int i = 0; i < N; i++)
		{
			cin >> a >> b;
			A[2*i].index = a;
			A[2*i].type = true;
			A[2*i + 1].index = b + 1;
			A[2*i + 1].type = false;
		}
		sort(A, A + 2*N, myCompare);
		
		present_index = 0;
		present_value = 0;
		
		/*
		//debug
		cout << "debug: ";
		for(int i = 0; i < 2*N; i++)
		{
			cout << A[i].index << ' ';
		}cout << endl;
		*/
		
		for(int i = 1; i < N + 1; i++)
		{
			while(i >= A[present_index].index && present_index < 2*N)
			{
				if(A[present_index].type)
				{
					present_value++;
				}else
				{
					present_value--;
				}
				present_index++;
			}
			cout << present_value;
			if(i != N)
			{
				cout << ' ';
			}
		}
		cout << endl;
		
		
		cin >> N;
	}
	
	
	
	return 0;
 } 
