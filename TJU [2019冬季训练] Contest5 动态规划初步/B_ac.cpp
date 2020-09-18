//Bone Collector HDU - 2602
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N, V;
int ans;
int value[1005];
int volume[1005];
int dp[1005][1005];
//dp[volume][index]

void solve();

int main()
{
    int T;
    scanf("%d", &T);
    for(int testCount = 0; testCount < T; testCount++)
    {
        scanf("%d%d", &N, &V);
        for(int boneCount = 1; boneCount <= N; boneCount++)
            scanf("%d", &value[boneCount]);
        for(int boneCount = 1; boneCount <= N; boneCount++)
            scanf("%d", &volume[boneCount]);
        
        solve();

        ans = dp[V][N];
        printf("%d\n", ans);
    }
    return 0;
}

void solve()
{
    for(int v = 0; v <= N; v++)
        dp[0][v] = 0;

    int candi1;
    for(int i = 1; i <= N; i++)
    {
        for(int v = 0; v <= V; v++)
        {
            if(v - volume[i] >= 0)
                candi1 = dp[v - volume[i]][i-1] + value[i];
            else
                candi1 = 0;

            dp[v][i] = max(dp[v][i-1], candi1);
        }
    }
    return;
}