#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int pancake[100010][13];
int dp[100010][13];

int maxOf3(const int a, const int b, const int c)
{
    return max(a, max(b, c));
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n == 0)
            break;
        
        memset(dp, 0, sizeof(dp));
        memset(pancake, 0, sizeof(pancake));
    //memset(dp, 0, sizeof(int)*LINES*PER_LINE);
    //memset(pancake, 0, sizeof(int)*LINES*PER_LINE);

        int tmp_p;
        int tmp_t;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp_p);
            scanf("%d", &tmp_t);
            pancake[tmp_t][tmp_p + 1]++;
        }

    for(int i = 100010 - 1; i >= 0; i--)
    {
        for(int j = 1; j <= 11; j++)
        {
                dp[i][j] = maxOf3(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]) + pancake[i][j];
            }
        }
        printf("%d\n", dp[0][6]);
    }
    return 0;
}