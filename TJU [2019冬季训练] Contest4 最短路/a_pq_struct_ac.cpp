#include<iostream>
#include<vector>
#include<queue>



//typedef vector<Edge>::iterator Vei;
//typedef pair<int, int> Pii;

using namespace std;

#define Vei vector<Edge>::iterator

typedef struct EDGE{
    int to;
    int cost;
    EDGE(int _to, int _cost)
    {
        to = _to;
        cost = _cost;
    }
    friend bool operator < (const struct EDGE a, const struct EDGE b)
    {
        return a.cost > b.cost;
    }
}Edge;

void vec_clear(vector<Edge> v[], const int S);
void vec_std_in(vector<Edge> v[], const int _edge_num);
int solve_dij(vector<Edge> v[], const int S, int src, int dist);
int solve_dij_priority_queue(vector<Edge> e[], const int S, int src, int dest);


int main()
{
    int N, M;
    int src, dest;
    int ans;
    vector<Edge> edge[200];
    

    while(cin >> N >> M)
    {
        vec_clear(edge, N);
        vec_std_in(edge, M);
        cin >> src >> dest;
        ans = solve_dij_priority_queue(edge, N, src, dest);
        cout << ans << endl;
    }

    return 0;
}

void vec_clear(vector<Edge> v[], const int S)
{
    for(int i = 0; i < S; i++)
    {
        v[i].clear();
    }
    return;
}

void vec_std_in(vector<Edge> v[], const int _edge_num)
{
    int a, b, x;
    for(int i = 0; i < _edge_num; i++)
    {
        cin >> a >> b >> x;
        v[a].push_back(EDGE(b, x));
        v[b].push_back(EDGE(a, x));
    }
    return;
}

int solve_dij(vector<Edge> e[], const int S, int src, int dest)
//O(n^2)
{
    int ans;
    int const inf = 0x3f3f3f3f;
    int dist[S];//dist from src
    bool ifInSet[S];
    
    //-----init-----
    for(int i = 0; i < S; i++)
    {
        dist[i]= inf;
        ifInSet[i] = false;
    }

    /*
    for(vei it = e[src].begin(); it != e[src].end(); it++)
    {
        if((*it).cost < dist[(*it).to])
        //attention to this "if"
        {
            dist[(*it).to] = (*it).cost;
        }
    }
    ifInSet[src] = true;
    */
    dist[src] = 0;

    
    //-----init-end-----


    int present_smallest;
    int present_index;
    while(true)
    {
        present_smallest = inf - 1;
        present_index = -1;

        //try to find smallest a but not in the set
        for(int i = 0; i < S; i++)
        {
            if(dist[i] < present_smallest && !ifInSet[i])
            {
                present_smallest = dist[i];
                present_index = i;
            }
        }

        if(present_index >= 0)
        {
            //add in set
            ifInSet[present_index] = true;

            //song chi
            for(Vei it = e[present_index].begin(); it != e[present_index].end(); it++)
            {
                int tmp_new_dist = dist[present_index] + (*it).cost;
                int tmp_dest = (*it).to;

                //debug
                //cout << endl << "---debug-songchi:---" << endl;
                //cout << "tmp_new_dist " << tmp_new_dist << endl;
                //cout << "tmp_dest "<< tmp_dest << endl;
                //cout << "dist[tmp_dest] " << dist[tmp_dest] << endl;
                //cout << "---debug-songchi-end---" << endl;

                if(tmp_new_dist < dist[tmp_dest])
                {
                    dist[tmp_dest] = tmp_new_dist;
                }
            }
        }else
        {
           break;
        }
    }

    if(dist[dest] < inf)
    {
        ans = dist[dest];
    }else{
        ans = -1;
    }

    

    return ans;
}

int solve_dij_priority_queue(vector<Edge> e[], const int S, int src, int dest)
//O(n^2)
{
    int ans;
    int const inf = 0x3f3f3f3f;
    int dist[S];//dist from src
    bool ifInSet[S];


    priority_queue<Edge, vector<Edge>> pq;
    //first: cost
    //second: to
    
    //-----init-----
    for(int i = 0; i < S; i++)
    {
        dist[i]= inf;
        ifInSet[i] = false;
    }

    dist[src] = 0;
    pq.push(EDGE(src, 0));

    
    //-----init-end-----


    int present_index;
    int present_distance;
    while(!pq.empty())
    {
        present_distance = pq.top().cost;
        present_index = pq.top().to;
        pq.pop();

        //debug
        //cout << endl << "-----debug-pq-top-----" << endl;
        //cout << "dist " << present_distance << endl;
        //cout << "index " << present_index << endl;
        //cout << endl << "-----debug-pq-top-end----" << endl;

        if(dist[present_index] >= present_distance && !ifInSet[present_index])
        {
            //add in set
            ifInSet[present_index] = true;
        }else{
            continue;
        }
  
        //song chi
        for(Vei it = e[present_index].begin(); it != e[present_index].end(); it++)
        {
            int tmp_new_dist = dist[present_index] + (*it).cost;
            int tmp_dest = (*it).to;

            //debug
            //cout << endl << "---debug-songchi:---" << endl;
            //cout << "tmp_new_dist " << tmp_new_dist << endl;
            //cout << "tmp_dest "<< tmp_dest << endl;
            //cout << "dist[tmp_dest] " << dist[tmp_dest] << endl;
            //cout << "---debug-songchi-end---" << endl;

            if(tmp_new_dist < dist[tmp_dest])
            {
                dist[tmp_dest] = tmp_new_dist;
                pq.push(EDGE(tmp_dest, tmp_new_dist));
            }
        }

    }

    if(dist[dest] < inf)
    {
        ans = dist[dest];
    }else{
        ans = -1;
    }

    

    return ans;
}