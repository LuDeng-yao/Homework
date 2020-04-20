#include<iostream>
#include<stdio.h>
#define defaultSize 100
using namespace std;

//Abstract queue class
template <typename E> class Queue{
private:
    void operator = (const Queue&) {}   //protect assignment
    Queue (const Queue&) {} //protect copy constructor

public:
    Queue() {}  //default
    virtual ~Queue(){}  //base destructor

    virtual void clear()=0;
    virtual void enqueue(const E&) = 0;
    virtual E dequeue ()=0;
    virtual const E& frontValue() const=0;
    virtual const E& lastValue() const=0;
    virtual const E& nValue() const=0;
    virtual int length() const=0;
};

//Array-based queue implementation
template <typename E> class AQueue{
private:
    int maxSize;
    int front;
    int rear;       //index of rear element
    int value;
    E *listArray;

public:
    AQueue (int size=defaultSize) {
    maxSize=size+1;
    rear=0; front =1;
    listArray=new E[maxSize];
    }

    ~AQueue()   {delete [] listArray; }
    void clear() {rear=0; front=1;}
    void enqueue(const E&it){
        if (((rear+2)%maxSize)==front)
            cout<<"1 Queue is full"<<endl;
        else
        {
            rear =(rear+1)%maxSize;
            listArray[rear]=it;
        }
    }
    E dequeue(){
        if (length()==0)
            cout<<"2 Queue is empty"<<endl;
        else{
            E it =listArray[front];
            front =(front+1)%maxSize;
            return it;
        }
    }
    const E& frontValue() const {
       if(length()==0)
        cout<<"3 Queue is empty"<<endl;
       else
        return listArray[front];
    }
    virtual int length() const
    {
        return ((rear+maxSize)-front+1)%maxSize;
    }
    const E& lastValue() const {
        if(length()==0)
            cout<<"4 Queue is empty"<<endl;
        else
            return listArray[((rear+maxSize)-front+1)%maxSize];
    }
    const E& nValue(int value) const {
       if(length()==0)
        cout<<"5 Queue is empty"<<endl;
       else
        return listArray[value%maxSize];
    }
};

template <typename E> class Stack
{
private:
    void operator = (const Stack&) {}   //protect assignment
    Stack (const Stack&) {} //protect copy constructor
public:
    Stack() {}  //default
    virtual ~Stack(){}  //base destructor

    virtual void clear()=0;
    virtual void push(const E&it) = 0;
    virtual E pop ()=0;
    virtual const E& topValue() const=0;
    virtual const E& nValue() const=0;
    virtual int length() const=0;
};

template <typename E>
class QStack {
   private:
    int maxSize; //栈的容量
    AQueue<E> QA;
    AQueue<E> QB; //基于数组实现的队列
   public:
     QStack(int size = defaultSize): QA(size), QB(size) //初始化队列
     {
        maxSize = size;
     }
     ~QStack() { }
    //完成下列函数的代码
     //virtual void clear()=0;
     void clear()
     {
         QA.clear();
         QB.clear();
     }
     //virtual void push()=0;
     void push(const E& it)
     {
        if(QA.length()==0&&QB.length()==0)
            QA.enqueue(it);
        else if(QA.length()!=0)
            QA.enqueue(it);
        else if(QB.length()!=0)
            QB.enqueue(it);
     }
     //virtual E pop() {}=0;
     E pop()
     {
        if(QA.length()==0&&QB.length()==0)
            cout<<"6 Queue is empty"<<endl;
        else if(QA.length()==0)
        {
            while(QB.length()>1)
            {
                QA.enqueue(QB.dequeue());
            }
            return QB.dequeue();
        }
        else if(QB.length()==0)
        {
            while(QA.length()>1)
            {
                QB.enqueue(QA.dequeue());
            }
            return QA.dequeue();
        }
     }
     //virtual int length() const {  }=0;
     int length()
     {
        if(QB.length()==0&&QA.length()==0)
            return 0;
        else if(QA.length()!=0)
            return QA.length();
        else if(QB.length()!=0)
            return QB.length();
     }
     //virtual const E& topValue() const {}=0;
     const E& topValue()
     {
        if(QB.length()==0&&QA.length()==0)
            cout<<"7 Queue is empty"<<endl;
        else if(QA.length()!=0)
            return QA.lastValue();
        else if(QB.length()!=0)
            return QB.lastValue();
     }
     const E& nValue(int value)
     {
        if(QB.length()==0&&QA.length()==0)
            cout<<"8 Queue is empty"<<endl;
        else if(QA.length()!=0)
            return QA.nValue(value);
        else if(QB.length()!=0)
            return QB.nValue(value);
     }
};

