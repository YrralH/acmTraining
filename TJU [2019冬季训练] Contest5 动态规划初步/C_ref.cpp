#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int pai[13][100010];
int dp[100010][13];

int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(pai,0,sizeof(pai));
        memset(dp,0,sizeof(dp));

        int time=0;

        for(int i=1;i<=n;i++){ 
            int x,T; 
            scanf("%d%d",&x,&T); 
            x++; 
            pai[x][T]++; 
            time=max(time,T); 
        } 
        for(int i=time;i>=0;i--){
            for(int j=1;j<=11;j++){
                dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
                dp[i][j]+=pai[j][i];
            }
        }
        cout<<dp[0][6]<<endl;
    }
}