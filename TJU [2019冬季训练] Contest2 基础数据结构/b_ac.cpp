#include<iostream>

using namespace std;

int main()
{
	int cnt;
	bool flag;
	int res;
	string s;
	
	while(cin >> s)
	{
		//debug
		//cout << endl << "debug: s" << endl;
		//cout << s << endl;
		
		cnt = 0;
		flag = false;
		
		for(int i = 0; i < s.length(); i++)
		{
			switch(s[i])
			{
				case '(':
					cnt++;
					break;
				case ')':
					cnt--;
					break;
				case 'B':
					res = cnt;
					flag = true;
					break;
				default:
					break;
			}
			
			if(flag)
			{
				break;
			}
		}
		cout << res << endl;
	}
	
	
	return 0;
}
