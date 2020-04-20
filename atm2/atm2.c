#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include"lab.h"

llistp head;
llistp u;
int sz;

void read()
{
    head=(llistp)malloc(sizeof(llist));
    head->next=NULL;
    strcpy(head->data.id,"12345678900");
    head->data.password[0]=0;
    u=(llistp)malloc(sizeof(llist));
    u=NULL;
	FILE *f=NULL;

	if((f=fopen("atm_info.txt","r"))==NULL)
	{
		return;
	}
    u=head;
	if(feof(f))
	{
		fclose(f);
		printf("File dose not exist.\n");
		return;
	}
    fscanf(f,"%d",&sz);
	//printf("sz:%d\n",sz);
    for(int i=0;i<sz;i++)
    {
        u->next=(llistp)malloc(sizeof(llist));
        u=u->next;
        fscanf(f,"%s\n%s\n%10f\n%d\n",u->data.id,u->data.password,&u->data.deposit,&u->data.use);
        //printf("%s\n%s\n%.2f\n%d\n",u->data.id,u->data.password,u->data.deposit,u->data.use);
        u->next=NULL;
    }
    fclose(f);
}
void change_password()
{
    printf("Change password:\n");
    char newp[keylen+1];
    char oldp[keylen+1];
    printf("Please input the old password: \n");
    scanf("%s",oldp);
    if(!strcmp(oldp,u->data.password))
    {
        printf("Please input the new password: \n");
        scanf("%s",newp);
        strcpy(u->data.password,newp);
        printf("Change password successfully!\n\n");
    }
    else
        printf("Password is wrong.\nChange password failed.\n\n");
}
void transfer()
{
    printf("Transfer:\n");
    char idv[idlen+1];
    double money;
    llistp v;

    printf("Please input the account number you want to transfer your money to: \n");
    scanf("%s",idv);
    printf("Please input the amount you want to transfer: \n");
    scanf("%lf",&money);

    if(u->data.deposit<money)
    {
        printf("Money is not enough.\n\n");
        return;
    }

    v=head;
    while(v->next!=NULL)
    {
        v=v->next;
        if(!strcmp(idv,v->data.id))
        {
            v->data.deposit +=money;
            u->data.deposit-=money;
            printf("Transfer money successfully!\n\n");
            return;
        }
    }
    printf("The account number was not found.\n\n");
}
void withdraw()
{
    printf("Withdraw: \n");
    double m;
    printf("How much do you want to withdraw:\n");
    scanf("%10f",&m);
    if(u->data.deposit<m)
        printf("Your deposit is not enough.\n\n");
    else
    {
        u->data.deposit-=m;
        printf("withdraw money successful!\n\n");
    }
}
void deposit_money()
{
    printf("Deposit: \n");
    double m;
    printf("How much do you want to save?\n");
    scanf("%lf",&m);
    u->data.deposit+=m;
    printf("Save money successful!\n\n");
}
void print()
{
    printf("Account information:\n");
    printf("ID number: %s\n",u->data.id);
    printf("Money: %.2f\n\n",u->data.deposit);
}
void block()
{
    u->data.use=3;
    printf("Block successfully!\n\n");
    return;
}
void free_account()
{
    u->data.use=2;
    printf("Delete successfully!\n\n");
    return;
}
void menu()
{
    int k=1;
    while(k)
    {
        int ch;
        printf("*************** Menu ***************\n");
        printf("1\tWithdraw money\n2\tDeposit money\n3\tPrint information\n");
        printf("4\tTransfer money\n5\tModify password\n6\texit\n");
        printf("7\tblock account\n8\tdelete account\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:withdraw();
            break;
        case 2:deposit_money();
            break;
        case 3:print();
            break;
        case 4:transfer();
            break;
        case 5:change_password();
            break;
        case 6:k=0;
            break;
        case 7:block();
            break;
        case 8:free_account();
            break;
        default:
            printf("The number you input is wrong.\n");
            printf("Now jump to the initialization page for you.\n\n");
            k=0;
            break;
        }
    }
}
void defrost()
{
    u->data.use=1;
    printf("Defrost successfully!\n\n");
}
void login()
{
    llistp w;
    w=head;
    char id[idlen+1];
    char password[keylen+1];
    int times=3;
    printf("Please input your account number: \n");
    scanf("%s",id);;
    while(w->next!=NULL)
    {
        w=w->next;
        if(strcmp(w->data.id,id)==0)
        {
            if(w->data.use==2)
            {
                printf("The account has been cancelled.\n");
                break;
            }
            else if(w->data.use==3)
            {
                int s;
                printf("The account has been frozen.\n");
                printf("Need to unfreeze this account?\n1\tYes.\n2\tNo.\n");
                scanf("%d",&s);
                if(s)
                    defrost();
                else
                    break;
            }
            while(times>0)
            {
                printf("Please input your password: \n");
                scanf("%s",password);
                if(strcmp(w->data.password,password)==0)
                {
                    u=w;
                    printf("Login successful!\n\n");
                    menu();
                    return;
                }
                else
                {
                    times--;
                    if(times>0)
                    {
                        printf("Wrong account or password.\n\n");
                        printf("You have %d more chance.\n\n",times);
                    }
                    else
                    {
                        printf("Login failed.\n\n");
                        return;
                    }
                }
            }
        }
    }
    printf("The account may not exist.\n\n");
}

