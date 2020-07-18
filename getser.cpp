/***********************************
 * 求两个字符串的最长公共子串长度。
 * 输入格式:
 * 输入长度≤100的两个字符串S和T。
 * 输出格式:
 * 输出两个字符串的最长公共子串长度。
***********************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

int Max(int x,int y){
    return x>y ? x:y;
}

int main(){
    string s,t;
    cin>>s>>t;
    int m,n;
    m=s.length();
    n=t.length();
    char a[m+5];
    char b[n+5];
    strcpy(a,s.c_str());
    strcpy(b,t.c_str());
    int result=0;
    int temp=0;
    int c[m+5][n+5];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            c[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                result=Max(result,c[i][j]);
            }
            else{
                temp=Max(c[i][j-1],c[i-1][j]);
                result=Max(temp,result);
            }
        }
    }
    cout<<result<<endl;
    return 0;
}