#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n+20];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int times=0;
    while(times<k)
    {
        int j=0;
        int temp;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<=arr[i+1])
            {
                j++;
            }
            else
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            
        }
        times++;
        if(j==n-1)
            break;
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<endl;
    return 0;
}