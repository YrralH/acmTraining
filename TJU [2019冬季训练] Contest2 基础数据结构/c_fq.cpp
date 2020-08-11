#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		priority_queue<pair<int,int> > q[3];
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			string x; int y,z;
			cin>>x;
			if (x=="IN")
			{
				cin>>y>>z;
				q[y-1].push(make_pair(z,--cnt));
			}
			else
			{
				cin>>y;
				if (q[y-1].empty())
				{
					cout<<"EMPTY"<<endl;
				}
				else
				{
					cout<<-q[y-1].top().second<<endl;
					q[y-1].pop();
				}
			}
			
		}
	}
	return 0;
}