#include<iostream>
#include"string.h"

using namespace std;


bool ifPrime1[10000];
bool ifPrime2[10000];

void primeListInit(bool list[], int length)
{
	/*
	for(int i = 0; i < length; i++)
	{
		list[i] = true;
	}*/
	
	//try memset
	memset(list, 0x1, length); 
	
	return;
}

//°£ÊÏÉ¸·¨ 
void filterPrime1(bool list[], int length)
{
	int present_prime;
	int tmp;
	bool flag;
	
	//init
	present_prime = 2;
	primeListInit(list, length);
	list[0] = false;
	flag = true;
	
	while(flag)
	{
		//filter
		tmp = present_prime * 2;
		while(tmp < length)
		{
			list[tmp] = false;
			tmp = tmp + present_prime;
		}
		
		/*
		//debug
		cout << endl << "debug-present_prime" << endl;
		cout << present_prime << endl;
		*/
		
		present_prime++;
	
		while(!list[present_prime])
		{
			if(present_prime >= length)
			{
				flag = false;
				break;
			} else
			{
				present_prime++;
			}
		}
	}
	
	return;	
}

void printPrime(bool list[], int length)
{
	int cnt;
	cnt = 0;
	for(int i = 0; i < length; i++)
	{
		if(list[i])
		{
			cout << i << ' ';
			cnt++;
		}
	}
	cout << endl;
	cout << cnt << " numbers in total." << endl;
}

int main()
{
	int length;
	length = 1000;
	
	//primeListInit(ifPrime1, length);
	//primeListInit(ifPrime2, length);
	
	filterPrime1(ifPrime1, length);
	
	printPrime(ifPrime1, length);
	
	cout << "length: " << length << endl;
	
	return 0;
 } 
