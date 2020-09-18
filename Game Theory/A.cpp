#include<iostream>

using namespace std;

int main()
{
	int m, n;
	int a; 
	while(cin >> m >> n)
	{
		if(n > m)
		{
			for(int i = m; i <= n; i++)
			{
				cout << i;
				if(i != n)
				{
					cout << ' ';
				} 
			}
			cout << endl;
			continue;
		}
		if(n == m)
		{
			cout << n << endl;
			continue;
		}
		if(n < m)
		{
			a = m%(n + 1);
			if(a == 0)
			{
				cout << "none" << endl;
			}else
			{
				cout << a << endl;
			}
		}
	}
	
	return 0;
}
