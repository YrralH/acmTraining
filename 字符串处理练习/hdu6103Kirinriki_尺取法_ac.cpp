#include<iostream>
#include"string.h"

using namespace std;

int std_in_and_solve();
int get_ans(char s[], const int s_len, int m, int mid_index, bool type);
void init_lr(int& mid_index, int& left, int& right);
void compute1_lr_2(int& mid_index, int& left, int& right, int& left2, int& right2);
void compute2_lr_2(int& mid_index, int& left, int& right, int& left2, int& right2);
bool if_legal(int length, int& left, int& right, int& left2, int& right2);

int main()
{
    int T;
    int ans;
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        ans = std_in_and_solve();
        printf("%d\n", ans);
    }
}

int std_in_and_solve()
{
    int m;
    char s[5000];
    scanf("%d", &m);
    scanf("%s", &s);
    int s_len = strlen(s);
    int max;

    int tmp_max;

    max = 0;

    for(int i = 0; i < s_len; i++)
    {
        tmp_max = get_ans(s, s_len, m, i, true);//true means type 1

        //debug
        //cout << "mini case " << i << " " << true << " " <<  tmp_max << endl;

        if(tmp_max > max)
            max = tmp_max;

        tmp_max = get_ans(s, s_len, m, i, false);//false means type 2

        //debug
        //cout << "mini case " << i << " " << false << " " <<  tmp_max << endl;

        if(tmp_max > max)
            max = tmp_max;
    }


    return max;
}

int get_ans(char s[], const int s_len, int m, int mid_index, bool type)
//chi qufa
{
    int left, right, left2, right2;
    bool legal;
    int dist;
    int max;
    int tmp_max;


    init_lr(mid_index, left, right);
    dist = 0;
    max = 0;

    while(1)
    {
        if(dist <= m)
        {
            tmp_max = right - left + 1;
            if(tmp_max > max)
                max = tmp_max;

            right++;

            if(type)
                compute1_lr_2(mid_index, left, right, left2, right2);
            else
                compute2_lr_2(mid_index, left, right, left2, right2);
            
            legal = if_legal(s_len, left, right, left2, right2);
            if(!legal)
            {
                break;
            }
            dist += abs(s[right] - s[right2]);
        }else
        {
            dist -= abs(s[left] - s[left2]);
            left++;

            if(type)
                compute1_lr_2(mid_index, left, right, left2, right2);
            else
                compute2_lr_2(mid_index, left, right, left2, right2);

            legal = if_legal(s_len, left, right, left2, right2);
            if(!legal)
            {
                break;
            }
        }
        
    }
    return max;
}

void init_lr(int& mid_index, int& left, int& right)
{
    left = mid_index + 1;
    right = left - 1;
    return;
}

void compute1_lr_2(int& mid_index, int& left, int& right, int& left2, int& right2)
{
    left2 = mid_index*2 - left + 1;
    right2 = mid_index*2 - right + 1;
    return;
}

void compute2_lr_2(int& mid_index, int& left, int& right, int& left2, int& right2)
{
    left2 = mid_index*2 - left;
    right2 = mid_index*2 - right;
    return;
}

bool if_legal(int length, int& left, int& right, int& left2, int& right2)
{
    bool flag;
    flag = (left >= 0 && left < length) &&
        (right >= 0 && right < length) &&
        (left2 >= 0 && left2 < length) &&
        (right2 >= 0 && right2 < length);
    return flag;
}
