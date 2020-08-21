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

void _debug_print_dist(int _dist[], const int SIZE)
{
    cout << endl << "---_debug_print_dist---" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << _dist[i] << ' ';
    }
    cout << endl << "---_debug_print_dist-end---" << endl;
}

int main()
{
	cin >> r >> s >> p;



	Pos* Pa = new Pos[p];

    const int DIST_SIZE = r*s*2 + 5;
    int* dist = new int[DIST_SIZE];

    int present_dist;
	int bias;
    int res;

    //init
    for(int i = 0; i < DIST_SIZE; i++)
    {
        dist[i] = 0;
    }

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
        present_dist = get_dist_form_col(Pa[i].col) - bias + (r - 1);
        //debug
        //cout << endl << "-----debug-insert:-----" << endl;
        //cout << "bias: " << bias << endl;
        //cout << "present_dist: " << present_dist << endl;
        //cout << "-----debug-insert-end-----" << endl;

        dist[present_dist]++;
        //debug
        //cout << "debug-final-insert: " << present_dist << endl;
    }
	
    //_debug_print_dist(dist, DIST_SIZE);

    res = 0;
    for(int i = 0; i < DIST_SIZE; i++)
    {
        if(dist[i] > 1)
        {
            dist[i + 1] += (dist[i] - 1);
            dist[i] = 1;
        }

        if(dist[i] > 0)
        {
            res = i;
        }
    }
    res++;

    //_debug_print_dist(dist, DIST_SIZE);
	


    cout << res << endl;
	
	delete[] Pa;
    return 0;
}
