#include<stdio.h>
#include<iostream>

using namespace std;

int n, k;
int a[1000000];
int q[1000000];


void getMin(bool flag)
{
	int left, right;
	left = 0;
	right = 1;
	q[0] = 0;
	
	for(int i = 0; i < n; i++)
	{
		//try to get in the queue
		if(flag)
			while(left < right && a[i] < a[q[right-1]])
				right--;
		else
			while(left < right && a[i] > a[q[right-1]])
				right--;
		q[right] = i;
		right++;

		while(q[left] <= i - k)
			left++;

		if(i >= k - 1)
			printf("%d ", a[q[left]]);
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
