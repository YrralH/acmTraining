#include<iostream>

using namespace std;

int main()
{
    int recovery_num;
    int death_num;  
    double rate;

    recovery_num = 2900188;
    death_num = 172606;

    rate = static_cast<double>(death_num) / (death_num + recovery_num);

    cout << "rate: " << rate << endl;
    return 0;
}
