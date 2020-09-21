#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct PAN{
    int t;//time
    int p;//postition
}Pan;

int dp[11];
Pan pancake[100010];
int bias[11];
int ans;

void solve(int N);
bool cmp_pan(const Pan p1, const Pan p2);
void b_clear();
void b_update(const int mid, const int r, const int spread_t);
void b_update_hyper(const int mid, const int r, const int spread_t);
void b_add();
void _debug_print_dp();

int main()
{
    int N;
    while(true)
    {
        scanf("%d", &N);
        if(N == 0)
            break;
        
        solve(N);

        printf("%d\n", ans);
    }
    
    

    return 0;
}

void solve(int N)
{
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &pancake[i].p);
        scanf("%d", &pancake[i].t);
    }

    sort(pancake, pancake + N, cmp_pan);

    int present_T, previous_T,  tmp_T;
    int present_P, tmp_P;

    previous_T = 0;
    present_T = 0;
    present_P = -1;
    b_clear();

    for(int i = 0; i < N; i++)
    {
        tmp_T = pancake[i].t;
        tmp_P = pancake[i].p;

        if(tmp_T < abs(tmp_P - 5))
        {
            continue;
        }

        if(tmp_T > present_T)
        {
            b_add();
            b_clear();
            _debug_print_dp();

            previous_T = present_T;
            present_T = tmp_T;
            
            b_update(tmp_P, present_T - previous_T, tmp_T);
            present_P = tmp_P;
        }else{
            //tmp_T = present_T;
            if(present_P == tmp_P)
            {
                b_update_hyper(tmp_P, present_T - previous_T, tmp_T);
            }else{
                b_update(tmp_P, present_T - previous_T, tmp_T);
            }
            
            present_P = tmp_P;
        }
    }
    b_add();
    _debug_print_dp();

    ans = 0;
    for(int i = 0; i < 11; i++)
    {
        if(ans < dp[i])
        {
            ans = dp[i];
        }
    }
    return;
}

bool cmp_pan(const Pan p1, const Pan p2)
{
    return (p1.t == p2.t) ? (p1.p < p2.t) : (p1.t < p2.t);
}

void b_clear()
{
    memset(bias, 0, sizeof(int)*11);
    return;
}

void b_update(const int mid, const int r, const int spread_t)
{
    int left = max(mid - r, 0);
    int right = min(mid + r, 10);

    left = max(left, 5 - spread_t);
    right = min(mid, 5 + spread_t);

    for(int i = left; i <= right; i++)
    {
        if(bias[i] < 1)
        {
            bias[i] = 1;
        }
    }
    return;
}

void b_update_hyper(const int mid, const int r, const int spread_t)
{
    int left = max(mid - r, 0);
    int right = min(mid + r, 10);

    left = max(left, 5 - spread_t);
    right = min(mid, 5 + spread_t);

    for(int i = left; i <= right; i++)
    {
        bias[i]++;
    }
    return;
}

void b_add()
{
    for(int i = 0; i < 11; i++)
    {
        dp[i] += bias[i];
    }
    return;
}

void _debug_print_dp()
{
    printf("\n---debug-print-dp---\n");
    for(int i = 0; i < 11; i++)
    {
        printf("%d ", dp[i]);
    }
    printf("\n--debug-end--\n");
    return;
}