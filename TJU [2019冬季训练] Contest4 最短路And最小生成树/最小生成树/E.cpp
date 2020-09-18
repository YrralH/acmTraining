#include<iostream>
#include<algorithm>

using namespace std;

typedef struct EDGE{
    int a;
    int b;
    int cost;

    EDGE()
    {
        a = 0;
        b = 0;
        cost = 0;
    }

    EDGE(int _a, int _b, int _cost)
    {
        a = _a;
        b = _b;
        cost = _cost;
    }

    friend bool operator < (const struct EDGE e1, const struct EDGE e2)
    {
        return e1.cost < e2.cost;
    }
}Edge;

Edge road[105*105];
int road_num;

//int dist[105][105];
//dist[a][b] is the distance from a to b
//index starts at 1

int father[105];

long long process_a_case();
int find_ancient(int index);
void set_father_along_gen(int index, int father_index);
void connect(int a, int b);

int main()
{
    long long ans;

    ans = process_a_case();
    cout << ans << endl;
    
    return 0;
}

long long process_a_case()
{
    long long _ans;
    int N;//number of villages
    int Q;//number of road already built

    int a, b;//tmp
    int tmp_cost_input;

    //-----input-and-pre-process-----
    //input the number of villages
    cin >> N;
    //input the distance
    road_num = 0;
    for(int i = 1; i < N + 1; i++)
    {
        for(int j = 1; j < N + 1; j++)
        {
            cin >> tmp_cost_input;

            //take the advantage of the symmetry of the path
            if(i > j)
            {
                road[road_num] = EDGE(i, j, tmp_cost_input);
                road_num++;
            }
        }
    }
    //input the already built road number
    cin >> Q;

    //clear tree structure i.e. father
    for(int i = 1; i < N + 1; i++)
    {
        father[i] = i;
    }

    //input the built road
    for(int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        connect(a, b);
    }
    //-----input-and-pre-process-end----

    //debug-print-all-road
    //cout << "\nprint all road\n";
    //for(int i = 0; i < road_num; i++)
    //    cout << road[i].a << ' ' << road[i].b << ' ' <<  road[i].cost << "\n";

    sort(road, road + road_num);

    //debug-print-all-road
    //cout << "\nprint all road\n";
    //for(int i = 0; i < road_num; i++)
    //    cout << road[i].a << ' ' << road[i].b << ' ' <<  road[i].cost << "\n";

    _ans = 0;
    for(int i = 0; i < road_num; i++)
    {
        if(father[road[i].a] == father[road[i].b])
        {
            continue;
        }

        if(find_ancient(road[i].a) != find_ancient(road[i].b))
        {
            //debug-print-road
            //cout << "\nprint road\n";
            //cout << "road: " <<  road[i].a << ' ' << road[i].b << ' ' <<  road[i].cost << "\n";

            //debug
            //cout << "each ancient: " << find_ancient(road[i].a) << ' ' << find_ancient(road[i].b) << endl;

            _ans += road[i].cost;
            set_father_along_gen(road[i].a, road[i].b);

            //debug
            //cout << "each ancient: " << find_ancient(road[i].a) << ' ' << find_ancient(road[i].b) << endl;
            //debug
            //cout << "each connect end\n";
        }
    }
    

    return _ans;
}

int find_ancient(int index)
{
    int tmp_index;
    tmp_index = index;

    while(tmp_index != father[tmp_index])
    {
        tmp_index = father[tmp_index];
    }
    return tmp_index;
}

void set_father_along_gen(int index, int father_index)
{
    int ancient_index = find_ancient(father_index);
    int present_ancient_index = find_ancient(index);

    father[present_ancient_index] = father_index;

    int tmp_index = index;
    int tmp_index_delay;
    while(tmp_index != father[tmp_index])
    {
        tmp_index_delay = tmp_index;
        tmp_index = father[tmp_index];
        father[tmp_index_delay] = ancient_index;
    }
}

void connect(int a, int b)
{
    if(father[a] == father[b])
    {
        return;
    }else
    {
        set_father_along_gen(a, b);
        return;
    }
}