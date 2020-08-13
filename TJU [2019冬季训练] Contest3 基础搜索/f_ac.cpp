#include<iostream>
#include<queue>

using namespace std;

char chessBoard[2][10][10];

int dist[2][10][10];

typedef struct POSSITION{
    int l;
    int x;
    int y;
}Possition;

bool main_solver(int N, int M, int T);
//implicit arg: chessBoard

Possition make_poss(int l, int x, int y);
char visitBoard_globe(Possition& tmp);
Possition destination;

bool try_new_possition(Possition p_old, Possition p_new, queue<Possition>& pq);

int main()
{
    int C;//number of cases
    int N, M, T;
    char tmpChar;
    bool ifAble;

    cin >> C;

    for(int caseCount = 0; caseCount < C; caseCount++)
    {
        cin >> N >> M >> T;


        for(int l = 0; l < 2; l++)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < M; j++)
                {
                    cin >> tmpChar;
                    chessBoard[l][i][j] = tmpChar;
                    if(tmpChar == 'P')
                    {
                        destination.l = l;
                        destination.x = i;
                        destination.y = j;
                    }
                }
            }
        }

        ifAble = main_solver(N, M, T);
        if(ifAble)
        {
            cout << "YES" << endl;
        }else
        {
            cout << "NO" << endl;
        }
        
    }


    return 0;
}


bool main_solver(int N, int M, int T)
//implicit arg: chessBoard
{
    queue<Possition> q;
    Possition tmpP;
    int l;
    int x;
    int y;
    int reach_flag;

    //init
    for(int l = 0; l < 2; l++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                dist[l][i][j] = -1;
            }
        }
    }
    dist[0][0][0] = 0;
    q.push(make_poss(0, 0, 0));
    reach_flag = false;

    while(!q.empty())
    {
        tmpP = q.front();
        l = tmpP.l;
        x = tmpP.x;
        y = tmpP.y;
        q.pop();

        //debug
        //cout << "---debug:---" << endl;
        //cout << "now possition: " << l << ' ' << x << ' ' << y << endl;
        //cout << "now dist: " << dist[l][x][y] << endl;

        if(x >= 1)
        {
            reach_flag = try_new_possition(tmpP, make_poss(l, x-1, y), q);
            if(reach_flag)
            {
                break;
            }
        }

        if(x <= N - 2)
        {
            reach_flag = try_new_possition(tmpP, make_poss(l, x+1, y), q);
            if(reach_flag)
            {
                break;
            }
        }

        if(y >= 1)
        {
            reach_flag = try_new_possition(tmpP, make_poss(l, x, y-1), q);
            if(reach_flag)
            {
                break;
            }            
        }
        
        if(y <= M - 2)
        {
            reach_flag = try_new_possition(tmpP, make_poss(l, x, y+1), q);
            if(reach_flag)
            {
                break;
            }            
        }
    }

    //debug
    //cout << "-----debug-destination-dist:-----" << endl;
    //cout << "destination:" << destination.l << ' ' << destination.x << ' ' <<  destination.y << endl;
    //cout << "destination-dist:" << dist[destination.l][destination.x][destination.y] << endl;

    if(dist[destination.l][destination.x][destination.y] <= T && dist[destination.l][destination.x][destination.y]  >= 0)
    {
        return true;
    }else
    {
        return false;
    }
    
}

bool try_new_possition(Possition p_old, Possition p_new, queue<Possition>& pq)
{


    switch(visitBoard_globe(p_new))
    {
        case '.':
            if(dist[p_new.l][p_new.x][p_new.y] < 0)
            {
                dist[p_new.l][p_new.x][p_new.y] = dist[p_old.l][p_old.x][p_old.y] + 1;
                pq.push(p_new);
                return false;
            } else{
                return false;
            }
            break;

        case '#':
            if(chessBoard[1-p_new.l][p_new.x][p_new.y] == '.')
            {
                if(dist[1-p_new.l][p_new.x][p_new.y] < 0)
                {
                    dist[1-p_new.l][p_new.x][p_new.y] = dist[p_old.l][p_old.x][p_old.y] + 1;
                    pq.push(make_poss(1-p_new.l, p_new.x, p_new.y));
                    return false;
                }else{
                    return false;
                }

                break;
            }

            if(chessBoard[1-p_new.l][p_new.x][p_new.y] == 'P')
            {
                if(dist[1-p_new.l][p_new.x][p_new.y] < 0)
                {
                    dist[1-p_new.l][p_new.x][p_new.y] = dist[p_old.l][p_old.x][p_old.y] + 1;
                    pq.push(make_poss(1-p_new.l, p_new.x, p_new.y));
                    return true;                    
                }else
                {
                    return true;
                }
                
                break;
            }
            break;
        case 'P':
            if(dist[p_new.l][p_new.x][p_new.y] < 0)
            {
                dist[p_new.l][p_new.x][p_new.y] = dist[p_old.l][p_old.x][p_old.y] + 1;
                pq.push(p_new);
                return true;                
            }else
            {
                return true;
            }
            
            break;
        default:
            break;
    }

    return false;
}

Possition make_poss(int l, int x, int y)
{
    Possition tmp;
    tmp.l = l;
    tmp.x = x;
    tmp.y = y;

    return tmp;
}

char visitBoard_globe(Possition& tmp)
{
    return chessBoard[tmp.l][tmp.x][tmp.y];
}