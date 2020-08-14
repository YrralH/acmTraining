#include<iostream>

using namespace std;

typedef struct NODE{
    int index;
    int value;
}Node;

const int SIZE = 100005;

int n;
int m[SIZE];
int all[SIZE];
int dif[SIZE];

Node nList[SIZE];
int nList_len;


int main()
{
    int tmpMin;
    long long ans;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        dif[i] = i - m[i];
    }

    nList_len = 0;
    tmpMin = 2*SIZE;
    for(int i = n - 1; i >= 0; i--)
    {
        if(dif[i] < tmpMin)
        {
            nList[nList_len].index = i;
            nList[nList_len].value = i - dif[i];
            nList_len++;

            tmpMin = dif[i];
        }
    }

    //debug
    //cout << endl << "-----debug-nList:------\n" <<  "nList_len: " << nList_len << endl;
    //for(int i = 0; i < nList_len; i++)
    //  cout << "nList[" << i << "]\'s index and value: " << nList[i].index << " " << nList[i].value << endl;

    int tmpIndex;
    int startIndex;
    int endIndex;
    Node n1;
    Node n1_pre;

    nList[nList_len].index = 0;
    nList[nList_len].value = 0;
    nList_len++;
    all[0] = 0;

    for(int i = nList_len - 2; i >= 0; i--)
    {
        //debug
        //cout << "debug: i = " << i << endl;
        startIndex = nList[i+1].index;
        endIndex = nList[i].index;
        for(int j = startIndex + 1; j <= endIndex; j++)
        {
            all[j] = all[startIndex];
        }

        if(nList[i].value > all[startIndex])
        {
            tmpIndex = nList[i].index;
            for(int j = nList[i].value; j >= all[startIndex]; j--)
            {
                all[tmpIndex] = j;
                tmpIndex--;
            }
        }
    }

    //debug
    //cout << "\n-----debug-print-array-d:-----\n";
    //for(int i = 0; i < n; i++)
    //    cout << all[i] << ' ';
    //cout << endl;

    ans = 0;
    for(int i = 0; i < n; i++)
        ans += static_cast<long long>(all[i] - m[i]);

    cout << ans << endl;

    return 0;
}