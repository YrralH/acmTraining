#include<iostream>
#include<algorithm>

using namespace std;

typedef struct PAN{
    int t;//time
    int p;//postition
}Pan;

int N;
long long dp[11];
int present_T;
Pan pancake[100010];
long long ans;

void solve();
bool cmp_pan(const Pan p1, const Pan p2)

int main()
{
    int N;
    while(true)
    {
        scanf("%d", &N);
        if(N == 0)
            break;

        printf("%lld", ans);
    }
    
    

    return 0;
}

void solve()
{
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &pancake[i].p);
        scanf("%d", &pancake[i].t);
    }
    sort(pancake, pancake + N, cmp_pan);

}

bool cmp_pan(const Pan p1, const Pan p2)
{
    return p1.t < p2.t;
}