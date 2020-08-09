#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len = 1000, N = 10000;
    srand(time(0));
    printf("%d\n",N);
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<len;j++)
        {
            bool isUpper = rand() % 2;
            int rnd = rand() % 26;
            putchar(rnd + (isUpper?'A':'a'));
        }
        putchar('\n');
    }
    return 0;
}