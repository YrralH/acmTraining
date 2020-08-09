#include<bits/stdc++.h>
using namespace std;
struct mat{
    long long val[3][3];
};
mat mul(mat a,mat b)
{
    mat c;
    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    {
        c.val[i][j] = 0;
    }

    for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    for (int k=0;k<3;k++)
    {
        c.val[i][k] = (c.val[i][k]+a.val[i][j] * b.val[j][k])%998244353;
    }
    return c;
}

mat bin(mat a,long long k)
{
    mat res;
    res.val[0][0] = 1;
    res.val[0][1] = 0;
    res.val[0][2] = 0;
    res.val[1][0] = 0;
    res.val[1][1] = 1;
    res.val[1][2] = 0;
    res.val[2][0] = 0;
    res.val[2][1] = 0;
    res.val[2][2] = 1;
    while (k)
    {
        if (k&1) res = mul(res,a);
        a = mul(a,a);
        k>>=1;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    mat raw;
    raw.val[0][0] = 2;
    raw.val[0][1] = 1;
    raw.val[0][2] = 2;
    raw.val[1][0] = 1;
    raw.val[1][1] = 0;
    raw.val[1][2] = 0;
    raw.val[2][0] = 0;
    raw.val[2][1] = 1;
    raw.val[2][2] = 0;
    while (n--)
    {
        long long x;
        cin>>x;
        if (x<3) cout<<x<<endl;
        else
        {
            mat res = bin(raw,x-2);
            cout << res.val[0][0] << endl;
            cout << res.val[0][1] << endl;
            cout<<(2*res.val[0][0] + res.val[0][1])%998244353<<endl;
        }
    }
    return 0;
}
