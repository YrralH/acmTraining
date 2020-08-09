#include<iostream>

using namespace std;

int main_solve(const int n, const int k, const bool chessboard[][8]);

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

int main_solve(const int n, const int k, const bool chessboard[][8])
{
	int ans;
	ChoiceNode myChoice[8];
	int flag;

	//init
	ans = 0;
	flag = true;

	while(flag)
	{
		//search
	}



	return ans;
}
