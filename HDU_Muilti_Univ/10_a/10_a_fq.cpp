#include<vector>
#include<cstdio>
using namespace std;
// test vector
vector<int> a[500010];
int b[500010],n;
long long ss;
void fuck1(int x)
{
    b[x] = 1;
    for (vector<int>::iterator it = a[x].begin();it!=a[x].end();it++)
    {
        fuck1(*it);
        b[x]+=b[*it];
    }
    ss+=b[x];
}
long long fuck2(int x)
{
    long long ans = 0;
    for (vector<int>::iterator it = a[x].begin();it!=a[x].end();it++)
    {
        ans = max(ans,fuck2(*it));
    }
    return ans+n-b[x];
}
int main()
{
    int t; scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ss = 0;
        for (int i=1;i<=n;i++)
        vector<int>().swap(a[i]);
        for (int i=2;i<=n;i++)
        {
            int tmp; scanf("%d",&tmp);
            a[tmp].push_back(i);
        }
        fuck1(1);
        printf("%lld\n",ss+fuck2(1));
    }
    return 0;
}