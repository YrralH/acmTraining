
<!-- TOC -->

- [基础搜索](#基础搜索)
	- [递归写DFS](#递归写dfs)
	- [队列与BFS](#队列与bfs)
- [附加](#附加)
	- [常用STL库](#常用stl库)
		- [queue](#queue)
		- [stack](#stack)
		- [pair and piority queue](#pair-and-piority-queue)
		- [pair and map](#pair-and-map)
		- [迭代器](#迭代器)
		- [set](#set)
		- [algorithm](#algorithm)
	- [随机数Random Number](#随机数random-number)
	- [数论相关](#数论相关)
		- [最大公约数GCD](#最大公约数gcd)
	- [最短路/最小生成树](#最短路最小生成树)
		- [Dijkstra](#dijkstra)
	- [Floyd](#floyd)
- [心态崩了预案](#心态崩了预案)
	- [错误记录](#错误记录)

<!-- /TOC -->

# 基础搜索  
## 递归写DFS  

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


## 队列与BFS
没什么好说的，也许STL的队列比较方便。

# 附加
## 常用STL库
### queue
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
### stack
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
### pair and piority queue
TODO 自定义比较函数    
> 使用：push(a) pop() top() empty() size()
### pair and map
TODO：map and hashmap

### 迭代器

### set

### algorithm
TODO：sort 全排列

## 随机数Random Number
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

## 数论相关
### 最大公约数GCD
可用库
> ```c++
> #include<algorithm>
> int gcd = __gcd<int>(N, M);
> //显然最小公倍数
> int lcm = N * M / gcd;
> ```
若不用库当然辗转相除即可。  
不 可 维 护 辗 转 相 除 ↓ 
> ```c++
> int gcd1(int a,int b)
> {
> 	while(b ^= a ^= b ^= a %= b);
> 	return a;
> }
> ```

## 最短路/最小生成树
### Dijkstra
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
> 当然是堆优化，最简单就是用优先队列  
> TODO
> 另外还有FQ的邪术
> TODO


## Floyd

> ```c++
> for (int k=1;k<=n;k++)
> for (int i=1;i<=n;i++)
> for (int j=1;j<=n;j++)
> if (a[i][k]+a[k][j]<a[i][j])
>		a[i][j] = a[i][k]+a[k][j];
> ```




# 心态崩了预案
比较复杂的模拟题，如迷宫，回合制，可以自己造点（比较特殊的）样例。

## 错误记录
10_f_3.cpp
读Node List来做一个不减且差分至多为一的函数。  
不减的地方出问题了，想读上一个点位置的值，应该读已经画好的函数，而不是Node List里面的值。  
> 如: ```Node List：(0, 0) (1, 1) (2, 2) (0, 0) (1, 1) ```  
> 读```Node List： 0 1 2 2 1```(省略x坐标)  
> 读画好的函数：```0 1 2 2 2  ```   

Codeforces可以看输入样例（机试可不行）