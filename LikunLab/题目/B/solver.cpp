#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main()
{
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    for (int i=3;i<500000;i++)
    a[i] = ((2*a[i-1]%998244353+a[i-2])%998244353 + 2*a[i-3]%998244353)%998244353;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        cout<< a[x]<<endl;
    }
    return 0;
}