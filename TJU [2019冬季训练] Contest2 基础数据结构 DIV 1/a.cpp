#include<iostream>

using namespace std;

//type table
//value type
//1 a
//2 b
//3 c
//4 ab
//5 ac
//6 bc
//7 abc

int valueTableConvert(string& type)
{
	int t = 0;
	if(type.compare("A") == 0)
	{
		t = 1;
	}
	if(type.compare("B") == 0)
	{
		t = 2;
	}
	if(type.compare("C") == 0)
	{
		t = 3;
	}
	if(type.compare("AB") == 0 || type.compare("BA") == 0)
	{
		t = 4;
	}
	if(type.compare("AC") == 0 || type.compare("CA") == 0)
	{
		t = 5;
	}
	if(type.compare("BC") == 0 || type.compare("CB") == 0)
	{
		t = 6;
	}
	if(type.compare("ABC") == 0 || type.compare("ACB") == 0 ||
		type.compare("BAC") == 0 || type.compare("BCA") == 0 ||
		type.compare("CAB") == 0 || type.compare("CBA") == 0)
	{
		t = 7;
	}
	return t;
}

int main()
{
	int N;
	cin >> N;
	
	int min[8];
	int t;
	
	int candidate[8];
	int res;
	
	int val;
	string type;
	
	for(int i = 0; i < 8; i++)
		min[i] = 0x1f1f1f1f;
	
	for(int i = 0; i < N; i++)
	{
		cin >> val >> type;
		t = valueTableConvert(type);
		if (val < min[t])
			min[t] = val;
	} 
	
	/*
	if(min[4] > min[1] + min[2])
		min[4] = min[1] + min[2];
		
	if(min[5] > min[1] + min[3])
		min[5] = min[1] + min[3];
		
	if(min[6] > min[2] + min[3])
		min[6] = min[2] + min[3];*/
	
	candidate[0] = min[1] + min[6];
	candidate[1] = min[2] + min[5];
	candidate[2] = min[3] + min[4];
	
	candidate[3] = min[4] + min[5];
	candidate[4] = min[4] + min[6];
	candidate[5] = min[5] + min[6];
	
	candidate[6] = min[7];
	
	candidate[7] = min[1] + min[2] + min[3];
	
	res = 0x3f3f3f3f;
	for(int i = 0; i < 8; i++)
	{
		//cout << candidate[i] << endl;
		if(candidate[i] <= res)
			res = candidate[i];
	}
	
	if(res < 400000)
		cout << res;
	else
		cout << -1;

	return 0;
 } 
