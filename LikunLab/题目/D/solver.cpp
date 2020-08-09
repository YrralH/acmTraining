#include<bits/stdc++.h>
using namespace std;
int times(long long x1,long long y1,long long x2,long long y2,long long x,long long y)
{
    long long tx = x-x1;
    long long ty = y-y1;
    long long ttx = x-x2;
    long long tty = y-y2;
    long long res = tx * tty - ty * ttx;
    if (res>0) return 1;
    if (res<0) return -1;
    return 0;
}

bool inside(long long x1,long long y1,long long x2,long long y2,long long x,long long y)
{
    return x>=x1 && x<=x2 && y>=y1 && y<=y2; 
}

int main()
{
    int n; cin>>n;
    for (int i=0;i<n;i++)
    {
        long long x1,y1,x2,y2;
        long long xx1,yy1,xx2,yy2;
        
        cin>>x1>>y1>>x2>>y2>>xx1>>yy1>>xx2>>yy2;
        int tmp1 = times(x1,y1,x2,y2,xx1,yy1);
        int tmp2 = times(x1,y1,x2,y2,xx2,yy2);
        int f1 =  tmp1*tmp2;
        int tmp3 = times(xx1,yy1,xx2,yy2,x1,y1);
        int tmp4 = times(xx1,yy1,xx2,yy2,x2,y2);
        int f2 =  tmp3*tmp4;
        if (tmp1 == 0 && tmp2 == 0)
        {
            if (inside(x1,y1,x2,y2,xx1,yy1) || inside(x1,y1,x2,y2,xx2,yy2)
                || inside(xx1,yy1,xx2,yy2,x1,y1) || inside(xx1,yy1,xx2,yy2,x2,y2))
            {
                cout<<"yes"<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
        }
        else
        {
            if (f1<=0 && f1<=0)
            {
                cout<<"yes"<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
        }

    }
    return 0;
}