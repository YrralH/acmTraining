#include<iostream>

using namespace std;

int main()
{
    int numberOfCases; 
	long long n, k;
	cin >> numberOfCases;
	
	for(int caseCount = 0; caseCount < numberOfCases; caseCount++)
	{
		cin >> n >> k;
		if(n >= k)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

    return 0;
}
