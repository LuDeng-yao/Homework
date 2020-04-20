#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;
    int l=0;
    int r=n-1;
    int k;
    int times=0;
    while(l<=r)
    {
        times++;
        k=(l+r)/2;
        if(arr[k]==x)
        {
            cout<<k<<endl;
            break;
        }
        else if(arr[k]<x)
        {
            l=k+1;
        }
        else
        {
            r=k-1;
        }    
    }
    if(arr[k]!=x)
        cout<<"-1"<<endl;
    cout<<times<<endl;
    return 0;
}

