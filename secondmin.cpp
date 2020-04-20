#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m;
    int arr[10];
    for(int i=0;i<m;i++)
    {
        cin>>n;
        int a=0,b=0;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            if(arr[j]>arr[a])
            {
                if(arr[a]==arr[b])
                {
                    b=j;
                }
            }
            else if(arr[j]<arr[a])
            {
                b=a;
                a=j;
            }
        }
        if(arr[a]==arr[b])
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<arr[b]<<endl;
        }
    }
    return 0;
}