#include<bits/stdc++.h>

using namespace std;

int main()
{
	int numOfCases;
	cin >> numOfCases;
	
	string s;
	string s1, s2;
	string s1e, s2e;
	
	bool mid1, mid2;
	
	int l;
	
	
	for(int caseCount = 0; caseCount < numOfCases; caseCount++)
	{
		cin >> s;
		l = s.length();
		
		s1 = "";
		s1e = ""; 
		mid1 = false;
		for(int i = 0; i < (l+1)/2; i++)
		{
			if(s[i] == s[l - i - 1])
			{
				s1.append(s[i]);
				s1e = s[i] + s1e;
			}else{
				if(2*i < length)
				{
					s1.append(s[i]);
				}
			}
		}
		s1.append(s1e);
		
		s2 = "";
		s2e = ""; 
		mid2 = false;
		for(int i = l - 1; i > l/2; i++)
		{
			if(s[i] == s[l - i - 1])
			{
				s1.append(s[i]);
				s1e = s[i] + s1e;
			}else{
				if(2*i < length)
				{
					s1.append(s[i]);
				}
			}
		}
		s1.append(s1e);
		
		
	}
	
	return 0;
 } 
