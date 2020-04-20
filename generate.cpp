#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
 
int n,maxn=0,r[100005];
queue<int>q;
vector<int>v[100005];
 
void bfs(int old){
    q.push(old);
    r[old]=1;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int i=0;i<v[a].size();i++){
            r[v[a][i]]=r[a]+1;
            if(r[v[a][i]]>maxn)
                maxn=r[v[a][i]];
            q.push(v[a][i]);
        }
    }
}
 
int main(){
    int x,old,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==-1)
            old=i;
        else
            v[x].push_back(i);
    }
    if(n==1)
        printf("1\n1\n");
    else{
        bfs(old);
        printf("%d\n",maxn);
        for(int i=1;i<=n;i++){
            if(r[i]==maxn){
                if(cnt)
                    printf(" ");
                printf("%d",i);
                cnt++;
            }
        }
        printf("\n");
    }
    return 0;
}