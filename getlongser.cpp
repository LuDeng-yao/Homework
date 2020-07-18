/*********************************************
 * 求两个字符串的所有最长公共子串。
 * 输入格式:
 * 依次输入长度≤100的两个字符串S和T。
 * 输出格式:
 * 输出S与T所有最长公共子串，若最长公共子串多于1个，则将所有子串按字典序从小到大排序后输出。
*********************************************/
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

int Max(int x,int y){
    return x>y ? x:y;
}
int Min(int x,int y){
    return x<y ?x:y;
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
    int c[m+5][n+5];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            c[i][j]=0;
        }
    }
    int len=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            len=Max(len,c[i][j]);
        }
    }
    int mark[m]={0};
    int amount=0;
    if(len==0){
        cout<<"NO"<<endl;
    }
    else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(c[i][j]==len){
                   mark[amount]=i-1;
                   amount++;
                }
            }
        }
    }
    char result[amount][len];
    for(int i=0;i<amount;i++){
        int pos=mark[i];
        for(int j=len-1;j>=0;j--){
            result[i][j]=a[pos];
            pos--;
        }
    }
    // string s[amount];
    // for(int i=0;i<amount;i++){
    //     stringbuf str=new stringbuf();
    //     for(int j=0;j<len;j++){
    //         str.append(result[i][j]);
    //     }
    //     s[i]= str.toString();
    // }
    int minindex;
    char temp[len];	
    for(int i = 0; i<amount-1;i++)	{	    
        minindex = i;	    
        for(int j = i+1; j<amount; j++){		    
            if(result[j][0]<result[minindex][0]){				
                minindex = j;
                break;
            }			
        }		
        for(int j=0;j<len;j++){
            temp[j]=result[i][j];
            result[i][j]=result[minindex][j];
            result[minindex][j]=temp[j];
        }
    }
    // for(int i=0;i<amount;i++){
    //     cout<<s[i]<<endl;
    // }
    for(int i=0;i<amount;i++){
        for(int j=0;j<len;j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
    return 0;
}