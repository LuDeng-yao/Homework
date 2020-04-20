#include<iostream>
using namespace std;

void insert_sort(int *now,int n)
{
    int a,b,k;
    for(a=2;a<=n&&now[a-1]<=now[a];a++);
    k=now[a];
    for(b=a-1;b>=1;b--)
    {
        if(now[b] > k)
        {
            now[b+1]=now[b];
        }
        else
        {
            break;
        }
        now[b]=k;
    }
}
void swap(int *e,int *f)
{
    int d=*e;
    *e=*f;
    *f=d;
}
void maxheap(int l,int r,int *now)
{
    int i=1;
    int j=i*2;
    while(j<=r)
    {
        if(j+1<=r&&now[j]<now[j+1])
        {
            j++;
        }
        if(now[j]>now[i])
        {
            swap(now[i],now[j]);
            i=j;
            j=i*2;
        }
        else 
            break;
    }
}
void heap_sort(int *now,int n)
{
    int pos=n;
    for(pos=n;pos>1&&now[pos]>now[pos-1];pos--);
    swap(now[1],now[pos]);
    maxheap(1,pos-1,now);
}
void print(int *now,int n)
{
    for(int i=1;i<n;i++)
    {
        cout<<now[i]<<" ";
    }
    cout<<now[n]<<endl;
}
int main()
{
    int n;
    cin>>n;
    int pre[120]={0};
    int now[120]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>pre[i];
    }
    for(int j=1;j<=n;j++)
    {
        cin>>now[j];
    }
    if(now[1]<now[2])
    {
        cout<<"Insertion Sort"<<endl;
        insert_sort(now,n);
        print(now,n);
    }
    else
    {
        cout<<"Heap Sort"<<endl;
        heap_sort(now,n);
        print(now,n);
    }
    
}