int order(int *a,int n,int k)
{
    int curr=0;
    QStack <int> QS(k);
    for(int v=0;v<k;v++)        //先将QS里压入k个值
    {
        QS.push(++curr);
    }
    int s=0;    //a[s],输入的出栈顺序
    int t=1;    //QS.nValue(t)
    for(t=1;t<=k;t++)       //确定第一次比较时t的值
    {
        if(QS.nValue(t)==a[s])
            break;
    }
    //cout<<"* "<<t<<endl;
    int b[n]; //存入已弹出元素，避免重复弹入
    int h=0;    //b[h]
    while(s<n)
    {
        if(QS.length()==0)
            break;
        //cout<<a[s]<<"&"<<QS.nValue(t)<<endl;
        if(QS.length()==1&&s==4)
        {
            if(QS.nValue(t+1)==a[s])
                break;
            else
            {
                cout<<"F"<<endl;
                return 0;
            }
        }
        else if(a[s]==QS.nValue(t))
        {
            //cout<<"11"<<QS.length()<<endl;
            int g=QS.length();
            for(int v=0;v<=curr-a[s]&&v<g;v++)
            {
                QS.pop();
                //cout<<"$"<<QS.length()<<endl;
            }
            b[h++]=a[s];
            //cout<<a[s]<<"a[s]"<<endl;
            int m=0;
            for(int w=a[s]+1;w<=curr+1&&w<=n;w++)
            {   //如果不是B里的元素则push
                for(int q=0;q<h;q++)
                {
                    if(w==b[q])
                        m=1;
                }
                if(m==0)
                {
                    QS.push(w);
                    //cout<<w<<" "<<QS.length()<<endl;
                }
            }
            //cout<<QS.nValue(QS.length())<<endl;
            if(curr<n)
                curr++;
            //cout<<curr<<"*"<<t<<endl;
            s++;
            //cout<<s<<endl;
            if(t>QS.length())
                t=QS.length();
        }
        else if(t!=1&&a[s]==QS.nValue(t-1))
        {
            //cout<<"22"<<t<<"#"<<curr<<endl;
            int g=QS.length();
            for(int v=0;v<curr-a[s]&&v<g;v++)
                QS.pop();
            b[h++]=a[s];
            int m=0;
            for(int w=a[s]+1;w<=curr+1&&w<n;w++)
            {   //如果不是B里的元素则push
                for(int q=0;q<h;q++)
                {
                    if(w==b[q])
                        m=1;
                }
                if(m==0&&curr<n)
                    QS.push(w);
            }
            if(curr<n)
                curr++;
            s++;
            t=t-1;
        }
        else if((QS.length()<=k)&&a[s]==QS.nValue(QS.length()))
        {
            //cout<<"33"<<endl;
            b[h++]=QS.pop();
            if(curr<=n)
                QS.push(++curr);
            s++;
            t=k-1;
            if(t>QS.length())
                t=QS.length();
        }
        else
        {
            cout<<"F"<<endl;
            return 0;
        }
    }
    cout<<"T"<<endl;
    curr=0;
    QS.clear();
    return 0;
}
int main()
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=0;i<m;i++)
    {
        int a[n];
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        order(a,n,k);
    }
    return 0;
}

/*
int main()
{
    return 0;
}*/

