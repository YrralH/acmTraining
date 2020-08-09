#include<iostream>

using namespace std;

int main()
{
	int numberOfCase;
	int numberOfCMD;
	string typeString;'
	bool type;
	
	cin >> numberOfCase;
	for(int caseCount = 0; caseCount < numberOfCase; caseCount++)
	{
		cin >> numberOfCMD;
		cin >> typeString;
		if(typeString.compare("FIFO") == 0)
		{
			type = true;
		}else
		{
			type = false;
		}
		
		
		
	}
	
	
	return 0;
 } 
