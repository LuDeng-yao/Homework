#include<iostream>
#include<stdio.h>
using namespace std;

int f[30005]={0};
int getf(int x)
{
    if(f[x] == x)
        return f[x];
    return f[x] = getf(f[x]);
}
void merge(int x,int y)
{
    int tx = getf(x);
    int ty = getf(y);
    if(tx != ty)
        f[ty] = tx;
    return;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        f[i] = i;
    int t;
    for(int i = 0;i < m;i++)
    {
        int k,x,z;
        scanf("%d%d",&k,&x);
        if(i == 0)
            t = x;
        for(int j = 1;j < k;j++)
        {
            scanf("%d",&z);
            merge(x,z);
        }
    }
    int num=0;
    for(int i = 0;i < n;i++)
        if(getf(t) == getf(i))
            num++;
    printf("%d\n",num);
    return 0;
}