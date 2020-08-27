#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int r, s, p;

typedef struct POS{
	int row;
	int col;
}Pos;

bool PosCMP(Pos A, Pos B)
{
	return (A.row != B.row) ? (A.row > B.row) : (A.col > B.col);
}

int get_dist_form_col(int _col)
//implicit arg: s
{
    int tmp;
    tmp = _col - s;
    if(tmp <= 0)
    {
        return -tmp + 1;
    }else
    {
        return tmp;
    }
    
}

int main()
{
	cin >> r >> s >> p;

	Pos* Pa = new Pos[p];
    set<int> distance;
    set<int>::iterator it;
    int present_dist;
	int bias;

    //std in
	for(int i = 0; i < p; i++)
	{
		cin >> Pa[i].row;
		cin >> Pa[i].col;
	}

    //sort
    sort(Pa, Pa + p, PosCMP);

    //debug
    //cout << endl << "-----debug-sort-result:-----" << endl;
    //cout << "Pa[0]:" << Pa[0].row << ' ' << Pa[0].col << endl;
    //cout << "Pa[p-1]:" << Pa[p-1].row << ' ' << Pa[0].col << endl;
    //cout << endl << "-----debug-sort-result-end-----" << endl;

    //merge to set from far to near
    for(int i = 0; i < p; i++)
    {
        bias = Pa[i].row - 1;
        present_dist = get_dist_form_col(Pa[i].col) - bias;
        //debug
        //cout << endl << "-----debug-insert:-----" << endl;
        //cout << "bias: " << bias << endl;
        //cout << "present_dist: " << present_dist << endl;
        //cout << "-----debug-insert-end-----" << endl;

        it = distance.find(present_dist);

        if(it == distance.end())
        {
            distance.insert(present_dist);
        }else
        {
            while(*it == present_dist)
            {
                it++;
                present_dist++;
            }
            distance.insert(present_dist);
        }
        //debug
        //cout << "debug-final-insert: " << present_dist << endl;
    }
	
    //debug
    //cout << endl << "-----debug-insert-result:-----" << endl;
    //cout << "bias: " << bias << endl;
    //cout << "r " << r << endl;
    //cout << "*(distance.begin()): " << *(distance.begin()) << endl;
    //cout << "*(--distance.end()): " << *(--distance.end()) << endl;
    //cout << endl << "-----debug-insert-result-end-----" << endl;
	

    int max_dist = *(--distance.end());
    bias = r - 1;
    int res = bias + max_dist + 1;
    cout << res << endl;
	
	delete[] Pa;
    return 0;
}
