#include<iostream>
#include<cstdio>
using namespace std;
char a[10][10];
int ans,n,k;
bool used[10];

void work(int x,int y)
{
    if (x==n)
    {
        ans++;
        return ;
    }

    if (n-x>y) work(x+1,y);

    if (y>0)
    for (int i=0;i<n;i++)
    if (a[x][i]=='#' && used[i]==false)
    {
        used[i]=true;
        work(x+1,y-1);
        used[i]=false;
    }
}

int main()
{
    while (cin>>n>>k)
    {
        if (n==-1) return 0;
        for (int i=0;i<n;i++) scanf("%s",a[i]);
        ans = 0;
        work(0,k);
        cout<<ans<<endl;
    }
    return 0;
}