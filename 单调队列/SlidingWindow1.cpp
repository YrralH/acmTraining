#include<stdio.h>
#include<iostream>

using namespace std;

int n, k;
int a[1000000];

int ans_min[1000000];
int ans_max[1000000];

int q[1000000];



void show(int* _a)
{
	cout << "show" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << _a[i] << ' '; 
	}
	cout << endl;
	return;
}

void getMin(bool flag)
{
	int left, right;
	left = 0;
	right = 1;
	
	q[0] = 0;

	
	for(int i = 0; i < k - 1; i++)
	{
		//try to get in the queue
		if(flag)
		{
			while(left < right && a[i] < a[q[right-1]])
			{
				right--;
			}
		}else
		{
			while(left < right && a[i] > a[q[right-1]])
			{
				right--;
			}
		}

		q[right] = i;
		right++;
		
		//show(qmin_value);
		//show(qmin_index);
	}
	
	for(int i = k - 1; i < n; i++)
	{
		//try to get in the queue
		if(flag)
		{
			while(left < right && a[i] < a[q[right-1]])
			{
				right--;
			}
		}else
		{
			while(left < right && a[i] > a[q[right-1]])
			{
				right--;
			}
		}

		q[right] = i;
		right++;
		
		//show(qmin_value);
		//show(qmin_index);
		
		while(q[left] <= i - k)
		{
			left++;
		}
		
		//show(qmin_value);
		//show(qmin_index);
		
		
		printf("%d ", a[q[left]]);
		/*
		if(flag)
		{
			ans_min[i] = a[q[left]];
		}else
		{
			ans_max[i] = a[q[left]];
		}*/
		
	}
	
	return;
}


int main()
{
	scanf("%d%d", &n, &k);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	getMin(true);printf("\n");
	getMin(false);
	
	
	return 0;
 } 
