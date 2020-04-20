#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int arr[105];
    cin>>n;
    int k=(n*(n-1))/2;
    int res[5020];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            res[m]=arr[i]+arr[j];
            m++;
        }
    }
    sort(res,res+k);
    for(int i=0;i<k-1;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<res[k-1]<<endl;
    return 0;
}
