//多测初始化：memset(h,0,sizeof(h));cnt=0;memset(t,0,sizeof(t));
//dis也可以考虑memset  
//无向图 M*=2 ins两次 
//made by extraordinarily
 
#include<cstdio>
const int N=1e4+5,M=5e5+5,inf=2147483647;
struct edge{int v,nxt,w;}e[M];
int h[N],cnt,n,m,s,dis[N],t[N<<1];
void ins(int u,int v,int w){e[++cnt]=(edge){v,h[u],w};h[u]=cnt;}//加边 
void update(int p,int v){for(t[p+=n-1]=v;p;p>>=1)t[p>>1]=dis[t[p]]<dis[t[p^1]]?t[p]:t[p^1];}//更新 
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<=n;i++)dis[i]=inf;
    for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),ins(u,v,w);
    dis[s]=0;update(s,s);
    for(int k=1,u=s;k<=n;++k)
	{
	    //printf("%d %d\n",u,dis[u]);
        if(dis[u]==inf) break;//防止狗血的不连通图，可删 
        for(int i=h[u];i;i=e[i].nxt)
        if(dis[e[i].v]>dis[u]+e[i].w)dis[e[i].v]=dis[u]+e[i].w,update(e[i].v,e[i].v);
        update(u,0);u=t[1];
    }
    //for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
}
