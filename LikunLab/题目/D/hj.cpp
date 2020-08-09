#include<iostream>

using namespace std;

void Mod(long long* p)
{
	for(int i = 0; i < 9; i++)
	{
		p[i] = p[i] % 998244353;
	}
	return;
}

void Multi(long long* p)
{
	long long tmp[9];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			tmp[i + j*3] = 0;
			for(int x = 0; x < 3; x++)
			{
				tmp[i + j*3] += p[i + 3*x] * p[x + 3*j];
			}
		}
	}
	
	for(int i = 0; i < 9; i++)
	{
		p[i] = tmp[i];
	}
}

void Multi(long long* src, long long* dst)
{
	long long tmp[9];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			tmp[i + j*3] = 0;
			for(int x = 0; x < 3; x++)
			{
				tmp[i + j*3] += src[i + 3*x] * dst[x + 3*j];
			}
		}
	}
	
	for(int i = 0; i < 9; i++)
	{
		dst[i] = tmp[i];
	}
	return;
}

void MultiAndMod(long long* p)
{
	Multi(p);
	Mod(p);
	return;
}

void MultiAndMod(long long* src, long long* dst)
{
	Multi(src, dst);
	Mod(dst);
	return;
}

long long* fastMulti(long long times)
{
	long long* t = new long long [9];
	long long* res = new long long[9];
	
	t[0] = 2;
	t[1] = 1;
	t[2] = 2;
	
	t[3] = 1;
	t[4] = 0;
	t[5] = 0;
	
	t[6] = 0;
	t[7] = 1;
	t[8] = 0;
	
	res[0] = 1;
	res[1] = 0;
	res[2] = 0;
	
	res[3] = 0;
	res[4] = 1;
	res[5] = 0;
	
	res[6] = 0;
	res[7] = 0;
	res[8] = 1;
	for(Mod(t); times; times >>= 1, MultiAndMod(t))
	{
		//cout << "times " << times << " t0 " << t[0] << endl;
		if(times & 1)
		{
			MultiAndMod(t, res);
			/*
			for(int ii = 0; ii < 9; ii++)
			{
				cout << "res " << ii << " " << res[ii] << endl;
			}*/
		}
	}
	delete t;
	
	/*
	cout << "res mat:" << endl;
	for(int i = 0; i < 9; i++)
	{
		cout << res[i] << endl;
	}
	cout << "res mat end" << endl;
	*/
	return res;
}

long long getResult(long long x)
{
	long long* p;
	p = fastMulti(x-2);
	long long res;
	//cout << "p0 1: " << p[0] << ' ' << p[1] << endl;
	res = (p[0]*2 + p[1]) % 998244353;
	delete p;
	return res;
}


int main(){
	int numberOfCases;
	
	cin >> numberOfCases;
	long long x;
	
	for(int caseCount = 0; caseCount < numberOfCases; caseCount++)
	{
		cin >> x;
		cout << getResult(x) << endl;
	}
	
	
	
	return 0;
}
