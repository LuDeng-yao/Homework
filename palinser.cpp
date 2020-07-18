/********************************************
 * 一个字符串，如果从左到右读和从右到左读是完全一样的，比如"aba"，我们称其为回文串。
 * 现在给你一个字符串，可在任意位置添加字符，求最少添加几个字符，才能使其变成一个回文串。
 * 输入格式:
 * 任意给定的一个字符串，其长度不超过1000.
 * 输出格式:
 * 能变成回文串所需添加的最少字符数。
********************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int m,n;
    m=s.length();
    n=s.length();
    char a[n+5], b[n+5];
    strcpy(a,s.c_str());
    for(int i=0;i<n;i++){
        b[i]=a[--m];
    }
    int c[n+5][n+5];
    for(int i=0;i<=n;i++){
        c[i][0]=0;
        c[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if(c[i][j-1]>c[i-1][j]){
                c[i][j]=c[i][j-1];
            }
            else{
                c[i][j]=c[i-1][j];
            }
        }
    }
    int res=0;
    res=n-c[n][n];
    cout<<res<<endl;
    return 0;
}