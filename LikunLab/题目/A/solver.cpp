#include <bits/stdc++.h>
using namespace std;
char a[1010];
int main()
{   
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",a);
        int now = 0;
        while (a[now]!='\0')
        {
            if (a[now] >= 'a') a[now] = a[now] - 'a' + 'A';
            if (now > 0 && a[now]=='I' && a[now-1]=='H')
            {
                a[now-1] = 'L';
                a[now] = 'O';
            }
            now++;
        }

        now = 0;
        while (a[now]!='\0')
        {
            if (a[now]!='X')
            {
                putchar('#');
                putchar(a[now]);
            } 
            now++;
        }
        putchar('\n');
    }
    return 0;
}