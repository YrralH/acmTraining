#include<iostream>

using namespace std;

const int myInf = 0x3f3f3f3f;
int dist[200][200];

void clear(const int size);
void std_in(const int edge_num);
void solve_floyd(int size);
void _debug_print_all_dist(int N);


int main()
{
    int N, M;
    int src, dest;
    int ans;

    while(cin >> N >> M)
    {
        clear(N);
        std_in(M);

        cin >> src >> dest;

        //_debug_print_all_dist(N);
        solve_floyd(N);
        //_debug_print_all_dist(N);

        ans = dist[src][dest];
        if (ans >= myInf - 5) 
            ans = -1;
        
        cout << ans << endl;
    }

    return 0;
}

void clear(const int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            dist[i][j] = myInf;
        }
    }
    for(int i = 0; i < size; i++)
    {
        dist[i][i] = 0;
    }
    return;
}

void std_in(const int edge_num)
{
    int a, b, x;
    for(int i = 0; i < edge_num; i++)
    {
        cin >> a >> b >> x;
        if(x < dist[a][b])
        {
            dist[a][b] = x;
            dist[b][a] = x;
        }
        
    }
    return;
}

void solve_floyd(int size)
{
    int tmp_new_dist;
    for(int k = 0; k < size; k++)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                tmp_new_dist = dist[i][k] + dist[k][j];
                if(tmp_new_dist < dist[i][j])
                {
                    dist[i][j] = tmp_new_dist;
                }
            }
        }
    }
    return;
}

void _debug_print_all_dist(int N)
{
    //debug
    cout << "\n---debug-print-dist---\n";
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }
    cout << "---end---\n";
    return;
}