#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 500125;

int globe_T;;
int globe_N;
int child_num[MAX_SIZE];
int main_child[MAX_SIZE];
int degree[MAX_SIZE];
bool ifVisited[MAX_SIZE];
vector<int> child[MAX_SIZE];

void cnt_child_and_degree(int i);
long long find_best_child(int index);
void upgrade(int i);
void add_one_edge();

/*
void debug_main_child()
{
    cout << "---debug-print-main-child-list:---" << endl;
    for(int i = 1; i <= globe_N; i++)
    {
        cout << i << " main child: " << main_child[i] << endl;
    }
    cout << "---debug-print-main-child-list-end---" << endl;
}
*/

/*
void debug_print_vertex(int i)
{
    cout << "vertex " << i << "\'s child: ";
    for(int j = 0; j < child[i].size(); j++)
    {
        cout << child[i][j] << ' ';
    }
    cout << endl;
}
*/

int main()
{
    int tmpIndex;
    long long ans;

    scanf("%d",&globe_T);; //test case num;

    for(int caseCount = 0; caseCount < globe_T; caseCount++)
    {
        scanf("%d",&globe_N);

        for(int i = 0; i <= globe_N; i++)
            vector<int>().swap(child[i]);
        
        for(int i = 0; i <= globe_N; i++)
        {
            child_num[i] = 0;
            degree[i] = 0;
            ifVisited[i] = false;
        }
        
        for(int i = 2; i <= globe_N; i++)
        {
            scanf("%d", &tmpIndex);
            child[tmpIndex].push_back(i);
        }

        //debug
        //cout << endl << "---debug-print-all-vertex:---" << endl;
        //for(int i = 1; i <= n; i++)
        //    debug_print_vertex(i);
        //cout << endl << "---debug-print-all-vertex-end---" << endl;

        cnt_child_and_degree(1);

        //debug
        //debug_main_child();

        //debug
        //cout << endl << "---debug-root:---" << endl;
        //cout << "child num " << child_num[1] << endl;
        //cout << "degree " << degree[1] << endl;

        //ans = 0;
        //for(int i = 1; i <= n; i++)
        //    ans += child_num[i] + 1;
        //debug
        //cout << "debug-ans-before-add-edge: " << ans << endl;

        //add_one_edge();
        long long add_edge_gain;
        add_edge_gain = find_best_child(1);

        ans = 0;
        for(int i = 1; i <= globe_N; i++)
        {
            ans += child_num[i] + 1;
        }
        ans += add_edge_gain;
        //debug
        //cout << "debug-ans: " << ans << endl;
        printf("%lld\n", ans);
    }

    return 0;
}

void cnt_child_and_degree(int i)
{
    //debug
    //cout << "debug-function-called-cnt_child_and_degree, arg = " << i << endl;


    main_child[i] = -1;
    child_num[i] = 0;
    degree[i] = 0;

    //debug
    //cout << "vector empty: " << child[i].empty() << endl;
    //cout << "vector size: " << child[i].size() << endl;

    if(child[i].empty() || i >= globe_N + 1 || ifVisited[i])
    { 
        return;
    }

    int tmpIndex;
    int tmpMaxDegree;
    for(vector<int>::iterator it = child[i].begin(); it != child[i].end(); it++)
    //for(int j = 0; j < child[i].size(); j++)
    {
        tmpIndex = *it;
        //tmpIndex = child[i][j];

        //debug
        //cout << "debug-function-cnt_child_and_degree-calling in " << i << ", arg = " << tmpIndex << endl;
        //exit(101);

        cnt_child_and_degree(tmpIndex);

        child_num[i] += child_num[tmpIndex] + 1;
        tmpMaxDegree = degree[tmpIndex] + 1;
        if(tmpMaxDegree > degree[i])
        {
            degree[i] = tmpMaxDegree;
            main_child[i] = tmpIndex;
        }
    }

    //debug
    //exit(101);
    ifVisited[i] = true;
    return;

}

void upgrade(int i)
{
    if(i >= globe_N + 1 || i <= 0)
    {
        return;
    }
    child_num[i] = globe_N - 1;

    if(main_child[i] >= 1)
    {
        upgrade(main_child[i]);
    }
    return;
}

void add_one_edge()
{
    upgrade(1);
    return;
}

long long find_best_child(int index)
{
    long long best_child_gain = 0;
    long long tmp_child_gain;
    for(vector<int>::iterator it = child[index].begin(); it != child[index].end(); it++)
    {
        tmp_child_gain = find_best_child(*it);
        if(tmp_child_gain > best_child_gain)
        {
            best_child_gain = tmp_child_gain;
        }
    }
    return best_child_gain + (globe_N - (child_num[index] + 1));
}