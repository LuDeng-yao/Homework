#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool gender[1000]={0}; // 1 for girl, 0 for boy
int read(){
    int input=0, flag=0;
    char a=getchar();
    while((a<'0' || a>'9') && a!='-')
        a=getchar();
    if(a=='-')
    {
        flag=1;
        a=getchar();
    }
    while(a>='0' && a<='9')
    {
        input=input*10+a-'0';
        a=getchar();
    }
    gender[input]=flag;
    return input;
}
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    vector <vector <int> > p(n);
    int k;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        p[i].resize((int)k);
        for(int j=0;j<k;j++)
            p[i][j]=read();
    }
    int a, b;
    double pa_max=0.0, pb_max=0.0;
    vector<double> pa(n,0.0), pb(n,0.0);
    a=read();
    b=read();
    for(int i=0;i<m;i++)
    {
        bool founda=find(p[i].begin(),p[i].end(),a)!=p[i].end();    //if this photo has a
        bool foundb=find(p[i].begin(),p[i].end(),b)!=p[i].end();    //if this photo has b
        if(founda || foundb)
        {
            for(int j=0;j<p[i].size();j++)
            {
                if(founda && gender[a]!=gender[p[i][j]])
                {
                    pa[p[i][j]]+=(double)1/p[i].size();
                    pa_max=max(pa_max,pa[p[i][j]]);
                }
                else if(foundb && gender[b]!=gender[p[i][j]])
                {
                    pb[p[i][j]]+=(double)1/p[i].size();
                    pb_max=max(pb_max,pb[p[i][j]]);
                }
            }
        }
    }
    if(pa_max==pa[b] && pb_max==pb[a]) 
        printf("%s%d %s%d\n",gender[a]?"-":"",a,gender[b]?"-":"",b);
    else{
        for(unsigned int i=0;i<n;i++)
        {
            if(pa[i]==pa_max)
                printf("%s%d %s%d\n",gender[a]?"-":"",a,gender[i]?"-":"",i);
        }
        for(unsigned int i=0;i<n;i++)
        {
            if(pb[i]==pb_max)
                printf("%s%d %s%d\n",gender[b]?"-":"",b,gender[i]?"-":"",i);
        }
    }
    return 0;
}