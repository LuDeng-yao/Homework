#include<iostream>
using namespace std;
void check(Queue&Q,Stack&S)
{
    int c,d,k=1;
    while (cin>>c&&c!=' '&&c!='\n')
    {
        Q.enqueue(&c);
        S.push(c);
    }
    while(!S)
    {
        c=S.pop();
        d=Q.dequeue();
        if(c!=d)
        {
            k==0;
            break;
        }
    }
    if(k==1)    cout<<"true"<<endl;
    if(k==0)    cout<<"false"<<endl;
}
int main()
{
    check(Queue&Q,Stack&S);
    return 0;
}
