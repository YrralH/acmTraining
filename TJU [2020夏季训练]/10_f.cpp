#include<iostream>
#include<stack>

using namespace std;

typedef struct NODE{
    int index;
    int value;
}Node;

int n;
int m[100005];
int all[100005];
int dif[100005];

//Node nList[100005];
//int nList_len;

Node makeNode(int i, int v)
{
    Node tmp;
    tmp.index = i;
    tmp.value = v;
    return tmp;
}

int main()
{
    int tmpMin;
    long long ans;
    stack<Node> s;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        dif[i] = i - m[i];
    }

    //nList_len = 0;
    tmpMin = 0x3f3f3f3f;
    for(int i = n - 1; i >= 0; i--)
    {
        if(dif[i] < tmpMin)
        {
            //nList[nList_len].index = i;
            //nList[nList_len].value = i - dif[i];
            //nList_len++;
            s.push(makeNode(i, i - dif[i]));

            tmpMin = dif[i];
        }
    }

    //debug
    //cout << endl << "-----debug-nList:------\n" <<  "nList_len: " << nList_len << endl;
    //for(int i = 0; i < nList_len; i++)
    //   cout << "nList[" << i << "]\'s index and value: " << nList[i].index << " " << nList[i].value << endl;

    int tmpIndex;
    int startIndex;
    int endIndex;
    Node n1;
    Node n1_pre;

    //nList[nList_len].index = 0;
    //nList[nList_len].value = 0;
    //nList_len++;
    s.push(makeNode(0, 0));
    all[0] = 0;

    n1_pre = s.top();
    s.pop();

    while(!s.empty())
    {
        n1 = s.top();
        s.pop();

        startIndex = n1_pre.index;
        endIndex = n1.index;
        for(int j = startIndex; j <= endIndex; j++)
        {
            all[j] = n1_pre.value;
        }

        if(n1.value > n1_pre.value)
        {
            tmpIndex = n1.index;
            for(int j = n1.value; j >= n1_pre.value; j--)
            {
                all[tmpIndex] = j;
                tmpIndex--;
            }
        }


        n1_pre = n1;
    } 

/*
    for(int i = nList_len - 2; i >= 0; i--)
    {
        startIndex = nList[i+1].index;
        endIndex = nList[i].index;
        for(int j = startIndex; j <= endIndex; j++)
        {
            all[j] = nList[i+1].value;
        }

        if(nList[i].value > nList[i+1].value)
        {
            tmpIndex = nList[i].index;
            for(int j = nList[i].value; j >= nList[i+1].value; j--)
            {
                all[tmpIndex] = j;
                tmpIndex--;
            }
        }
    }*/

    //debug
    cout << "\n-----debug-print-array-d:-----\n";
    for(int i = 0; i < n; i++)
        cout << all[i] << ' ';
    cout << endl;

    ans = 0;
    for(int i = 0; i < n; i++)
        ans += all[i] - m[i];

    cout << ans << endl;

    return 0;
}