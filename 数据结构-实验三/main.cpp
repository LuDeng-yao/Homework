#include <iostream>
#include<cassert>
#define Assert(a,b) assert((a)&&(b))

using namespace std;


//Calculate the greatest common divisor using Euclidean Algorithm
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    return b==0?a:gcd(b,a%b);
}

//Rational class
class Rational{

    //operators override
    friend bool operator<(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D<r2.N*r1.D) return true;
        else return false;
    }
    friend bool operator<=(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D<=r2.N*r1.D) return true;
        else return false;
    }
    friend bool operator>(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D>r2.N*r1.D) return true;
        else return false;
    }
    friend bool operator>=(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D>=r2.N*r1.D) return true;
        else return false;
    }
    friend bool operator==(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D==r2.N*r1.D) return true;
        else return false;
    }
    friend bool operator!=(const Rational& r1, const Rational& r2)
    {
        if(r1.N*r2.D!=r2.N*r1.D) return true;
        else return false;
    }

public:
   int N; //Numerator
   int D; //Denominator, must be greater than 0

   Rational()    //default constructor
   {
       N=0;
       D=1;
   }
   Rational(int n)  //constructor for integer value
   {
       N=n;
       D=1;
   }
   Rational(int n, int d)   //normal constructor
   {
       Assert(d>0,"Denominator must be greater than 0");
       N=n;
       D=d;
   }
   Rational(const Rational& r)   //copy constructor
   {
       N=r.N;
       D=r.D;
   }
   Rational& operator=(const Rational& r)    // assignment override
   {
       N=r.N;
       D=r.D;
   }

   //Print the rational in the correct form
   void printR()
   {
       if(D==1||N==0)
       {
           cout<<N;
       }
       else if(gcd(N,D)!=1)
       {
           int g=gcd(N,D);
           if(D/g==1) cout<<N/g;
           else cout<<N/g<<"/"<<D/g;
       }
       else
       {
           cout<<N<<"/"<<D;
       }
   }
};


//Swap two rationals value
void swap(Rational* r,int i,int j)
{
   Rational temp;
   temp=r[i];
   r[i]=r[j];
   r[j]=temp;
}


//Min heap class
template <typename E> class minheap
{
private:
    E* minHeap;             //Pointer to the min heap array
    int maxsize;            //Maximum size of the min heap
    int n;                  //Number of elements now in the min heap

    //Helper function to put element down to its correct place
    void siftdown(int pos)
    {
        while(!isLeaf(pos))                         //Stop if pos is a leaf
        {
            int j=leftchild(pos);
            int rc=rightchild(pos);
            if((rc<n)&&(minHeap[rc]<minHeap[j]))
                j=rc;                               //Set j to greater child's value
            if(minHeap[pos]<minHeap[j]) return;     //Done
            swap(minHeap,pos,j);
            pos=j;                                  //Move down
        }
    }

    //Helper function to put element up to its correct place
    void siftup(int pos)
    {
        while(pos)
        {
            int p=parent(pos);
            if(minHeap[p]<minHeap[pos]) return;
            if(minHeap[p]>minHeap[pos])
            {
                swap(minHeap,pos,p);
                pos=p;
            }
        }
    }

public:
    minheap(E* h,int ms,int num)            //Constructor
    {
        minHeap=h;
        n=num;
        maxsize=ms;
        buildHeap();
    }
    int heapSize() const                    //Return current min heap size
    {
        return n;
    }
    bool isLeaf(int pos) const              //True if pos id a leaf
    {
        return (pos>=n/2)&&(pos<n);
    }
    int leftchild(int pos) const            //Return leftchild position
    {
        return 2*pos+1;
    }
    int rightchild(int pos) const           //Return rightchild position
    {
        return 2*pos+2;
    }
    int parent(int pos) const               //Return parent position
    {
        return (pos-1)/2;
    }
    void buildHeap()                        //Heapify contents of min heap
    {
        for(int i=n/2-1;i>=0;i--)
            siftdown(i);
    }


    //Insert "it" into the min heap
    void insert(const E& it)
    {
        Assert(n<maxsize,"Heap is full");
        int curr=n++;
        minHeap[curr]=it;
        while((curr!=0)&&(minHeap[curr]<minHeap[parent(curr)]))
        {
            swap(minHeap,curr,parent[curr]);
            curr=parent[curr];
        }
    }

    //Remove first value
    E removefirst()
    {
        Assert(n>0,"Heap is empty");
        swap(minHeap,0,--n);
        if(n!=0) siftdown(0);
        return minHeap[n];
    }

    //Return and remove element at specific position
    E remove(int pos)
    {
        Assert((pos>=0)&&(pos<n),"Bad position");
        if(pos==(n-1)) n--;
        else
        {
            swap(minHeap,pos,--n);
            while((pos!=0)&&(minHeap[pos]<minHeap[parent(pos)]))
            {
                swap(minHeap,pos,parent[pos]);
                pos=parent[pos];
            }
            if(n!=0) siftdown(pos);
        }
        return minHeap[n];
    }

    //Print elements in the min heap in heap order
    void printRMH() const
    {
        for(int i=0;i<n;i++)
        {
            minHeap[i].printR();
            cout<<"  ";
        }
        cout<<endl;
    }


};

//Print elements in the min heap in sorted order
void printSortRMH(minheap<Rational> sortmh)
{
    while(sortmh.heapSize())
    {
        sortmh.removefirst().printR();
        cout<<"  ";
    }
    cout<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;
    Rational rationals[100];
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        Rational r(n,d);
        rationals[i]=r;
    }
    minheap<Rational> mh(rationals,100,t);
    mh.printRMH();
    printSortRMH(mh);
    return 0;
}
