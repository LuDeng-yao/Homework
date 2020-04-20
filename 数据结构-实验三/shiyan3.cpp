#include<iostream>
#include<stdio.h>
using namespace std;

template<typename E>
void swap(E A[],int i,int j)
{
    E temp = A [i];
    A [i] = A [j];
    A [j] = temp;
}

//Heap class
template <typename E,typename Comp> class heap{
private:
    E* Heap;
    int maxsize;
    int n;
    void siftdown(int pos) {
        while(!isLeaf(pos)) {
            int j=leftchild(pos);
            int rc=rightchild(pos);
            if((rc<n)&& Comp::prior(Heap[rc],Heap[j]))
                j=rc;
            if(Comp::prior(Heap[pos],Heap[j]))  return;
            swap(Heap,pos,j);
            pos=j;
        }
    }
public:
    heap(E*h,int num,int max)
    {   Heap = h;n=num; maxsize=max; buildHeap();    }
    int size() const
    {   return n;    }
    bool isLeaf(int pos) const
    {   return (pos>=n/2)&& (pos<n);    }
    int leftchild(int pos) const
    {   return 2*pos+1;    }
    int rightchild(int pos) const
    {   return 2*pos+2;    }
    int parent(int pos) const
    {   return (pos-1)/2;    }
    void buildHeap()
    {
        for (int i=n/2-1;i>=0;i--)  siftdown(i);
    }

    void insert(const E& it){
        if(n>=maxsize)
            cout<<"Heap is full"<<endl;
        else
        {
            int curr=n++;
            Heap[curr]=it;
            while((curr!=0)&&(Comp::prior(Heap[curr],Heap[parent(curr)])))
            {
                swap(Heap,curr,parent(curr));
                curr=parent(curr);
            }
        }
    }

    E removefirst(){
        if(n<=0)
            cout<<"Heap is empty"<<endl;
        else
        {
            swap(Heap,0,--n);
            if(n!=0)    siftdown(0);
            return Heap[n];
        }
    }

    E remove(int pos)
    {
        if((pos<0)||(pos>n))
            cout<<"Bad position"<<endl;
        else{
            if(pos==(n-1))  n--;
            else{
                swap(Heap,pos,--n);
                while((pos!=0)&&(Comp::prior(Heap[pos],Heap[parent(pos)])))
                {
                    swap(Heap,pos,parent(pos));
                    pos=parent(pos);
                }
                if(n!=0)    siftdown(pos);
            }
        }
        return Heap[n];
    }
};

class Rational
{
    public:
	Rational(int N,int D);
	Rational(int N);
	Rational();
	int N;
	int D;

	bool operator =(const Rational&r);

	friend void change(Rational&r);
	friend bool operator ==(Rational&r1,Rational&r2);
	friend bool operator >=(Rational&r1,Rational&r2);
	friend bool operator <=(Rational&r1,Rational&r2);
	friend bool operator >(Rational&r1,Rational&r2);
    friend bool operator <(Rational&r1,Rational&r2);
	friend bool operator!=(Rational&r1,Rational&r2);
	friend 	int gcd(int d1,int d2);
private:
	bool check(int d);
};
bool Rational::check(int d)
{
	if(d==0)
		return false;
	else
		return true;
}
int gcd(int d1,int d2)
{
	if(d2==0)
		return d1;
	else
		return gcd(d2,d1%d2);
}
void change(Rational& r)
{
	if(r.D<0)
	{
		r.D*=-1;
		r.N*=-1;
	}
}
Rational::Rational()    //default constructor
   {
       N=0;
       D=1;
   }
Rational::Rational(int n)  //constructor for integer value
   {
       N=n;
       D=1;
   }
Rational::Rational(int n,int d)
{
	int temp_gcd;
	bool flag;
	flag=check(d);
	if(flag==false)
	{
		exit(1);
	}
	temp_gcd=gcd(n,d);
    N=n/temp_gcd;
	D=d/temp_gcd;

}
bool operator ==(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.D==r2.D && r1.N==r2.N)
		return true;
	else
		return false;
}
bool operator !=(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.D!=r2.D|| r1.N!=r2.N)
		return true;
	else
		return false;
}
bool operator >=(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.N*r2.D>=r2.N*r1.D)
		return true;
	else
		return false;
}
bool operator <=(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.N*r2.D<=r2.N*r1.D)
		return true;
	else
		return false;
}
bool operator >(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.N*r2.D>r1.D*r2.N)
		return true;
	else
		return false;
}
bool operator <(Rational& r1,Rational& r2)
{
	change(r1);
	change(r2);
	if(r1.N*r2.D<r1.D*r2.N)
		return true;
	else
		return false;
}
bool Rational::operator =(const Rational& temp)
{
	N=temp.N;
	D=temp.D;
	return true;
}
class minIntCompare {
public:
    static bool prior(Rational x, Rational y) { return x<y; }
};
template<typename E>
void output1(E*h,int num)
{
    for(int i=0;i<num;i++)
    {
        if(h[i].D==1)
            cout<<h[i].N<<"  ";
        else
            cout<<h[i].N<<"/"<<h[i].D<<"  ";
    }
    cout<<endl;
}
//template<typename E>
void output2(heap<Rational,minIntCompare> h,int num)
{
    Rational ra2[num+10]={0};
    Rational pairtwo;
    for (int j=0;j<num;j++)
    {
        pairtwo=h.removefirst();
        ra2[j]=pairtwo;
    }
    for (int j=0;j<num;j++)
    {
        if(ra2[j].D==1)
            cout<<ra2[j].N<<"  ";
        else
            cout<<ra2[j].N<<"/"<<ra2[j].D<<"  ";
    }
    cout<<endl;
}

int main()
{
    int num;
    cin>>num;
    Rational ra[num+10]={0};
    for(int i=0;i<num;i++)
    {
        int n,d;
        cin>>n>>d;
        Rational r(n,d);
        ra[i]=r;
    }
    heap<Rational,minIntCompare> h (ra,num,100);
    output1(ra,num);
    output2(h,num);
    return 0;
}





