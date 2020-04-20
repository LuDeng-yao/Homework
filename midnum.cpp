#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
    long long int k;
	while(cin>>n>>k)
    {
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		long long int a=(n-1)/2;
		long long int flag=1;
		while(k>0)
        {
			if(a+flag>n-1)
            {
				arr[a]+=k/flag;
				k=0;
				break;
			}

	        long long int t=arr[a+flag]-arr[a];
			if(k>=t*flag)
            {
				k-=t*flag;
				arr[a]+=t;
			    flag++;
			}
			else
            {
				arr[a]+=k/flag;
				k=0;
                break;
			}
		}
		cout<<arr[a]<<endl;
	}
	return 0;
}