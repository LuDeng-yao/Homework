#include<iostream>
#include<stdio.h>
using namespace std;


void bubblesort(int n,int arr[])
{
    while(1)
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
        if(j==n-1)
            break;
    }
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k))
    {
        int arr[n+20];
        for(int i=0;i<n;i++)
        {
            scanf("%d",arr[i]);
        }
        int a;
        while(k)
        {
            k--;
            bubblesort(n,arr);
            a=(n-1)/2;
            arr[a]++;
        }
        bubblesort(n,arr);
        a=(n-1)/2;
        printf("%d",arr[a]);
    }
    return 0;
}