#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
using namespace std;

string change(int t) //t暂存需要输出的数字
{
    string a;
    switch(t)
    {
    case 0:
        a="ling";
        break;
    case 1:
        a="yi";
        break;
    case 2:
        a="er";
        break;
    case 3:
        a="san";
        break;
    case 4:
        a="si";
        break;
    case 5:
        a="wu";
        break;
    case 6:
        a="liu";
        break;
    case 7:
        a="qi";
        break;
    case 8:
        a="ba";
        break;
    case 9:
        a="jiu";
        break;
    default:
        break;
    }
    return a;
}

void show(int k)
{
    int a=k;
    int b[1000]={0};
    int times=0;  //记录位数
    while(a>0)
    {
        if(a>9)
        {
            b[times]=a%10;
            times++;
            a=a/10;
        }
        else if(a<10)
        {
            b[times]=a;
            times++;
            break;
        }
    }
    for(int i=times-1;i>0;i--)
    {
        string x=change(b[i]);
        cout<<x<<" ";
    }
    cout<<change(b[0])<<endl;
    return;
}

int main()
{
    int n[100]={0};
    char c;
    int number;
    int len=0;
    c=cin.get();
    while (1)
    {
        stringstream ss;
        ss<<c;
        ss>>number;
        n[len]=number;//每输入一个数字就把它添加到数组的最后
        len++;
        c=cin.get();
        if(c=='\n')
            break;
    }
    int res=0;
    for(int i=0;i<=len;i++)
    {
        res=res+n[i];
    }
    show(res);
    return 0;
}
