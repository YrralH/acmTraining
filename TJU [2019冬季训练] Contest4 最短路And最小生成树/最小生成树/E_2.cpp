#include<iostream>
#include<algorithm>
#include<stack>

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


int father[105];

void one_case_std_in();
int process_a_case();
int find_ancient(int index);
void set_father_along_gen(int index, int father_index);

int main()
{
    long long ans;

    ans = process_a_case();
    printf("%d\n", ans);
    
    return 0;
}

void one_case_std_in()
{
    int N;//number of villages
    int Q;//number of road already built

    int a, b;//tmp
    int tmp_cost_input;

    //-----input-and-pre-process-----
    //input the number of villages
    scanf("%d", &N);
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
    scanf("%d", &Q);

    //clear tree structure i.e. father
    father[0] = 0;
    for(int i = 1; i < N + 1; i++)
    {
        father[i] = i;
    }

    //input the built road
    for(int i = 0; i < Q; i++)
    {
        scanf("%d%d", &a, &b);
        set_father_along_gen(a, b);
    }
    //-----input-and-pre-process-end----
    return;
}

int process_a_case()
{
    int _ans;

    one_case_std_in();//implicit return value: road_num

    sort(road, road + road_num);

    _ans = 0;
    for(int i = 0; i < road_num; i++)
    {
        if(father[road[i].a] == father[road[i].b])
        {
            continue;
        }

        if(find_ancient(road[i].a) != find_ancient(road[i].b))
        {
            _ans += road[i].cost;
            set_father_along_gen(road[i].a, road[i].b);
        }
    }

    return _ans;
}

int find_ancient(int index)
{
    int tmp_index;
    int ancient_index;
    stack<int> s;

    tmp_index = index;
    while(tmp_index != father[tmp_index])
    {
        s.push(tmp_index);
        tmp_index = father[tmp_index];
    }
    ancient_index = tmp_index;

    while(!s.empty())
    {
        tmp_index = s.top();
        s.pop();
        father[tmp_index] = ancient_index;
    }

    return ancient_index;

    /*
    if(index == father[index])
    {
        return index;
    }else{
        father[index] = find_ancient(father[index]);
        return father[index];
    }
    */
}

void set_father_along_gen(int index, int father_index)
{
    int ancient_index = find_ancient(father_index);
    int present_ancient_index = find_ancient(index);

    father[present_ancient_index] = ancient_index;
    return;
}
