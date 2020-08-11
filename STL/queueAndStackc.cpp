//#pragma GCC diagnostic error "-std=c++11"
#include<iostream>
#include<queue>
#include<stack>

#include<random>
#include<ctime>
#include<functional>

using namespace std;

void printDebugStage(int i);
template<typename T>void showQueueStatus(queue<T> q);
void testQueue();
void testStack(); 
void testRandomNumber();

int main()
{
    testRandomNumber();
    testQueue();
    testStack();
    

    return 0;
}

void printDebugStage(int i)
{
    cout << "------debug id:" << i << "------" << endl;
}

void testQueue()
{
    queue<int> q_int_demo1;

    cout << "-----queue int demo 1:-----" << endl;
    
    printDebugStage(1);
    showQueueStatus<int>(q_int_demo1);

    printDebugStage(2);
    q_int_demo1.push(1);
    showQueueStatus<int>(q_int_demo1);

    printDebugStage(3);
    int a = q_int_demo1.front();
    int b = q_int_demo1.back();
    cout << a << endl;
    cout << b << endl;
    showQueueStatus<int>(q_int_demo1);

    printDebugStage(4);
    q_int_demo1.pop();
    showQueueStatus<int>(q_int_demo1);

    cout << "-----queue int demo 1 end-----" << endl;

    return;
}

template<typename T>void showQueueStatus(queue<T> q)
{
    cout << "size: " << q.size() << endl;
    cout << "ifEmpty: " << q.empty() << endl;
    return;
}

void testRandomNumber()
{
    mt19937 mt(time(0));//include random and ctime
    auto mt_random_real = bind(uniform_real_distribution<double>(0, 1), mt);//include functional
    auto mt_random_int = bind(uniform_int_distribution<int>(0, 100000), mt);

    srand(time(0));
    double fake_random_real = rand() / static_cast<double>(RAND_MAX);
    int fake_random_int = rand() % 200 + 100;

    cout << "-----random number test-----" << endl;
    cout << mt_random_int() << endl;
    cout << mt_random_real() << endl;
    cout << fake_random_real << endl;
    cout << fake_random_int << endl;
    cout << "-----random number test end-----" << endl;
    return;
}

void testStack()
{
    stack<int> s_int_demo1;

    mt19937 mt(time(0));
    auto mt_random_real = bind(uniform_real_distribution<double>(0, 1), mt);
    auto mt_random_int = bind(uniform_int_distribution<int>(0, 100000), mt);
    
    int a[10];
    int b[10];

    cout << "-----stack int demo 1:-----" << endl;

    for(int i = 0; i < 10; i++)
    {
        a[i] = 100 * i;

    }


    cout << "-----stack int demo 1 end-----" << endl;
    return;
}
