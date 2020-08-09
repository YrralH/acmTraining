#include<iostream>

using namespace std;

int main()
{
	int cnt;
	int res;
	string s;
	
	while(cin >> s)
	{
		//debug
		//cout << endl << "debug: s" << endl;
		//cout << s << endl;
		
		cnt = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '(')
			{
				cnt++;
			}
			if(s[i] == ')')
			{
				cnt--;
			}
			if(s[i] == 'B')
			{
				res = cnt;
				break;
			}
		}
		cout << res << endl;
	}
	
	
	return 0;
}
