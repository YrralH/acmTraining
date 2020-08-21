
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[4005],b[4005];
int na[4005][2];
int nb[4005][2];
int lena,lenb;
int ans[4005][4005];
int hhh[4005][4005];
int fuck(int x,int y)
{
	if (x>lena && y>lenb) return 0;
	if (ans[x][y]) return ans[x][y];
	int t0=fuck(na[x][0],nb[y][0]);
	int t1=fuck(na[x][1],nb[y][1]);
	if (t0<=t1)
	{
		hhh[x][y] = 0;
		return ans[x][y]=t0+1;
	}
	else
	{
		hhh[x][y] = 1;
		return ans[x][y]=t1+1;
	}
	
}
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	lena = strlen(a+1);
	lenb = strlen(b+1);
	na[lena+1][0] = lena+1;
	na[lena+1][1] = lena+1;
	nb[lenb+1][0] = lenb+1;
	nb[lenb+1][1] = lenb+1;
	for (int i=lena;i>=0;i--)
	{
		na[i][0] = a[i+1]=='0' ? i+1:na[i+1][0];
		na[i][1] = a[i+1]=='1' ? i+1:na[i+1][1];
	}
	for (int i=lenb;i>=0;i--)
	{
		nb[i][0] = b[i+1]=='0' ? i+1:nb[i+1][0];
		nb[i][1] = b[i+1]=='1' ? i+1:nb[i+1][1];
	}
	fuck(0,0);
	int x=0,y=0;
	while (x<=lena || y<=lenb)
	{
		int ttt = hhh[x][y];
		putchar(ttt+'0');
		x=na[x][ttt];
		y=nb[y][ttt];
	}
	putchar('\n');
	return 0;
}