#ifndef LAB_H_INCLUDED
#define LAB_H_INCLUDED

#define idlen 11
#define keylen 6

typedef  struct accountinfo
{
    char id[idlen+1];
    char password[keylen+1];
    float  deposit;
    int use;    //1,normal;2,delete;3,frozen;
}info;

typedef struct node
{
    info data;
    struct node *next;
}llist,*llistp;


#endif // LAB_H_INCLUDED
