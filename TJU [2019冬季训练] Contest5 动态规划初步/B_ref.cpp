#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1003;
int t, n, m;
int dp[maxn][maxn], v[maxn], w[maxn], path[maxn][maxn];
int main() {
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        //memset(path, 0, sizeof(path));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)scanf("%d", &v[i]);
        for (int i = 1; i <= n; i++)scanf("%d", &w[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (w[i] > j) //当前容量j小于物品i的重量，装不下
                    dp[i][j] = dp[i - 1][j];
                else {  //可以装，取不装和装的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                    //if (dp[i - 1][j - w[i]] + v[i] > dp[i - 1][j])//记录路径
                    //    path[i][j] = 1;
                }
        printf("%d\n", dp[n][m]);
        /*for (int i = n, j = m; i >0 && j > 0;i--) {  //输出方案
            if (path[i][j]) {
                printf("%d ", i);
                j -= w[i];
            }
        }*/
    }
    return 0;
}
