#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 500125;

int globe_T;;
int globe_N;
int child_num[MAX_SIZE];

long long process_one_case();
void cnt_child_and_degree(int i, vector<int> child[]);
long long find_best_child(int index, vector<int> child[]);

int main()
{
    long long ans;

    scanf("%d",&globe_T);; //test case num;

    for(int caseCount = 0; caseCount < globe_T; caseCount++)
    {
        ans = process_one_case();

        printf("%lld\n", ans);
    }

    return 0;
}

long long process_one_case()
{
    long long ans;
    long long add_edge_gain;
    int tmpIndex;

    scanf("%d",&globe_N);

    vector<int>* child = new vector<int>[globe_N + 1];
    
    for(int i = 2; i <= globe_N; i++)
    {
        scanf("%d", &tmpIndex);
        child[tmpIndex].push_back(i);
    }

    cnt_child_and_degree(1, child);

    add_edge_gain = find_best_child(1, child);

    ans = 0;
    for(int i = 1; i <= globe_N; i++)
    {
        ans += child_num[i] + 1;
    }
    ans += add_edge_gain;

    delete[] child;

    return ans;
}

void cnt_child_and_degree(int i, vector<int> _child[])
{
    child_num[i] = 0;

    if(_child[i].empty() || i >= globe_N + 1)
    { 
        return;
    }

    int tmpIndex;
    for(vector<int>::iterator it = _child[i].begin(); it != _child[i].end(); it++)
    {
        tmpIndex = *it;

        cnt_child_and_degree(tmpIndex, _child);

        child_num[i] += child_num[tmpIndex] + 1;
    }
    return;

}

long long find_best_child(int index, vector<int> _child[])
//return gain for best child
{
    long long best_child_gain = 0;
    long long tmp_child_gain;
    for(vector<int>::iterator it = _child[index].begin(); it != _child[index].end(); it++)
    {
        tmp_child_gain = find_best_child(*it, _child);
        if(tmp_child_gain > best_child_gain)
        {
            best_child_gain = tmp_child_gain;
        }
    }
    return best_child_gain + (globe_N - (child_num[index] + 1));
}