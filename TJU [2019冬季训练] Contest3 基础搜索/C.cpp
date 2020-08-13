#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main_solver(int N, int M);
int BFS(int n, int m);
int gcd1(int a,int b);

int main()
{
    int S, N, M;
    int ans;

    while(true)
    {
        cin >> S >> N >> M;
        if(S == 0)
            break;

        ans = main_solver(N, M);
        if(ans >= 0)
            cout << ans << endl;
        else
        {
            cout << "NO" << endl;
        }
        


    }
    
    return 0;
}

int gcd1(int a,int b)
{
	while(b ^= a ^= b ^= a %= b); 	
    return a;
}

int main_solver(int N, int M)
{
    int ans;
    int gcd = gcd1(N, M);
    int n;
    int m;
    int s;

    n = N / gcd;
    m = M / gcd;
    s = n + m;

    if(s%2 != 0)
    {
        ans = -1;
    } else
    {
        ans = BFS(n, m);
    }
    

    return ans;
}

int BFS(int n, int m)
{
    int ans;
    int dist[120]; //s < 120, s = n + m 


    return ans;
}