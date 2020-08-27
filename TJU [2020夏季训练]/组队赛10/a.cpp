#include<iostream> 
#include<stack>

using namespace std;

string s;
string s0;

int n;

typedef struct ITEM{
	int sel;// 0 for none, 1 for num, 2 for letter
	int number;
	char letter;
	int index;
}Item;

int itemCMP(Item I0, Item I); 
void getNextItem(const string s, Item& I);
void itemDebug(const Item I, int number);

bool myCmp(string s0, string s)
{
	int flag;
	
	Item I;
	Item I0;
	
	//init
	I.index = 0;
	I0.index = 0;
	I.sel = 0;
	I0.sel = 0;
	
	
	flag = itemCMP(I0, I);
	//debug
	//cout << endl << "flag" << flag << endl;
	while(flag == 0)
	{
		getNextItem(s, I);
		getNextItem(s0, I0);
		
		//itemDebug(I, 1);
		//itemDebug(I0, 0);
		
		if(I.sel == 0 && I0.sel == 0)
		{
			return false;
		}
		
		flag = itemCMP(I0, I);
	}
	
	if(flag > 0)
	{
		return true;
	}
	
	if(flag < 0)
	{
		return false;
	}
}

void itemDebug(const Item I, int number)
{
	//debug
	cout << "debugI " << number << endl;
	cout << I.sel << ' ' << I.letter << ' ' << I.number << ' ' << I.index << endl; 
}

void getNextItem(const string s, Item& I)
{
	char nextChar;
	int tmpNum;
	int tmpSum;
	
	if(I.index >= s.length())
	{
		I.sel = 0;
		return;
	}
	
	nextChar = s[I.index];
	
	if(('a' <= nextChar && nextChar <= 'z') || ('A' <= nextChar && nextChar <= 'Z'))
	{
		I.sel = 2;
		I.letter = nextChar;
		I.index++;
		return;
	}
	
	stack<int> sta;
	
	
	if('0' <= nextChar && nextChar <= '9')
	{
		while('0' <= nextChar && nextChar <= '9')
		{
			sta.push(static_cast<int>(nextChar - '0'));
			I.index++;
			if(I.index < s.length())
			{
				nextChar = s[I.index];
			}else
			{
				break;
			}
		}
		
		//cout << sta.size() << "aa" << endl;
		
		tmpSum = 0;
		int times = 1;
		while(!sta.empty())
		{
			tmpNum = sta.top();
			sta.pop();
			tmpSum = tmpSum + tmpNum * times; 
			times*=10;
			//cout << tmpSum << "tmpSum" << endl;
		}
		
		I.sel = 1;
		I.number = tmpSum;
		return;
	}
}

// > 0, I before I0
int itemCMP(Item I0, Item I)
{
	if(I.sel != I0.sel)
	{
		return I0.sel - I.sel;
	}else{
		if(I.sel == 0)
		{
			return 0;
		 } 
		
		if(I.sel == 1)
		{
			return I0.number - I.number;
		}
		
		if(I.sel == 2)
		{
			return I0.letter - I.letter;
		}
	}
}

int main()
{
	cin >> n;
	cin >> s0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if(myCmp(s0, s))
		{
			cout << '-' << endl;
		}else{
			cout << '+' << endl;
		}
	}
	
	return 0;
}
