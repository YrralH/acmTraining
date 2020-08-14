#include<iostream>

using namespace std;

const int SIZE = 100005;

int n;
int m[SIZE];
int tmp1[SIZE];
int all[SIZE];

int main()
{
    long long ans;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    tmp1[0] = 0;
    for(int i = 1; i < n; i++)
    {
        tmp1[i] = max(m[i], tmp1[i-1]);
    }

    for(int i = n - 2; i >= 0; i--)
    {
        tmp1[i] = max(tmp1[i], tmp1[i+1] - 1);
    }

    //debug
    //cout << "-----debug-tmp1:-----" << endl;
    //for(int i = 0; i < n; i++)
    //    cout << tmp1[i] << ' ';
    //cout << endl;

    ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += tmp1[i] - m[i];
    }
    cout << ans << endl;

    return 0;
}
