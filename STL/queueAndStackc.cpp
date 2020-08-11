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
void testMultiType();

void testPairWithPioryQueue();//TODO
void testMap();//TODO
void testAlgorithm();//TODO
template<typename T>void showStackStatus(stack<T> s);

int main()
{
    //testRandomNumber();
    //testQueue();
    //testStack();
    testMultiType();
    

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

    //func: empty, size
    printDebugStage(1);
    showQueueStatus<int>(q_int_demo1);

    //func: push
    printDebugStage(2);
    q_int_demo1.push(1);
    q_int_demo1.push(2);
    showQueueStatus<int>(q_int_demo1);

    //func: front, back
    printDebugStage(3);
    int a = q_int_demo1.front();//which is about to pop next time
    int b = q_int_demo1.back();
    cout << a << endl;
    cout << b << endl;
    showQueueStatus<int>(q_int_demo1);

    //func: pop
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
    //mt
    mt19937 mt(time(0));//include random and ctime
    auto mt_random_real = bind(uniform_real_distribution<double>(0, 1), mt);//include functional
    auto mt_random_int = bind(uniform_int_distribution<int>(0, 100000), mt);

    //normally fake random
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
    auto mt_random_int = bind(uniform_int_distribution<int>(0, 100000), mt);
    
    int a[10];
    int b[10];
    int c;

    cout << "-----stack int demo 1:-----" << endl;

    //init
    for(int i = 0; i < 10; i++)
    {
        a[i] = 100 * i;
        b[i] = mt_random_int();
    }

    printDebugStage(1);
    //func: empty size
    showStackStatus<int>(s_int_demo1);

    //func: push
    printDebugStage(2);
    for(int i = 0; i < 10; i++)
    {
        s_int_demo1.push(a[i]);
    }
    showStackStatus<int>(s_int_demo1);

    //func: top
    printDebugStage(3);
    c = s_int_demo1.top();
    cout << c << endl;
    showStackStatus<int>(s_int_demo1);
    c = s_int_demo1.top();//repeat, to show the func:top() will not pop stack
    cout << c << endl;
    showStackStatus<int>(s_int_demo1);

    //func: pop
    printDebugStage(4);
    s_int_demo1.pop();
    c = s_int_demo1.top();
    cout << c << endl;
    showStackStatus<int>(s_int_demo1);


    cout << "-----stack int demo 1 end-----" << endl;
    return;
}

template<typename T>void showStackStatus(stack<T> s)
{
    cout << "size: " << s.size() << endl;
    cout << "ifEmpty: " << s.empty() << endl;
    return;
}

void testMultiType()
{
    cout << "-----test multi-type:-----" << endl;

    mt19937 mt(time(0));
    auto mt_random_real = bind(uniform_real_distribution<double>(0, 1), mt);

    typedef struct MYSTRUCT{
        int id;
        char position;
        string name;
        double value;
    }MyStruct;

    MyStruct mys_demo1[10];
    stack<MyStruct> s_mys_demo1;

    //init
    for(int i = 0; i < 10; i++)
    {
        mys_demo1[i].id = i;
        mys_demo1[i].position = 'a' + i*2;
        mys_demo1[i].name = "";
        mys_demo1[i].value = mt_random_real();
    }

    printDebugStage(1);
    for(int i = 0; i < 10; i++)
    {
        s_mys_demo1.push(mys_demo1[i]);
    }
    showStackStatus<MyStruct>(s_mys_demo1);


    cout << "-----test multi-type end-----" << endl;
    return;
}