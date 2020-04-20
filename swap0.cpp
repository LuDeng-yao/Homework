#include<iostream>
using namespace std;

int main()
{
	int n;
    cin>>n;
    int arr[n+20];
    int order[n+20];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        order[arr[i]]=i;
    }
    int times=0;
	int temp;
	for (int i=0; i<n; i++)
    {
		int j = i;
		int flag = 0; 
        int cntwhile = 0;
        int a=arr[j];
		if( arr[j] != j)
        {
			while(1)
            {	
                cntwhile++;
                if( j==0 ) 
                    flag = 1;
                if(arr[order[j]] == order[j]) 
                {
                    arr[j]=a;
                    order[j] = j;
                    break;
			    }
                temp = order[j];
                arr[j] = arr[order[j]];
                order[j] = j;
                j = temp;		
			}

			if (flag == 1 && cntwhile != 0) 
                cntwhile--;
			else 
                cntwhile++;
			times += cntwhile;
		}
	}	
	cout<<times<<endl;;
	return 0; 
} 
