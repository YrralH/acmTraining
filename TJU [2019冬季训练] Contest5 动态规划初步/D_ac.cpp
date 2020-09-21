#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 2005;

int time1[SIZE];
int time2[SIZE];
int dp[SIZE];

int main()
{
    int N;
    scanf("%d", &N);
    for(int testCnt = 0; testCnt < N; testCnt++)
    {
        int K;
        scanf("%d", &K);
        for(int i = 1; i <= K; i++)
            scanf("%d", &time1[i]);

        for(int i = 1; i <= K - 1; i++)
            scanf("%d", &time2[i]);

        dp[1] = time1[1];
        dp[2] = min(time1[1] + time1[2], time2[1]);

        for(int i = 3; i <= K; i++)
        {
            dp[i] = min(time1[i] + dp[i - 1],
                        time2[i - 1] + dp[i - 2]);
        }

        int total_time = dp[K];
        int tmp_time;
        bool if_am;
        int HH, MM, SS;
        
        SS = total_time % 60;
        tmp_time = total_time / 60;
        MM = tmp_time % 60;
        HH = 8 + tmp_time / 60;

        if(HH > 12)
        {
            HH -= 12;
            if_am = false;
        }else{
            if_am = true;
        }
        printf("%02d:%02d:%02d ", HH, MM, SS);
        if(if_am)
            printf("am\n");
        else
        {
            printf("pm\n");
        }
    }


    return 0;
}