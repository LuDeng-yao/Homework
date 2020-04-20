#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int> s[n+5];
    int m;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            s[i].insert(x);
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        set<int> res;
        set_intersection(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),inserter(res,res.begin()));
        int nc=res.size();
        int nt=s[a].size()+s[b].size()-res.size();
        double x=100.00*nc/nt;
        printf("%.2f%%\n",x);
    }
    return 0;
}