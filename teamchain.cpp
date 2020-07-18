/*******************************
 * 球队“食物链”：
 * 输入第一行给出一个整数N（2≤N≤20），为参赛球队数。
 * 随后N行，每行N个字符，给出了N×N的联赛结果表，其中第i行第j列的字符为球队i在主场对阵球队j的比赛结果：
 * W表示球队i战胜球队j，L表示球队i负于球队j，D表示两队打平，-表示无效（当i=j时）
*******************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int flag=0;
int mark[40];
int res[40];
int comp[40][40];
void chain(int i,int len){
    if(flag)
        return;
    res[len]=i;
    if(len==n){
        if(comp[i][1])
            flag=1;
        return;
    }
    int cn=0;
    for(int j=1; j<=n; j++)
    {
        if(mark[j]==0&&comp[j][1]==1)
            cn=1;
    }
    if(cn==0) 
        return;
    for(int k=1; k<=n; k++)
    {
        if(comp[i][k]==1&&mark[k]==0){
            mark[i]=1;
            chain(k,len+1);
            mark[i]=0;
        }
    }
}

int main(){
    cin>>n;
    char c;
    flag=0;
    for(int i=1;i<=n;i++){
        mark[i]=0;
        res[i]=0;
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='L'){
                comp[j][i]=1;
            }
            else if(c=='W'){
                comp[i][j]=1;
            }
        }
    }
    chain(1,1);
    if(flag){
        for(int i=1;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<res[n]<<endl;
    }
    else{
        cout<<"No Solution"<<endl;
    }
    return 0;
}