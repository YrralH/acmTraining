#include<iostream>
#include<algorithm>

using namespace std;

int dp[105];
int dp_t[105];

int process_a_case();
void dp_update(int index, int max_index, int tmp);

int main()
{
    int T;
    int ans;
    scanf("%d", &T);

    for(int testCount = 0; testCount < T; testCount++)
    {
        ans = process_a_case();
        printf("%d\n", ans);
    }

    return 0;
}

int process_a_case()
{
    int ans;
    int tmp;
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        if(i == 1)
        {
            scanf("%d", &tmp);
            dp_t[1] = tmp;
        }else{
            for(int j = 1; j <= i; j++)
            {
                scanf("%d", &tmp);
                dp_update(j, i - 1, tmp);
            }
        }

        memcpy(dp, dp_t, sizeof(int)*(N + 1));
    }


    ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    return ans;
}

void dp_update(int index, int max_index, int tmp)
{
    int candi1 = (index - 1 >= 0) ? dp[index - 1] : 0;
    int candi2 = (index <= max_index) ? dp[index] : 0;
    dp_t[index] = max(candi1, candi2) + tmp;
    return;
    
}