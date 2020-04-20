#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;

struct node
{
    node *l,*r,*f;
    int data;
};
int a[10001];
map<int,int>mp;
node *create(int l,int r)
{
    if(l>r)
        return NULL;
    node *root=new node;
    root->data=a[l];
    root->f=NULL;
    root->l=root->r=NULL;
    int i;
    for(i=l+1; i<=r; i++)//根据二叉搜索树的性质建树，第一个大于等于根节点的包括其后面的肯定在右子树，其他在左子树
    {
        if(a[i]>=a[l])
            break;
    }
    root->l=create(l+1,i-1);
    if(root->l)//要特判是否为空
        root->l->f=root;//标记father节点
    root->r=create(i,r);
    if(root->r)
        root->r->f=root;
    return root;
}
int Find(node *root,int x)//在以root为根的子树中是否查找到x
{
    if(root)
    {
        if(root->data==x)
            return 1;
        if(x<root->data)
            return Find(root->l,x);
        else
            return Find(root->r,x);
    }
    return 0;
}
 
int Find_F(node *root,int u,int v)//u是否是v的祖先
{
    if(root)
    {
        if(root->data==u)
        {
            if(Find(root,v))//如果在u的子树中找到了v，即说明u是v的祖先
                return 1;
            return 0;
        }
        if(u<root->data)
            return Find_F(root->l,u,v);
        else
            return Find_F(root->r,u,v);
    }
    return 0;
 
}
int Find_LCA(node *root,int x)//从第一个节点的地址向上找第二个节点的祖先
{
    while(root->f)
    {
        root=root->f;
        int r=Find(root,x);
        if(r)       //若找到。返回对应祖先节点值
            return root->data;
    }
    return 0;
}
node *Find_POS(node *root,int x)//找到一个节点的位置，返回的是一个指针
{
    if(root)
    {
        if(root->data==x)
            return root;
        if(x<root->data)
            return Find_POS(root->l,x);
        else
            return Find_POS(root->r,x);
    }
    return NULL;
}
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    node *root=NULL;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;//将其标记，看是否在树上
    }
    root=create(1,m);
    for(int i=1; i<=n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(!mp[u]&&!mp[v])
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(!mp[u])
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(!mp[v])
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        else
        {
            int x=Find_F(root,u,v);
            int y=Find_F(root,v,u);
            if(x)
                cout<<u<<" is an ancestor of "<<v<<"."<<endl;
            else if(y)
                cout<<v<<" is an ancestor of "<<u<<"."<<endl;
            else
            {
                node *temp=Find_POS(root,u);
                int r=Find_LCA(temp,v);
                cout<<"LCA of "<<u<<" and "<<v<<" "<<"is"<<" "<<r<<"."<<endl;
            }
 
        }
    }
    return 0;
}