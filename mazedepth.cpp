#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn=100020;
int N;
int K;
int tmp;
bool vis[maxn]; 
vector<int>v[maxn];   //动态数组，将相同父亲的孩子放入父亲的vector中； 
int depth[maxn];  //用来记录每个数字的深度； 
int root;    
int tp;
int maxnn = -1;   //用来找深度最大的； 
int ans = -1;    //用来记录答案； 
int main()
{
    queue<int>q;
    scanf("%d",&N);
    for(int i = 1 ; i <= N ;i++)
    {
        scanf("%d",&K);
        while(K--)
        {
            scanf("%d",&tmp);
            v[i].push_back(tmp);  //将孩子结点放入父亲的数组中； 
            vis[tmp] = 1;    //标记该点是孩子结点； 
        }
    }
    for(int j = 1 ; j <= N ;j++)
    {
        if(vis[j]!=1)
        {
            root = j ;    //找到根结点； 
        }
    }
    
    q.push(root);    //将根结点入队； 
    depth[root] = 1;  //根的深度为1； 
    while(!q.empty())
    {
        tp = q.front();
        q.pop();
        for(int j = 0 ; j < v[tp].size();j++)
        {
            depth[v[tp][j]] = depth[tp]+1;  //每个孩子的深度比父亲多一； 
            q.push(v[tp][j]);  //将孩子入队，重复过程；
        }
    }
    for(int j = 1 ; j <= N ;j++)
    {
        if(depth[j]>maxnn)
        {
            maxnn = depth[j];  //找最大深度的； 
            ans = j;     //找到答案； 
        }
    }
    printf("%d\n",ans);
    return 0;
}