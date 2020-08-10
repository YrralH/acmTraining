#include<iostream>

using namespace std;

int main_solve(const int n, const int k, const bool chessboard[][8]);
void DFS(int depth, int remaining_chess, const bool chessboard[][8], const int boardsize, bool ifOccupied[]); 

int main()
{
	int n;//matrix size
	int k;//chess pieces
	int C;//answer: the number of feasible cases
	bool chessboard[8][8];
	
	//tmp value
	char ch;

	cin >> n >> k;
	
	while(true)
	{
		if(n == -1)
		{
			break;
		}
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> ch;
				
				if(ch == '#')
					chessboard[i][j] = true;
				else
					chessboard[i][j] = false;
			}
		}
		
		C = main_solve(n, k, chessboard);
		
		cout << C << endl;
		
		cin >> n >> k;
	}
	
	return 0;
}

typedef struct CHOICE_NODE{
	int present_choice;
	int possible_choice[8];
	int possible_length;
}ChoiceNode;

int globe_ans;

int main_solve(const int n, const int k, const bool chessboard[][8])
{
	int ans;
	//ChoiceNode myChoice[8];
	bool ifOccupied[8];

	//init
	globe_ans = 0;
	for(int i = 0; i < n; i++)
	{
		ifOccupied[i] = false;
	}

	DFS(0, k, chessboard, n, ifOccupied);

	ans = globe_ans;

	return ans;
}

void DFS(int depth, int remaining_chess, const bool chessboard[][8], const int boardsize, bool ifOccupied[])
{
	//debug
	//cout << endl << "debug-DFS called" << endl;
	//cout << "depth " << depth << endl;
	//cout << "remaing chess " << remaining_chess << endl;
	
	//find a solution
	if(depth == boardsize)
	{
		//debug
		//cout << "debug-DFS return with globe_ans++" << endl;
		
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