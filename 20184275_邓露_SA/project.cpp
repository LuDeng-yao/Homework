#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

int Max(int a,int b){
    return a>b?a:b;
}

int main(){
    ifstream fin("test.txt");
    if(!fin){
        cout<<"读取文件失败！"<<endl;
        return -1;
    }
    int m,n;//m排n列
    fin>>m>>n;
    char c;
    int value[m+20][n+20]={0};
    int res[m+20][n+20]={0};//每一个位置的最大值
    int pos[m+20][n+20]={0};//记录最大值位置
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            fin>>value[i][j]>>c;
            res[i][j]=value[i][j];
        }
        fin>>value[i][n];
        res[i][n]=value[i][n];
    }
    fin.close();
    //动态规划
    for(int i=1;i<m;i++){
        for(int j=1;j<=i;j++){
            if(j-1>0){
                int temp=res[i+1][j-1];
                res[i+1][j-1]=Max(temp,res[i][j]+value[i+1][j-1]);
                if(res[i+1][j-1]!=temp){
                    pos[i][j-1]=j;
                }
            }
            if(j+1<=n){
                int temp=res[i+1][j+1];
                res[i+1][j+1]=Max(temp,res[i][j]+value[i+1][j+1]);
                if(res[i+1][j+1]!=temp){
                    pos[i][j+1]=j;
                }
            }
            int temp=res[i+1][j];
            res[i+1][j]=Max(temp,res[i][j]+value[i+1][j]);
            if(res[i+1][j]!=temp){
                pos[i][j]=j;
            }
        }
    }

    int maximun=res[m][1];
    pos[m][1]=1;
    for(int j=2;j<=n;j++){
        int temp=res[m][j];
        maximun=Max(temp,maximun);
        if(maximun==temp){
            pos[m][1]=j;
        }
    }
/**************************
    //test of res[][] and pos[][]
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",res[i][j]);
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",pos[i][j]);
        }
        cout<<endl;
    }
***************************/
    ofstream fout("output.txt",ios::trunc);
    cout<<"测试结果"<<endl;
    cout<<maximun<<"\t（最大价值）"<<endl;
    fout<<maximun<<"\t（最大价值）"<<"\n";
    int flag=1;
    int store[m+20];
    for(int i=m;i>0;i--){
        store[i]=pos[i][flag];
        flag=store[i];
    }
    cout<<store[1]<<"\t（开始位置，固定）"<<endl;
    fout<<store[1]<<"\t（开始位置，固定）"<<"\n";
    for(int i=2;i<=m;i++){
        cout<<store[i]<<"\t在第"<<i<<"排的位置"<<endl;
        fout<<store[i]<<"\t在第"<<i<<"排的位置"<<"\n";
    }
    fout.close();
    cout<<"测试结果已更新到output.txt"<<endl;
    system("pause");
    getchar();
    getchar();
    return 0;
}
