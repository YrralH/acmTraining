#include<bits/stdc++.h>
using namespace std;

int  n,m,a[1000],q[1000],h,t,ans[1000];
int main(){
    scanf("%d%d",&n,&m);//总共有n个数，区间长度为m 
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    h=1;t=0;
    for(int i=1;i<=n;i++){//以i为结尾 
        while(h<=t && a[q[t]]<=a[i])t--;//删去队尾的无用元素 
        q[++t]=i;//进队
        while(i-q[h]>=m)h++;//队头删去在所需区间外的元素 
        if(i>=m)ans[i-m+1]= a[q[h]];
    }
    for(int i=1;i<=n-m+1;i++)printf("%d--%d:%d\n",i,i+m-1,ans[i]);//打印区间最大值
    
}