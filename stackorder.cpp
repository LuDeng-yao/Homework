#include<iostream>
using namespace std;
 

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    while(k--)
    {    
        int a[1005]; 
        int top=0; 
        int index1=1,index2=0;
        int b[1005];
    	int flag=1;
    	for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
    	while(1)
    	{
    		if(index1==b[index2])
    		{
    			index1++;
    			index2++;
			}
            else if(top!=0&&a[top-1]==b[index2])
			{
				top--;
				index2++; 
			}
			else
			{
				if(index1>n)
                {
                    break;
                } 
                a[top]=index1;
				top++;
				index1++;
				if(top>=m)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0||top!=0)
        {
            cout<<"NO"<<endl;
        }
		else
        {
            cout<<"YES"<<endl;
        }
	}
	return 0;
}