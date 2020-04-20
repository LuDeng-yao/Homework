#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int old[n+5];
    int now[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>old[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>now[j];
    }
    int mark=0;
    for(int j=0;j<n-1;j++)
    {
        if(now[j]>now[j+1])
        {
            break;
        }
        else
        {
            mark++;
        }  
    }
    mark++;
    int flag=0;
    for(int t=mark;t<n;t++)
    {
        if(now[t]!=old[t])
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"Insertion Sort"<<endl;
        sort(now,now+mark+1);
    }
    else if(flag==1)
    {
        cout<<"Merge Sort"<<endl;
        int i=2;
        while(1)
        {
            int equal=0;
            for(int j=0;j<n;j++)
            {
                if(old[j]!=now[j])
                {
                    equal=1;
                    break;
                }
            }
            if(equal==0)
            {
                break;
            }
            for(int j=0;j<n;j+=i)
            {
                sort(old+j,old+j+min(i,n-j));
            }
            i+=i;
        }
        for(int j=0;j<n;j+=i)
        {
            sort(now+j,now+j+min(i,n-j));
        }
    }

    for(int i=0;i<n-1;i++)
    {
        cout<<now[i]<<" ";
    }
    cout<<now[n-1]<<endl;
    return 0;
}