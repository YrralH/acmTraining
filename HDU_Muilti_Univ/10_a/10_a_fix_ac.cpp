#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 500125;

int globe_T;;
int globe_N;
int child_num[MAX_SIZE];
vector<int> child[MAX_SIZE];

void cnt_child_and_degree(int i);
long long find_best_child(int index);

int main()
{
    int tmpIndex;
    long long ans;
    long long add_edge_gain;

    scanf("%d",&globe_T);; //test case num;

    for(int caseCount = 0; caseCount < globe_T; caseCount++)
    {
        scanf("%d",&globe_N);

        for(int i = 0; i <= globe_N; i++)
        {
            vector<int>().swap(child[i]);
            child[i].clear();
        }
        
        for(int i = 2; i <= globe_N; i++)
        {
            scanf("%d", &tmpIndex);
            child[tmpIndex].push_back(i);
        }

        cnt_child_and_degree(1);

        add_edge_gain = find_best_child(1);

        ans = 0;
        for(int i = 1; i <= globe_N; i++)
        {
            ans += child_num[i] + 1;
        }
        ans += add_edge_gain;
        printf("%lld\n", ans);
    }

    return 0;
}

void cnt_child_and_degree(int i)
{
    child_num[i] = 0;

    if(child[i].empty() || i >= globe_N + 1)
    { 
        return;
    }

    int tmpIndex;
    for(vector<int>::iterator it = child[i].begin(); it != child[i].end(); it++)
    {
        tmpIndex = *it;

        cnt_child_and_degree(tmpIndex);

        child_num[i] += child_num[tmpIndex] + 1;
    }
    return;

}

long long find_best_child(int index)
//return gain for best child
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