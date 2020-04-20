#include<iostream>
#include<stdio.h>
using namespace std;
struct obj
{
    int value1;
    int value2;
};
int main()
{
    int n;
    cin>>n;
    obj o[10]={0};
    for(int i=0;i<n;i++)
    {
        cin>>o[i].value1>>o[i].value2;
    }
    for(int i=0;i<n;i++)
    {
        cout<<o[i].value1<<o[i].value2<<endl;
    }
    /*int a=6;
    int b=9;
    swap(a,b);
    cout<<a<<b<<endl;
    if(Comp::prior(a,b))
        cout<<"1"<<endl;
    else
        cout<<"2"<<endl;*/

    return 0;
}
