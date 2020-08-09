#include<bits/stdc++.h>
using namespace std;
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
    auto rd = bind(uniform_int_distribution<int>(-1000000000, 1000000000), rng);
    int n = 100000;
    cout<<n<<endl;

    cout<<"1 1 2 2 3 3 4 4"<<endl;
    cout<<"1 1 2 2 2 2 3 3"<<endl;
    cout<<"1 1 2 2 0 1 1 0"<<endl;
    cout<<"0 0 0 0 0 0 0 0"<<endl;
    cout<<"0 0 -10 -10 0 0 -2 3"<<endl;
    for (int i=5;i<n;i++)
    {
        cout<<rd()<<' '<<rd()<<' '<<rd()<<' '<<rd()<<' '<<rd()<<' '<<rd()<<' '<<rd()<<' '<<rd()<<endl;
    }
    return 0;
}