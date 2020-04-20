#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int a;
    char b;
    cin>>a>>b;
    int k=(sqrt((a+1)/2))/1;
    int c=2*k*k-1;
    int d=a-c;
    int n=k;
    for(int i=k;i>0;i--)
    {
        for(int j=0;j<k-i;j++)
        {
            cout<<" ";
        }
        for(int j=2*n-1;j>0;j--)
        {
            cout<<b;
        }
        cout<<endl;
        n--;
    }
    n=k;
    for(int i=1;i<k;i++)
    {
        for(int j=k-i-1;j>0;j--)
        {
            cout<<" ";
        }
        for(int j=0;j<=2*(k-n+1);j++)
        {
            cout<<b;
        }
        cout<<endl;
        n--;
    }
    cout<<d<<endl;
    return 0;
}