#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string order[n][2];
    int grade[n];
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>order[i][j];
        }
        cin>>grade[i];
    }
    int max=0;
    int min=0;
    for(int i=1;i<n;i++)
    {
        
        if(grade[i]>grade[max])
        {
            max=i;
        }
        if(grade[i]<grade[min])
        {
            min=i;
        }
    }
    cout<<order[max][0]<<" "<<order[max][1]<<endl;
    cout<<order[min][0]<<" "<<order[min][1]<<endl;
    return 0;
}