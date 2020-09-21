#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int LINES = 100010;
const int PER_LINE = 13;

int ans;
int dp[LINES][PER_LINE];
int pancake[LINES][PER_LINE];

int solve(int N);
int maxOf3(const int a, const int b, const int c);

int main()
{
    int N;
    while(true)
    {
        scanf("%d", &N);
        if(N == 0)
            break;
        
        ans = solve(N);
        /*
        int tmp_p;
        int tmp_t;

        memset(dp, 0, sizeof(dp));
        memset(pancake, 0, sizeof(pancake));

        for(int i = 0; i < N; i++)
        {
            scanf("%d", &tmp_p);
            scanf("%d", &tmp_t);
            pancake[tmp_t][tmp_p + 1]++;
        }

        for(int i = LINES - 1; i >= 0; i--)
            for(int j = 1; j <= 11; j++)
                dp[i][j] = maxOf3(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]) + pancake[i][j];
        */
        printf("%d\n", dp[0][6]);
    }
    
    

    return 0;
}

int solve(int N)
{
    memset(dp, 0, sizeof(dp));
    memset(pancake, 0, sizeof(pancake));
    //memset(dp, 0, sizeof(int)*LINES*PER_LINE);
    //memset(pancake, 0, sizeof(int)*LINES*PER_LINE);

    int tmp_p;
    int tmp_t;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &tmp_p);
        scanf("%d", &tmp_t);
        pancake[tmp_t][tmp_p + 1]++;
    }

    for(int i = LINES - 1; i >= 0; i--)
    {
        for(int j = 1; j <= 11; j++)
        {
            dp[i][j] = maxOf3(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]) + pancake[i][j];
            /*
            switch(j)
            {
                case 0:
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + pancake[i][j];
                    break;
                case PER_LINE - 1: 
                    dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j]) + pancake[i][j];
                    break;
                default:
                    dp[i][j] = maxOf3(dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]) + pancake[i][j];
                    break;
            }*/
        }
    }

    //ans = dp[0][6];
    return 0;
}

int maxOf3(const int a, const int b, const int c)
{
    return max(a, max(b, c));
}
