#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
using namespace std;

typedef struct
{
    int id;
}pep;
typedef struct node
{
    pep data;
    struct node *next;
}LList;

bool init(LList **L,int sum)
{
    LList *p1,*p2;
    int i=1;
    if(sum<=1)
    {
        cout<<"Wrong sum number."<<endl;
        return false;
    }
    (*L)=(LList *)malloc(sizeof(LList));
    (*L)->data.id=1;
    p2=(*L);
    (*L)->next=0;
    while(i<sum)
    {
        p1=(LList *)malloc(sizeof(LList));
        p2->next=p1;
        p1->data.id=i+1;
        p2=p1;
        i++;
    }
    p2->next=(*L);
    return true;
}

int findout(LList *L,int sum,int k)
{
    LList *a=L, *b=L->next;
    while(~sum)
    {
        for(int j=1;j<k-1;j++)
        {
            a=a->next;
            b=b->next;
            sum--;
            if(sum==1)
                return a->data.id;
            //cout<<"a: "<<a->data.id<<endl;
            //cout<<"b: "<<b->data.id<<endl;
        }
        if(sum>1)
        {
            LList *c=b->next;
            a->next=c;
            b=c;
            sum--;
            //cout<<"1"<<endl;
            if(sum==1|sum==0)
                return a->data.id;
            else if(sum==2)
                return b->data.id;
        }
        if(sum==1)
        {
            //cout<<"4"<<endl;
            return a->data.id;
        }
        a=a->next;
        b=b->next;
        sum--;
    }
    //cout<<"K"<<endl;
    return b->data.id;
}

int main()
{
    int sum,k;
    cout<<"Please input the number of the people and the counted number: "<<endl;
    while(scanf("%d %d",&sum,&k))
    {
        LList *head;
        if(init(&head,sum)==false)
            return 0;
        if(k<1)
        {
            cout<<"Counted number is wrong."<<endl;
            return 0;
        }
        cout<<"The last number: "<<findout(head,sum,k)<<endl;
    }
    return 0;
}
