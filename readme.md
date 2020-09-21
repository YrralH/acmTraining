<!-- TOC -->

- [1. 基础搜索](#1-基础搜索)
	- [1.1. 递归写DFS](#11-递归写dfs)
	- [1.2. 队列与BFS](#12-队列与bfs)
- [2. 基础数据结构/基本操作](#2-基础数据结构基本操作)
	- [2.1. 输入输出](#21-输入输出)
		- [2.1.1. 输入判断文件末尾](#211-输入判断文件末尾)
		- [2.1.2. 格式化输出](#212-格式化输出)
			- [2.1.2.1. cout](#2121-cout)
			- [2.1.2.2. printf](#2122-printf)
	- [2.2. 常用STL库](#22-常用stl库)
		- [2.2.1. 偷懒](#221-偷懒)
		- [2.2.2. queue](#222-queue)
		- [2.2.3. stack](#223-stack)
		- [2.2.4. priority queue](#224-priority-queue)
		- [2.2.5. pair and piority queue](#225-pair-and-piority-queue)
		- [2.2.6. pair and map](#226-pair-and-map)
		- [2.2.7. 迭代器](#227-迭代器)
		- [2.2.8. set](#228-set)
		- [2.2.9. algorithm](#229-algorithm)
	- [2.3. 随机数Random Number](#23-随机数random-number)
- [3. 数论相关](#3-数论相关)
	- [3.1. 最大公约数GCD](#31-最大公约数gcd)
- [4. 最短路/最小生成树](#4-最短路最小生成树)
	- [4.1. Dijkstra](#41-dijkstra)
	- [4.2. Floyd](#42-floyd)
- [5. 动态规划(Dynamic Programming)](#5-动态规划dynamic-programming)
- [6. 字符串处理](#6-字符串处理)
	- [6.1. 基本](#61-基本)
		- [6.1.1. 尺取法](#611-尺取法)
		- [6.1.2. char[]函数和string函数](#612-char函数和string函数)
	- [6.2. 进阶](#62-进阶)
		- [6.2.1. KMP](#621-kmp)
		- [Manacher](#manacher)
- [7. 其他TODO](#7-其他todo)
- [8. 心态崩了预案](#8-心态崩了预案)
	- [8.1. 错误记录](#81-错误记录)

<!-- /TOC -->

# 1. 基础搜索  
## 1.1. 递归写DFS  

如
```c++
void DFS(int depth, int remaining_chess, const bool chessboard[][8], const int boardsize, bool ifOccupied[])
{

	//find a solution
	if(depth == boardsize)
	{	
		globe_ans++;
		return;
	}

	//possible way1: not put this time
	if(depth + remaining_chess < boardsize)
	{
		DFS(depth + 1, remaining_chess, chessboard, boardsize, ifOccupied);
	}

	//possible way2: try to put a chess piece this time
	if(remaining_chess <= 0)
	//no remaining chess
	{
		return;
	} else
	{
		for(int i = 0; i < boardsize; i++)
		{
			if(!ifOccupied[i] && chessboard[depth][i])
			{
				//to put
				ifOccupied[i] = true;
				DFS(depth + 1, remaining_chess - 1, chessboard, boardsize, ifOccupied);
				ifOccupied[i] = false;
			}
		}
		//no more put strategy
		return;
	}

}
```
> 其中为了效率，以下这几个直接放到全局变量会好挺多。 
> ```c++
> const bool chessboard[][8], const int boardsize, bool ifOccupied[]
> ```
 
如果不递归写起来比较麻烦，比如用栈来储存状态。


## 1.2. 队列与BFS
没什么好说的，也许STL的队列比较方便。

# 2. 基础数据结构/基本操作

## 2.1. 输入输出
### 2.1.1. 输入判断文件末尾
scanf和cin两种风格
```c++
while(~scanf("%d", &n))
```
```c++
while(cin >> n)
```

~是按位取反  
scanf的返回值是输入值的个数  
如果没有输入值就是返回-1  
-1按位取反结果是0  
### 2.1.2. 格式化输出
#### 2.1.2.1. cout
TODO 主要是保留小数点，补零什么的
#### 2.1.2.2. printf
|符号|功能/描述|  
| -- | ------- |
| %.8f | 保留小数点后8位 |
| %lf | double |  
| %lld | long long |
| %c | char |
| %s | char[] |
| %d %o %x | 十进制 八进制 十六进制 | 
| %-5.8 | 符号表示左对齐，小数点前保留5位，小数点后保留8位 | 
```c++  
itoa(int value, char * string, int radix);
```

## 2.2. 常用STL库
### 2.2.1. 偷懒
这样（需要-std=c++11），不然只能用``` #define ``` 
（代码太长较危险）  

> ```c++
> typedef vector<Edge>::iterator Vei;
> typedef pair<int, int> Pii;
> ```


### 2.2.2. queue
> 注意这些数据结构都需要先判断是否空再取元素，否则不可预料。
> first in first out  
```c++
//head
#include<queue>

//declare
queue<int> q_int_demo1;

//func
if(q_int_demo1.empty()){}
int s = q_int_demo1.size();

q_int_demo1.push(1);
int a = q_int_demo1.front();
int b = q_int_demo1.back();
q_int_demo1.pop();
```
### 2.2.3. stack
> first last out
```c++
//head
#include<stack>

//declare
stack<int> s_int_demo1;

//func
if(s_int_demo1.empty()){}
int s = s_int_demo1.size();

s_int_demo1.push(1);
int a = s_int_demo1.top();
q_int_demo1.pop();
```
### 2.2.4. priority queue
默认顶是最大的
>```c++
>priority_queue<Pii, vector<Pii>> pq;
>```

若需要顶是最小的
>```c++
>priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
>```

若需要结构体，则重载运算符"<"
>```c++
>typedef struct EDGE{
>    int to;
>    int cost;
>    EDGE(int _to, int _cost)
>    {
>        to = _to;
>        cost = _cost;
>    }
>    friend bool operator < (const struct EDGE a, const struct EDGE b)
>    {
>        return a.cost > b.cost;
>    }
>}Edge;

再使用默认的声明，本来是顶"最小"，重载的时候又反过来了，所以结果就是顶是cost最小的
> ```c++
> priority_queue<Edge, vector<Edge>> pq;
> ```






### 2.2.5. pair and piority queue
TODO 自定义比较函数    
> 使用：push(a) pop() top() empty() size()
### 2.2.6. pair and map
TODO：map and hashmap

### 2.2.7. 迭代器

### 2.2.8. set

### 2.2.9. algorithm
TODO：sort 全排列

## 2.3. 随机数Random Number
两种
> 1-32xxx的凑合随机数
>``` c++
>#include<ctime>
>#include<cstdlib>
>    srand(time(0));
>    double fake_random_real = rand() / static_cast<double>(RAND_MAX);
>    int fake_random_int = rand() % 200 + 100;
>```
> mt19937
> ```c++
> #include<random>
> #include<ctime>
> #include<functional>
>    mt19937 mt(time(0));
>    auto mt_random_real = bind(uniform_real_distribution<double>(0, 1), mt);
>    auto mt_random_int = bind(uniform_int_distribution<int>(0, 100000), mt);
> ```  

# 3. 数论相关
## 3.1. 最大公约数GCD
可用库
> ```c++
> #include<algorithm>
> int gcd = __gcd<int>(N, M);
> //显然最小公倍数
> int lcm = N * M / gcd;
> ```
若不用库当然辗转相除即可。  
阴间 ↓ 
> ```c++
> int gcd1(int a,int b){
> 	while(b ^= a ^= b ^= a %= b);
> 	return a;
> }
> ```
阳间 ↓ 
> ```c++
> int gcd2(int a, int b){
> 	return b == 0 ? a : gcd2(b, a%b);
> }
>```

# 4. 最短路/最小生成树
注意：输入时，对同一条路可能有多个输入，没注意时可能后面的覆盖前面的。
## 4.1. Dijkstra
思路就是每次都把```集合外且Dist最小者```(Dist即到src的距离加进来，并```松弛```。  
  
直接写就是```o(n^2)```  
> 注意初始化
> 如果这样初始化，注意这个if
> ```c++
>     for(vei it = e[src].begin(); it != e[src].end(); it++)
>    {
>        if((*it).cost < dist[(*it).to])
>        //attention to this "if"
>        {
>            dist[(*it).to] = (*it).cost;
>        }
>    }
>    ifInSet[src] = true;
>    dist[src] = 0;
> ```
> 当然还不如就这样初始化  
> ```c++
> dist[src] = 0;
> ```
> 因为这样第一个加入的点就是src点，就和后续是一样的。所以是理解不透（想思路的时候想这样初始化）妨碍效率高效。  
> 
不过可能还需习得n(nlogn)版本的  
> 当然是堆优化，最简单就是用```std::```优先队列    
> 重载结构体的小于符号，这样优先队列的堆顶是```cost最小者```  
> ```c++
> typedef struct EDGE{
>    int to;
>    int cost;
>    EDGE(int _to, int _cost)
>    {
>        to = _to;
>        cost = _cost;
>    }
>    friend bool operator < (const struct EDGE a, const struct EDGE b)
>    {
>        return a.cost > b.cost;
>    }
>}Edge;  
> ```
> 声明，第二个参数是底层容器
> ```c++ 
> priority_queue<Edge, vector<Edge>> pq;
> ```
> 初始化+ 
>```c++ 
>while(!pq.empty())
>{/*加入*/{} /*松弛*/{}}
>```


另外还有FQ的邪术  
> 假堆，详见: 最短路 a_fake_heap.cpp


## 4.2. Floyd
简单循环一下，有时能直接过，当然是```O(n^3)```
> ```c++
>int dist[200][200];
>void solve_floyd(int size)
>{
>    int tmp_new_dist;
>    for(int k = 0; k < size; k++)
>    {
>        for(int i = 0; i < size; i++)
>        {
>            for(int j = 0; j < size; j++)
>            {
>                tmp_new_dist = dist[i][k] + dist[k][j];
>                if(tmp_new_dist < dist[i][j])
>                {
>                    dist[i][j] = tmp_new_dist;
>                }
>            }
>        }
>    }
>    return;
>}
> ```

# 5. 动态规划(Dynamic Programming)
TODO 待刷TJU的题目

# 6. 字符串处理
## 6.1. 基本
### 6.1.1. 尺取法
任务example：给定一个正数序列，使得其和大于或等于S，求最短的子序列长度。
> ```c++
>     while(1)
>    {
>        if(constraint_dist <= m)
>        {
>            //尝试更新答案
>            {/*code*/}
>
>            right++;
>
>            //判断是是否合法，不合法break
>            {/*code*/}
>
>            //更新constraint（加入right）
>            constraint_dist += abs(s[right] - s[right2]);
>        }else
>        {
>            //更新constraint（去掉left）
>            constraint_dist -= abs(s[left] - s[left2]);
>
>           left++;
>
>            //判断是是否合法，不合法break
>            {/*code*/}
>        }
>        
>    }
> ```
  
### 6.1.2. char[]函数和string函数
char[]
>长度  
>```c++ int len=strlen(a);```  
>连接  
>```c++ strcat(a,b) ```的作用是将a和b连接起来后再赋值给a.  
>比较  
>```c++ strncmp(c,d,4)```是将c,d的前4个字符进行比较，并返回值。  
>
string
>长度  
>略  
比较  
>```c++ compare()```返回值意义如下：0：相等 1：大于 -1  
>查找  
>```c++ size_t find (constchar* s, size_t pos = 0) const;```在当前字符串的pos索引位置开始，查找子串s，返回找到的位置索引  
>反向  
>```c++  std:: void reverse(s.begin(), s.end());```反转（比如字符串）



## 6.2. 进阶
### 6.2.1. KMP
next 数组是被匹配串的一种属性  
用于指示匹配失效时下一个尝试位置  
### Manacher
o(N)的意思相当于，最右边界单向移动。  
若当前位置超过最右边界，则朴素地扩展。  
若没超过，则取min(对称位置的值，到最右边界的距离)    

# 7. 其他TODO
一次组队赛（至少4道，已有2道ac）
一次HDU（除了A还有一道）

# 8. 心态崩了预案
比较复杂的模拟题，如迷宫，回合制，可以自己造点（比较特殊的）样例。

## 8.1. 错误记录
10_f_3.cpp
读Node List来做一个不减且差分至多为一的函数。  
不减的地方出问题了，想读上一个点位置的值，应该读已经画好的函数，而不是Node List里面的值。  
> 如: ```Node List：(0, 0) (1, 1) (2, 2) (0, 0) (1, 1) ```  
> 读```Node List： 0 1 2 2 1```(省略x坐标)  
> 读画好的函数：```0 1 2 2 2  ```   

Codeforces可以看输入样例（机试可不行）