#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int LINES = 100010;
const int PER_LINE = 13;

int dp[LINES][PER_LINE];
int pancake[LINES][PER_LINE];
int maxOf3(const int a, const int b, const int c)
{
    return max(a, max(b, c));
}
int solve(int N)
{
    memset(dp, 0, sizeof(int)*LINES*PER_LINE);
    memset(pancake, 0, sizeof(int)*LINES*PER_LINE);

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
        }
    }

    return dp[0][6];
}



int main()
{
    int NN;
    while(true)
    {
        scanf("%d", &NN);
        if(NN == 0)
            break;
        int ans = solve(NN);

        printf("%d\n", dp[0][6]);
    }
    return 0;
}



