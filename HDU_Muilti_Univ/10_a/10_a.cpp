#include<iostream>
#include<vector>

using namespace std;

int T;
int n;
int child_num[500010];
int main_child[500010];
int degree[500010];
vector<int>* child = new vector<int>[500010];

void cnt_child_and_degree(int i, const vector<int> _child[])
{
    int tmpIndex;
    int tmpMaxDegree;
    main_child[i] = -1;
    child_num[i] = 0;
    degree[i] = 0;

    if(_child[i].empty() || i > n + 1)
    { 
        return;
    }
    
    //for(vector<int>::iterator it = child[i].begin(); it < child[i].end(); it++)
    for(int j = 0; j < _child[i].size(); j++)
    {
        //int tmpIndexi = *it;
        int tmpIndex = _child[i][j];

        cnt_child_and_degree(tmpIndex, _child);

        child_num[i] += child_num[tmpIndex] + 1;
        tmpMaxDegree = degree[tmpIndex] + 1;
        if(tmpMaxDegree > degree[i])
        {
            degree[i] = tmpMaxDegree;
            main_child[i] = tmpIndex;
        }
    }

    return;

}

void upgrade(int i)
{
    child_num[i] = n - 1;
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


long long process_one_case()
{
    int tmpIndex;
    long long ans;
    for(int i = 0; i <= n+5; i++)
        vector<int>().swap(child[i]);
        
    for(int i = 2; i <= n; i++)
    {
        scanf("%d",&tmpIndex);
        child[tmpIndex].push_back(i);
    }

    cnt_child_and_degree(1, child);

    add_one_edge();

    ans = 0;
    for(int i = 1; i <= n; i++)
        ans += child_num[i] + 1;

    return ans;
}

int main()
{
    long long ans;

    scanf("%d",&T); //test case num;

    for(int caseCount = 0; caseCount < T; caseCount++)
    {
        scanf("%d",&n);

        ans = process_one_case();

        cout << ans << endl;
    }

    return 0;
}