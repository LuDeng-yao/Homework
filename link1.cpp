#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct
{
      int id;

} pep;
typedef struct node
{
     pep data;
     struct node *next;
} list;


bool init (list** L,int sum)
{
    list *p1,*p2;
    int i=1;
    if(sum<=1)
    {
        printf("error");
        return false;
    }
    (*L)=(list *)malloc(sizeof(list));
    (*L)->data.id=1;

    p2=(*L);
    (*L)->next=0;
    while(i<sum)
    {
        p1=(list *)malloc(sizeof(list));
        p2->next=p1;
        p1->data.id=i+1;
        p2=p1;
        i++;
    }
    p2->next=(*L);
    return true;
}
int find(list* L,int sum,int num)
{
    list* a=L,*b=L->next;
    int k;
    for(k=num-2;k>0;k--,a=a->next,b=b->next);
        a->next=b->next;
        b=b->next;
        sum--;
    while(sum!=1)
    {
        for(k=num-1;k>0;k--,a=a->next,b=b->next);
        a->next=b->next;
        b=b->next;
        sum--;
    }
    return b->data.id;
}
int main()
{
   list* head;
   int sum;
   int n;
   printf("Enter the sum of peple: \n");
   scanf("%d",&sum);
   if((init(&head,sum)==false))
    return 0;
   printf("Enter the number they count:\n");
   scanf("%d",&n);
   if(n<=1)
   {
       printf("error");
       return 0;
   }
   n=find(head,sum,n);
   printf("%d",n);


return 0;
}
