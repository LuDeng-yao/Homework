#include <iostream>
#include <string>
#include <vector>
#include<string.h>

using namespace std;

template<typename E>
void swap(E A[],int i,int j)
{
    E temp = A [i];
    A [i] = A [j];
    A [j] = temp;
}


template<typename E>
void showArray(E* array,int size){
    for(int i=0;i<size;i++){
        if(array[i].D==1)
            cout<<array[i].N<<"  ";
        else
            cout<<array[i].N<<"/"<<array[i].D<<"  ";
    }
    cout<<endl;
}


void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}


// Heap class
template <typename E, typename Comp> class heap {
private:
    E* Heap;          // Pointer to the heap array
    int maxsize;         // Maximum size of the heap
    int n;               // Number of elements now in the heap

    // Helper function to put element in its correct place
    void siftdown(int pos) {
        while (!isLeaf(pos)) { // Stop if pos is a leaf
            int j = leftchild(pos);  int rc = rightchild(pos);
            if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
                j = rc;            // Set j to greater child's value
            if (Comp::prior(Heap[pos], Heap[j])) return; // Done
            swap(Heap, pos, j);
            pos = j;             // Move down
        }
    }

public:
    heap(E* h, int num, int max)     // Constructor
    { Heap = h;  n = num;  maxsize = max;  buildHeap(); }
    int size() const       // Return current heap size
    { return n; }
    bool isLeaf(int pos) const // True if pos is a leaf
    { return (pos >= n/2) && (pos < n); }
    int leftchild(int pos) const
    { return 2*pos + 1; }    // Return leftchild position
    int rightchild(int pos) const
    { return 2*pos + 2; }    // Return rightchild position
    int parent(int pos) const  // Return parent position
    { return (pos-1)/2; }
    void buildHeap()           // Heapify contents of Heap
    { for (int i=n/2-1; i>=0; i--) siftdown(i); }

    // Insert "it" into the heap
    void insert(const E& it) {
        Assert(n < maxsize, "Heap is full");
        int curr = n++;
        Heap[curr] = it;            // Start at end of heap
        // Now sift up until curr's parent > curr
        while ((curr!=0) &&
               (Comp::prior(Heap[curr], Heap[parent(curr)]))) {
            swap(Heap, curr, parent(curr));
            curr = parent(curr);
        }
    }
    // Remove first value
    E removefirst() {
        Assert (n > 0, "Heap is empty");
        swap(Heap, 0, --n);       // Swap first with last value
        if (n != 0) siftdown(0);  // Siftdown new root val
        //        cout<<endl;
        //        cout<<"        ";
        //        for(int i =0;i<n-1;i++){
        //            cout<<Heap[i].D/(double)Heap[i].N<<" ";
        //        }
        //        cout<<endl;
        return Heap[n];             // Return deleted value
    }

    // Remove and return element at specified position
    E remove(int pos) {
        Assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n-1)) n--; // Last element, no work to do
        else
        {
            swap(Heap, pos, --n);          // Swap with last value
            while ((pos != 0) &&
                   (Comp::prior(Heap[pos], Heap[parent(pos)]))) {
                swap(Heap, pos, parent(pos)); // Push up large key
                pos = parent(pos);
            }
            if (n != 0) siftdown(pos);     // Push down small key
        }
        return Heap[n];
    }

    void display(){
        //cout<<endl<<"heap is: ";
        showArray<E>(Heap,n);
    }

    void show(){
        for(int i=0;i<n;i++){
            cout<<Heap[i]<<" ";
        }
        cout<<endl;
    }


};


class Rational{
    friend bool operator<(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first<second;
    }
    friend bool operator<=(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first<=second;
    }
    friend bool operator>(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first>second;
    }
    friend bool operator>=(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first>=second;
    }
    friend bool operator==(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first==second;
    }
    friend bool operator!=(const Rational& r1, const Rational& r2) {
        double first,second;
        first=r1.N/(double)r1.D;
        second=r2.N/(double)r2.D;
        return first!=second;
    }

public:
    int N; //分子
    int D; //分母， 要求大于0

    void reduce(int &N,int &D){
        int min;
        if(N<D)
            min=N;
        else
            min=D;

        for(int i=1;i<=min;i++){
            if(N%i==0 && D%i==0)
            {N=N/i;D=D/i;}
        }

    }

    Rational() {
        N=0;D=1;
        reduce(N,D);
    }  //default constructor
    Rational(int n){
        N=n;D=1;
        reduce(N,D);
    } //constructor for integer value
    Rational(int n, int d) {
        N=n;D=d;
        reduce(N,D);
    } //normal constructor
    Rational(const Rational& r){
        N=r.N;
        D=r.D;
        reduce(N,D);
    } //copy constructor

    void assign(int n,int d){
        N=n;D=d;
        reduce(N,D);
    }
    Rational& operator=(const Rational& r) {
        N=r.N;
        D=r.D;
        reduce(N,D);
        return *this;
    } // assignment override

};

class maxIntCompare {
public:
    static bool prior(Rational x, Rational y) { return x>y; }
};

class minIntCompare {
public:
    static bool prior(Rational x, Rational y) { return x<y; }
};
// Standard heapsort implementation
template <typename E>
void heapsort(E A[], int n) { // Heapsort
    E maxval;
    heap<E,minIntCompare> H1(A, n, n);    // Build the heap
    H1.display();//heap is
    heap<E,maxIntCompare> H2(A, n, n);    // Build the heap
    for (int i=0; i<n; i++)        // Now sort
    {
        maxval = H2.removefirst();    // Place maxval at end
        //cout<<"maxval is:"<<maxval.N/(double)maxval.D<<"   ";
    }
    //排序结果存放在原本的heap数组中 按照升序排列
    //cout<<endl<<"sorted array is:";
    showArray(A, n);
}
int main(int argc, const char * argv[]) {
    int numofR;
    //cout<<"num of R is";
    cin>>numofR;
    Rational Rarr[numofR];
    int N,D;//N是分子，D是分母
    for(int i=0;i<numofR;i++){
        cin>>N;
        cin>>D;
        Rarr[i].assign(N, D);
    }

    heapsort<Rational>(Rarr, numofR);
}
