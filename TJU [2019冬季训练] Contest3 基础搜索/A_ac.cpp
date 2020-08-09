#include<iostream>
#include<cstring>

using namespace std;

int computeMinimalPathNumber_withSimpleBFS(int src, int tgt);

bool ifPrime[10000];
bool ifVisit[10000];

void primeListInit(bool list[], int length)
{
	memset(list, 0x1, length); 
	return;
}

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

void _debug_printPrime(bool list[], int length)
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

void preparePrimeList()
{
	filterPrime1(ifPrime, 10000);
	//_debug_printPrime(ifPrime, 10000);
	return;
}



int main()
{
	int numberOfCase;
	preparePrimeList();
	

	int src;
	int tgt;
	int minimalPathNum;
	
	cin >> numberOfCase;
	 
	for(int i = 0; i < numberOfCase; i++)
	{
		cin >> src >> tgt;
		
		
		minimalPathNum = computeMinimalPathNumber_withSimpleBFS(src, tgt);
		
		
		if(minimalPathNum >= 0)
			cout << minimalPathNum << endl;
		else
			cout << "Impossible" << endl;
	} 
	
	return 0;
 } 
 
int computeMinimalPathNumber_withSimpleBFS(int src, int tgt)
{
	int ans;
	int cnt;
	int flag;
	int* srcList = new int[10000];
	int* tgtList = new int[10000];
	int srcListLength;
	int tgtListLength;
	
	
	const int tmpDivideList[4] = {1, 10, 100, 1000};
	
	//tmp value
	int base;
	int bais;
	int tmpValueForBaseCompute;
	int tmpTargetLengthCnt;
	int tmpValue;
	
	
	//init
	for(int i = 0; i < 10000; i++)
	{
		ifVisit[i] = false;
	}
	
	cnt = 1;
	flag = true;
	srcListLength = 0;
	tgtListLength = 0;
	
	//init first search
	ifVisit[src] = true;
	srcList[0] = src;
	srcListLength = 1;
	
	if(src == tgt)
	{
		ans = 0;
		flag = false;
	}
	
	while(flag)
	{
		tmpTargetLengthCnt = 0;
		for(int srcIndex = 0; srcIndex < srcListLength; srcIndex++)
		{
			tmpValueForBaseCompute = srcList[srcIndex];
			for(int i = 0; i < 4; i++)
			{
				bais = tmpValueForBaseCompute % 10;
				for(int ii = 0; ii < i; ii++)
					bais = bais * 10;
				base = srcList[srcIndex] - bais;
				bais = 1;					
				for(int ii = 0; ii < i; ii++)
					bais = bais * 10;
					
				tmpValueForBaseCompute = tmpValueForBaseCompute / 10;	
				
				//debug
				//cout << endl << "debug:" << endl;
				//cout << "bais " << bais << endl;
				//cout << "base " << base << endl;
				
				
				for(int j = 0; j < 10; j++)
				{
					tmpValue = base + bais * j;
					//debug
					
					if(tmpValue > 999 && !ifVisit[tmpValue] && ifPrime[tmpValue])
					{
						//cout << "tmpValue: " << tmpValue << endl;
						//cout << "parent" << srcList[srcIndex] << endl;
						//cout << "cnt: " << cnt << endl;
						if(tmpValue == tgt)
						{
							flag = false;
							ans = cnt;
							break;
						}
						
						ifVisit[tmpValue] = true;
						tgtList[tmpTargetLengthCnt] = tmpValue;
						tmpTargetLengthCnt++;
					}
				}
			}
			if(!flag)
			{
				break;
			}
		}
		
		if(!flag)
		{
			break;
		}
		
		tgtListLength = tmpTargetLengthCnt;
		for(int i = 0; i < tgtListLength; i++)
		{
			srcList[i] = tgtList[i];
		}
		srcListLength = tgtListLength;
		
		if(srcListLength == 0)
		{
			ans = -1;
			break;
		}
		
		cnt++;
	}
	
	
	delete[] srcList;
	delete[] tgtList;
	
	//cout << "ans:" << ans << endl;
	return ans;
}
 
 
