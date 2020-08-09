#include<iostream>

using namespace std;

int main()
{
	const int Bias = 'A' - 'a';
	int numberOfCases;
	
	cin >> numberOfCases;
		
	
	string s;
	getline(cin, s);
	for(int caseCount = 0; caseCount < numberOfCases; caseCount++)
	{
		getline(cin, s);
		
		//task1
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] = s[i] + Bias;
			}
		}
		
		//task2
		if(s.length() >= 2)
		{
			for(int i = 0; i < s.length() - 1; i++)
			{
				if(s[i] == 'H' && s[i+1] == 'I')
				{
					s[i] = 'L';
					s[i+1] = 'O';
				}
			}
		}

		
		//task3&4
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] != 'X')
			{
				cout << '#' << s[i];
			}
		}
		cout << endl;
		
		
	}
	
	
	
	return 0;
}
