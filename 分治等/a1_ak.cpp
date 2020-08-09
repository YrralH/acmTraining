#include<iostream>

using namespace std;

typedef long long LL;

LL A(LL x, LL n, LL mod)
{
	LL ret = (mod != 1);
	for(x %= mod; n; n>>=1, x = x*x%mod)
	{
		if(n&1)
		{
			ret = ret * x % mod;
		}
	}
	return ret;
}

int main()
{
	LL n, m, k, x;
	cin >> n >> m >> k >> x;
	
	LL t = k%(n-1);
	t = k;
	LL last2 = A(10, t, n);
	
	LL mod;
	mod = (last2)%n;
	mod = mod*m%n;
	mod = (mod + x)%n;
	
	cout << mod;
	
	
	return 0;
 } 
