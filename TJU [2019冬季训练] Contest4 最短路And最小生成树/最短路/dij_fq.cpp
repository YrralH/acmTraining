//多测初始化：memset(h,0,sizeof(h));cnt=0;memset(t,0,sizeof(t));
//dis也可以考虑memset  
//无向图 M*=2 ins两次 
//made by extraordinarily
 
#include<cstdio>
#include"string.h"

const int N=1e4+5,M=5e5+5,inf=2147483647;
struct edge{
    int v,nxt,w;
    edge(int _v, int _nxt, int _w)
    {
        v = _v;
        nxt = _nxt;
        w = _w;
    }
}e[M];
int h[N],cnt,n,m,s,d,dis[N],t[N<<1];

void printDebugStage(int i)
{
    printf("\n------debug id: %d------\n", i);
}

void ins(int u,int v,int w){
    e[++cnt]=edge(v,h[u],w);
    h[u]=cnt;
}//加边 

void update(int p,int v){
    // 首先，这个东西结构类似一个堆。
    // x的左儿子是2x   (x<<1)
    // x的右儿子是2x+1 (   x<<1^1  或者 x<<1|1   )
    // 1是根节点

    // 把所有数据放到叶子上
    // 那么对于1~n个数据，就需要t[2n]的数组来存
    // 例：n=2。
    // t[0]不用   t[1]是根    t[2]是1号数据   t[3]是2号数据
    // 根在两个儿子中取最值，所以t[1]就是整体最值

    // 下面t[x]存的是最短的点的标号是谁

    p+=n-1; // 直达叶子节点，上面n=2的例子应该很明白
    t[p]=v; // 改叶子。为啥要这样看最后。

    while (p!=1) // 一路找爹，把最近的点传上去。
    {
        t[p>>1]= dis[t[p]] < dis[t[p^1]] ? t[p] : t[p^1];
        p>>=1;
    }

    // 那么问题来了，如果一个点的距离已经锁了，但是它还在这个数据结构里咋办呢。
    // 把它变成0。让dis[0]永远是inf，所以它就不会参与竞争最小值了。这也是t[p]=v存在的理由。
}//更新

void erase(int p)
{
    update(p, 0);
    return;
}

int main()
{
    printDebugStage(0);
    scanf("%d%d",&n,&m);

    memset(h,0,sizeof(h));
    cnt=0;
    memset(t,0,sizeof(t));

    printDebugStage(1);
        
    for(int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        ins(u, v, w);
        ins(v, u, w);
    }
        
    scanf("%d", &s);
    for(int i = 0; i <= n; i++)
    {
        dis[i]=inf;
    }

    dis[s] = 0;
    update(s, s);

    for(int k=1,u=s;k<=n;++k)
	{
	    //printf("%d %d\n",u,dis[u]);
        if(dis[u] == inf) 
            break;//防止狗血的不连通图，可删 
        for(int i = h[u]; i; i = e[i].nxt)
        {
            if(dis[e[i].v] > dis[u] + e[i].w)
            {
                dis[e[i].v] = dis[u] + e[i].w;
                update(e[i].v, e[i].v);
            }
        }

        update(u,0);u=t[1];
    }

    printDebugStage(100);
    for(int i = 0; i <= n; i++)
        printf("%d\n",dis[i]);
	return 0;
}
