#include<iostream>

using namespace std;

typedef struct NODE{
	int index;
	struct NODE* next;
}Node;

const int SIZE = 100005;
Node A[SIZE];
int validList[SIZE*2];
int validList_validSize;
bool main_flag;

void init()
{
	for(int i = 0; i < SIZE; i++)
	{
		A[i].index = i;
		A[i].next = NULL;
	}
	validList_validSize = 0;
	main_flag = true;
	return;
}

Node* findAncestors(Node* a)
{
	Node* tmp;
	tmp = a;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	
	return tmp;
}

int main()
{
	int a, b;
	
	Node* tmpA1;
	Node* tmpA2;
	Node* tmpA3;
	int root;
	
	while(cin >> a >> b)
	{
		if(a == -1 && b == -1)
		{
			break;
		}
		
		init();
		
		while(1)
		{
			if(a == 0 && b == 0)
			{
				//check if all nodes refer to the same root
				if(validList_validSize != 0)
				{
					tmpA3 = findAncestors(&(A[validList[0]]));
					root = tmpA3->index;
					for(int i = 1; i < validList_validSize; i++)
					{
						tmpA3 = findAncestors(&(A[validList[i]]));
						if(root != tmpA3->index)
						{
							main_flag = false;
							break;
						}
					}
				}
				
				
				if(main_flag)
				{
					cout << "Yes" << endl;
				}else
				{
					cout << "No" << endl;
				}
				break;
			}
			
			//if it can not be a tree, no need to process remaining input
			if(!main_flag)
			{
				cin >> a >> b;
				continue;
			}
			
			//process the input
			validList[validList_validSize] = a;
			validList_validSize++;
			validList[validList_validSize] = a;
			validList_validSize++;
			
			tmpA1 = findAncestors(&(A[a]));
			tmpA2 = findAncestors(&(A[b]));
			
			//jugde if the Graph has redundant and unexpected path
			if(tmpA1->index == tmpA2->index)
			{
				main_flag = false;
				cin >> a >> b;
				continue;
			}else{
				tmpA2->next = tmpA1;
				cin >> a >> b;
				continue;
			}
		}
	}
		
	return 0;
}
