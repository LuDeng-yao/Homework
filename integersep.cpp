#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int c;
    cin>>c;
    int result[c+20];
    for(int j=0;j<c;j++){
        long int n;
        cin>>n;
        long long int sep[n+20];
        for(int i = 1; i <= n; i++){
            if(i == 1)
                sep[i] = 1;
            else if(i % 2 != 0)
                sep[i] = sep[i - 1];
            else
                sep[i] = (sep[i - 1] + sep[i / 2]) % 1000000000;
        }
        result[j]=sep[n];
    }
    for(int j=0;j<c-1;j++){
        cout<<result[j]<<" ";
    }
    cout<<result[c-1]<<endl;
    return 0;
}