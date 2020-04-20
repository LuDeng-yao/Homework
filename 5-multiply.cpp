#include<stdio.h>

int main()
{
    int i,sum,legal=0;
    char op='0';
    scanf("%d",&sum);
    while(op!='=')
    {
        scanf("%c",&op);
        switch(op)
        {
        case '=':
            break;
        case '+':
            scanf("%d",&i);
            sum+=i;
        case '-':
            scanf("%d",&i);
            sum-=i;
        case '*':
            scanf("%d",&i);
            sum*=i;
        case '/':
            scanf("%d",&i);
            if(i!=0)
                sum/=i;
            else
            {
                legal=1;
                break;
            }
        default:
            legal=1;
            break;
        }
    }
    //if(legal==0)
        printf("%d\n",sum);
    //else
        printf("Error\n");
    return 0;
}
