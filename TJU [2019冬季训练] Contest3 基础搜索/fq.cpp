#include<iostream>
#include<queue>
using namespace std;
bool prim[10000];
int dis[10000];
int main()
{
	// 清空
	for (int i=2;i<10000;i++)
	prim[i] = true;

	// 质数表
	for (int i=2;i<10000;i++)
	if (prim[i])
	{
		int tmp = i<<1;
		while (tmp<10000)
		{
			prim[tmp]=false;
			tmp+=i;
		}
	}

	// 处理
	int n;
	cin>>n;
	while (n--)
	{
		int x,y; cin>>x>>y;

		for (int i=0;i<10000;i++) dis[i] = -1;
		dis[x] = 0;

		// bfs
		queue<int> q;
		q.push(x);
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			int mul = 1;
			for (int j=0;j<4;j++)
			{
				int num = top/mul%10;
				for (int i=0;i<10;i++)
				{
					int tmp = top+(i-num)*mul;
					if(prim[tmp]&&dis[tmp]==-1&&tmp>999)
					{
						q.push(tmp);
						dis[tmp]=dis[top]+1;
					}
				}
				mul*=10;
			}
		}
		if (dis[y]==-1) cout<<"Impossible"<<endl;
		else cout<<dis[y]<<endl;
	}
	return 0;
}