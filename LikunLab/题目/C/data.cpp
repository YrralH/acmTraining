#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 50000;
    cout<<n<<endl;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
    auto rd = bind(uniform_int_distribution<long long>(0, 5000000000000000000L), rng); 
    for (int i=0;i<n;i++)
    cout<<rd()<<endl;
    return 0;
}