#include<iostream>
#include<stdio.h>
using namespace std;
//双链表结点的实现
template <typename E> class Link{
private:
    static Link<E>* freelist;
public:
    E element1;
    E element2;
    Link*next;
    Link*prev;
    Link(const E&a,const E&b,Link*prevp,Link*nextp)
    {
        element1=a;
        element2=b;
        prev=prevp;
        next=nextp;
    }
    Link(Link*prevp=NULL,Link*nextp=NULL)
    {
        prev=prevp;
        next=nextp;
    }
    void*operator new (size_t)
    {
        if(freelist==NULL) return::new Link;
        Link<E>*temp=freelist;
        freelist=freelist->next;
        return temp;
    }
    void operator delete(void*ptr)
    {
        ((Link<E>*)ptr)->next=freelist;
        freelist=(Link<E>*)ptr;
    }
};
template <typename E>
Link<E>* Link<E>::freelist = NULL;

//双链表的基本操作实现
template <typename E> class LList
{
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt; // length
    void init()
    {
        head=tail=NULL;
        cnt=0;
    }
    void removeall()
    {
        while(head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList() { init(); } // Constructor
    ~LList() { removeall(); } // Destructor
    void clear() { removeall(); init(); }
    E remove()
    {
        if (curr->next == tail)
            return NULL;
        E it= curr->next->element;
        Link<E>* ltemp = curr->next;
        curr->next->next->prev = curr;
        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
        return it;
    }
    void change(const E& it1,const E&it2)
    {
        curr->element1=it1;
        curr->element2=it2;
    }
    void moveToStart()      { curr = head; }
    void moveToEnd()        { curr = tail; }
    void next() { if (curr != tail) curr = curr->next; }
    int length() const { return cnt; }
    int currPos() const
    {
        if(cnt==0||curr==NULL) return 0;
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
        temp = temp->next;
        return i;
    }
    void moveToPos(int pos) {

        curr = head;
        for(int i=0; i<pos; i++)
        curr = curr->next;
    }
    const E& getValue1() const {
        return curr->element1;
    }
    const E& getValue2() const {
        return curr->element2;
    }
    void previous() {
        if (curr != head)
        curr = curr->prev;
    }
    void append(const E&it1,const E&it2)
    {
        if(cnt==0)
        {
            Link<E> *temp=new Link<E>(it1,it2,NULL,NULL);
            curr=temp;
            head = temp;
            tail = temp;
            cnt++;
        }
        else
        {
            Link<E> *temp=new Link<E>(it1,it2,tail,NULL);
			tail->next=temp;
			tail=temp;
			cnt++;
			curr=tail;
        }
    }
    void insert(const E& it1,const E& it2)
    {
        curr->next=curr->next->prev=new Link<E>(it1,it2,curr,curr->next);
        cnt++;
    }
};

int main()
{
    int num1,num2;
	LList<int> L1;
	LList<int> L2;
	LList<int> La;
	LList<int> Lb;
	//printf("Please enter the number of terms of the polynomial: ");
	scanf("%d %d",&num1,&num2);
	//printf("Please input the first polynomials: ");
	for(int i=0;i<num1;i++)
    {
		int coef;//系数
		int expo;//指数
		scanf("%d %d",&coef,&expo);
		L1.append(coef,expo);
	}
	for(int i=0;i<num2;i++)
    {
		int coef;//系数
		int expo;//指数
		scanf("%d %d",&coef,&expo);
		L2.append(coef,expo);
	}
	int p1=num1;
	int p2=num2;

    //add
	L1.moveToStart();
	L2.moveToStart();
	while(num1+num2)
    {
        if(!num1)
        {
            La.append(L2.getValue1(),L2.getValue2());
            --num2;
            if(num2)
                L2.next();
        }
        else if(!num2)
        {
            La.append(L1.getValue1(),L1.getValue2());
            --num1;
            if(num1)
                L1.next();
        }
        else if(L1.getValue2()<L2.getValue2())
        {
            La.append(L2.getValue1(),L2.getValue2());
            --num2;
            if(num2)
                L2.next();
        }
		else if(L1.getValue2()==L2.getValue2())
        {
            La.append(L1.getValue1()+L2.getValue1(),L1.getValue2());
            --num1;
            --num2;
            if(num1&&num2)
            {
                L1.next();
                L2.next();
            }
            else if(num1)
                L1.next();
            else if(num2)
                L2.next();
        }
        else if(L1.getValue2()>L2.getValue2())
        {
            La.append(L1.getValue1(),L1.getValue2());
            --num1;
            if(num1)
                L1.next();
        }

	}
	La.moveToStart();
    printf("%d\n",La.length());
	for (int i=0;i<La.length();i++)
	{
		printf("%d %d\n",La.getValue1(),La.getValue2());
		La.next();
	}

	//multiple
	L1.moveToStart();
	L2.moveToStart();
	for(int i=0;i<p1;i++)
    {
        for(int j=0;j<p2;j++)
        {
            int m,n;
            m=L1.getValue1()*L2.getValue1();
            n=L1.getValue2()+L2.getValue2();
            while(1)
            {
                if(Lb.length()==0)
                {
                    Lb.append(m,n);
                    L2.next();
                    Lb.moveToStart();
                    break;
                }
                else if(Lb.getValue2()==n)
                {
                    int w=Lb.getValue1()+m;
                    Lb.change(w,n);
                    L2.next();
                    Lb.moveToStart();
                    break;
                }
                else if(Lb.getValue2()<n)
                {
                    int c=Lb.getValue1();
                    int d=Lb.getValue2();
                    Lb.change(m,n);
                    Lb.insert(c,d);
                    L2.next();
                    Lb.moveToStart();
                    break;
                }
                else if(Lb.getValue2()>n)
                {
                    if(Lb.currPos()+1==Lb.length())
                    {
                        Lb.append(m,n);
                        if(L2.currPos()+1!=L2.length()) L2.next();
                        Lb.moveToStart();
                        break;
                    }
                    else    Lb.next();
                }
           }
        }
        L1.next();
        L2.moveToStart();
    }
    Lb.moveToStart();
    printf("%d\n",Lb.length());
	for (int i=0;i<Lb.length();i++)
	{
		printf("%d %d\n",Lb.getValue1(),Lb.getValue2());
		Lb.next();
	}
    return 0;
}

