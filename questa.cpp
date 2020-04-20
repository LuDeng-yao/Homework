#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int small;
    if(m>=n)
        small=n;
    else
        small=m;
            
    char c;
    int temp;
    stack<int> S1,S2;

    while(cin>>c)
    {
        if(c=='T')
        {
            break;
        }
        else if(c=='A')
        {
            cin>>temp;
            if(S1.size()<small)
            {
                S1.push(temp);
            }
            else
            {
                if(S2.empty())
                {
                    int temp2;
                    while(!S1.empty())
                    {
                        temp2=S1.top();
                        S1.pop();
                        S2.push(temp2);
                    }
                    S1.push(temp);
                }
                else
                {
                    cout<<"ERROR:Full"<<endl;
                }  
            }
        }
        else if(c=='D')
        {
            if(!S2.empty())
            {
                cout<<S2.top()<<endl;
                S2.pop();
            }
            else
            {
                if(!S1.empty())
                {
                    int temp3;
                    while(!S1.empty())
                    {
                        temp3=S1.top();
                        S1.pop();
                        S2.push(temp3);
                    }
                    cout<<S2.top()<<endl;
                    S2.pop();
                }
                else
                {
                    cout<<"ERROR:Empty"<<endl;
                }   
            }   
        }
    }
    return 0;
}