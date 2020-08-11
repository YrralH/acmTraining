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