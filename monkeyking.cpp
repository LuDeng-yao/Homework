#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n]={0};
    int k=0;
    int p=n;
    int i=0;
    while(p>1)
    {
        if(i=n-1)
        {
            i=0;
        }
        for(;i<n;i++)
        {
            if(arr[i]==0)
            {
                k++;
                if(k==3)
                {
                    arr[i]=1;
                    p--;
                    k=0;
                }
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        if(arr[j]==0)
        {
            cout<<j+1<<endl;
        }
    }
    return 0;
}