void set_new_account()
{
    read();
    char password[keylen+1];
    char check[keylen+1];
    char id[idlen+1];
    llistp p;
    p=(llist *)malloc(sizeof(llist));
    u->next=p;
    p->next=NULL;
    printf("Register: \n");
    strcpy(id,u->data.id);
    for(int j=idlen-1;j>=0;j--)
    {
        if(j==0&& id[j]=='z')
        {
            printf("Account is full. Please contact the manager.\n\n");
            return;
        }
        if((id[j]>='0' && id[j]<'9')||(id[j]<'z' && id[j]>='a'))
        {
            id[j]++;
            break;
        }
        else if(id[j]=='9')
        {
            id[j]='a';
            break;
        }
    }
    strcpy(p->data.id,id);
    printf("Your account number is: \n");
    puts(p->data.id);
    int times=0;
    while(1)
    {
        int flag=1;
        printf("Password setting: \n");
        printf("Please set your password: \n");
        scanf("%s",password);
        printf("Please input(check) your password again: \n");
        scanf("%s",check);
        for(int i=0;i<keylen;i++)
        {
            if(check[i]!=password[i])
                flag=0;
        }
        printf("\n");
        if(flag==1)
            break;
        else
        {
            printf("The password you input these two times are different.\nTry it again.\n");
            times++;
        }
        if(times==5)
        {
            printf("Please try it later.\n\n");
            return;
        }
    }
    strcpy(p->data.password,password);
    p->data.deposit=0;
    p->data.use=1;
    sz++;
    printf("\nNow we will jump to the login interface for you.\n\nLogin:\n");
    u=u->next;
    login();
}
void welcome()
{
    int a;
    printf("*************** WELCOME ***************\n");
    printf("Choose the service you want: \n 1 register \n 2 login\n 3 exit\n");
    scanf("%d",&a);
    if(a==1)
        set_new_account();
    else if(a==2)
        login();
    else
        return;
}

void write()
{
    llistp q;
    FILE *f=fopen("atm_info.txt","w");
    q=head;
    fprintf(f,"%d\n",sz);
    for(int i=0;i<sz;i++)
    {
        q=q->next;
        fprintf(f,"%s\n%s\n%.2f\n%d\n",q->data.id,q->data.password,q->data.deposit,q->data.use);
    }
    fclose(f);
}
int main()
{
    int run=0;
    sz=0;
    read();
    while(!run)
    {
        welcome();
        printf("0\tcontinue\n1\tend\n");
        scanf("%d",&run);
    }
    write();
    return 0;
}
