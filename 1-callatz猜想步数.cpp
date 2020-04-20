#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int counted(int n)
{
    int t=0;
    int k;  
    while(n!=1)
    {
        k=n%2;
        if(k==1)
        {
            t++;
            n=(3*n+1)/2;
        }
        else if(k==0)
        {
            t++;
            n=n/2;
        }
    }
    return t;
}

int main()
{
    int n;
    while(cin>>n&&n>0&&n<=1000)
    {
        int t; 
        t=counted(n);
        cout<<t<<endl;
    }
    return 0;
}
