#include <cstdio>
#include <algorithm>

using namespace std;

const int INF =100000;
const int maxn =3000;
// 节点编号从1开始，邻接矩阵实现prim算法


int G[maxn][maxn]; 
bool vis[maxn]; 
int d[maxn]; 
// G矩阵存储任意两点间的距离，d存储从起始点到任意各点的最短距离

int n,m; //n为顶点数目，m为边的数目

int prim(int v)  //普利姆算法求最小连通图
{
    int sum=0;//最短路径长度
    int s[n+1]={0};
    fill(vis,vis+maxn,false);
    fill(d,d+maxn,INF);

    d[v]=0;  //到达本身的距离为0

    for(int i=1;i<=n;i++)
    {
        int u =-1;
        int mins = INF;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==false && d[j]<mins)
            {
                u =j; 
                mins= d[j];
                s[j]=1;
            }
        }
        vis[u] = true;
        sum +=d[u];

        for(int j=1;j<=n;j++)
        {
            if(vis[j]==false && G[u][j]!=INF  && G[u][j] <d[j])
                d[j] = G[u][j];
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(s[j]==0)
        {
            return -1;
        }
    }
    return sum;
}

int main()
{
    scanf("%d %d",&n,&m);
    fill(G[0],G[0]+maxn*maxn,INF);

    for(int i=1;i<=m;i++)
    {
        int u,v,len; scanf("%d %d %d",&u,&v,&len);

        G[u][v] = G[v][u] =len;
    }
    if(n>m)
    {
        printf("-1\n");
        return 0;
    }
    int sum =prim(1);

    printf("%d\n",sum);
    return 0;
}