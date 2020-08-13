
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
		- [algorithm](#algorithm)
	- [随机数Random Number](#随机数random-number)
	- [数论相关](#数论相关)
		- [最大公约数GCD](#最大公约数gcd)

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