/*//rational class
class Rational{
friend bool operator<(const Rational&, const Rational&) {}
friend bool operator<=(const Rational&, const Rational&) {}
friend bool operator>(const Rational&, const Rational&) {}
friend bool operator>=(const Rational&, const Rational&) {}
friend bool operator==(const Rational&, const Rational&) {}
friend bool operator!=(const Rational&, const Rational&) {}

public:
   int N; //分子
   int D; //分母， 要求大于0

   Rational() {}  //default constructor
   Rational(int n){} //constructor for integer value
   Rational(int n, int d) {} //normal constructor
   Rational(const Rational& r){} //copy constructor
   Rational& operator=(const Rational& r) {} // assignment override
};

bool operator<(const Rational& r1, const Rational& r2)
{
    int g=lcm(r1.n,r2.n);
    r1.d=(g/r1.n)*r1.d;
    r2.d=(g/r2.n)*r2.d;
    r1.n=g;
    r2.n=g;
    if(r1.d<r2.d)
        return true;
    else
        return false;
}
bool operator<=(const Rational& r1, const Rational& r2)
{
    int g=lcm(r1.n,r2.n);
    r1.d=(g/r1.n)*r1.d;
    r2.d=(g/r2.n)*r2.d;
    r1.n=g;
    r2.n=g;
    if(r1.d<=r2.d)
        return true;
    else
        return false;
}
bool operator>(const Rational& r1, const Rational& r2)
{
    int g=lcm(r1.n,r2.n);
    r1.d=(g/r1.n)*r1.d;
    r2.d=(g/r2.n)*r2.d;
    r1.n=g;
    r2.n=g;
    if(r1.d>r2.d)
        return true;
    else
        return false;
}
bool operator>=(const Rational& r1, const Rational& r2)
{
    int g=lcm(r1.n,r2.n);
    r1.d=(g/r1.n)*r1.d;
    r2.d=(g/r2.n)*r2.d;
    r1.n=g;
    r2.n=g;
    if(r1.d>=r2.d)
        return true;
    else
        return false;
}
bool operator==(const Rational& r1, const Rational& r2)
{
    r1.n=r1.n/gcd(r1.n,r1.d);
    r1.d=r1.d/gcd(r1.n,r1.d);
    r2.n=r2.n/gcd(r2.n,r2.d);
    r2.d=r2.d/gcd(r2.n,r2.d);
    if(r1.n==r2.n&&r1.d==r2.d)
        return true;
    else
        return false;
}
bool operator!=(const Rational& r1, const Rational& r2)
{
    r1.n=r1.n/gcd(r1.n,r1.d);
    r1.d=r1.d/gcd(r1.n,r1.d);
    r2.n=r2.n/gcd(r2.n,r2.d);
    r2.d=r2.d/gcd(r2.n,r2.d);
    if((r1.n!=r2.n)||(r1.d!=r2.d))
        return true;
    else
        return false;
}

//有理数规约
int gcd(int n,int m)
{
    if(m==0)
		return n;
	else
		return gcd(m,n%m);
}

//有理数通分
int lcm(int n,int m)
{
    return (n*m)/gcd(n,m);
}*/

#include<iostream>
#include<stdio.h>
#define defaultSize 10
using namespace std;

//最小堆(heap)类定义
template<class E>
class MinHeap {
public:
	MinHeap(int sz = DefaultSize);	//构造函数：建立空堆
	MinHeap(E arr[], int n);		//构造函数：通过一个数组创建堆
	~MinHeap() { delete[] heap; }	//析构函数
	bool insert(const E& x);		//将x插入到最小堆中
	bool removeMin(E& x);			//删除堆顶元素(min value)
	bool isEmpty() const;			//判断堆是否是空
	bool isFull() const;			//判断堆是否已满
	void makeEmpty();				//置空堆
	void output();					//数组元素输出
private:
	E* heap;						//存放最小堆元素的数组
	int currentSize;				//最小堆中当前元素的个数
	int maxHeapSize;				//最小堆最多存放元素个数
	void siftDown(int start, int m);//从start到m下滑调整为最小堆
	void siftUp(int start);			//从start到0上滑调整为最小堆
};

//函数定义
template<class E>
MinHeap<E>::MinHeap(int sz) {
	//方式1建立最小堆，动态创建
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new E[maxHeapSize];
	if (nullptr == heap) {
		std::cerr << "内存分配失败" << std::endl;
		exit(EXIT_FAILURE);
	}
	currentSize = 0;
}

template<class E>
MinHeap<E>::MinHeap(E arr[], int n) {
	//方式2创建最小堆，从已知数组中复制数据，然后调整为最小堆结构
	//函数参数：已知数组数据、数据个数
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new E[maxHeapSize];
	if (nullptr == heap) {
		std::cerr << "内存分配失败" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i ++) {
		heap[i] = arr[i];							//数据copy
	}
	currentSize = n;
	//利用完全二叉树中元素的排列规律，找到最初调整位置，也就是最后的分支节点
	int currentPos = (currentSize - 1) / 2;
	while (currentPos >= 0)	{						//自底向上逐步扩大形成堆
		siftDown(currentPos, currentSize - 1);		//局部调整
		currentPos--;								//向前换一个分支节点
	}
}

template<class E>
void MinHeap<E>::output() {
	//循环输出堆数组元素
	for (int i = 0; i < currentSize; i ++) {
		std::cout << heap[i] << ' ';
	}
}

template<class E>
bool MinHeap<E>::isEmpty() const {
	//判断heap是否是空
	return (0 == currentSize) ? true : false;
}

template<class E>
bool MinHeap<E>::isFull() const {
	//判断heap是否已经满
	return (maxHeapSize == currentSize) ? true : false;
}

template<class E>
void MinHeap<E>::makeEmpty() {
	currentSize = 0;
}

template<class E>
bool MinHeap<E>::insert(const E& x) {
	//共有函数：将x插入到最小堆中
	if (isFull()) {									//判断堆是否已经满
		std::cerr << "Heap Fulled" << std::endl;
		return false;
	}
	heap[currentSize] = x;							//将x元素插入到数组最后
	siftUp(currentSize);
	currentSize++;									//对当前大小增加1
	return true;
}

template<class E>
bool MinHeap<E>::removeMin(E& x) {
	//删除堆顶元素，引用返回
	if (0 == currentSize) {
		std::cout << "Heap Emptyed" << std::endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);					//借助函数对堆再一次调整
	return true;
}

template<class E>
void MinHeap<E>::siftDown(int start, int m) {
	//私有函数：从节点start开始到m为止，自上向下比较，如果子女值小于父节点的值，
	//则关键码小的上浮，继续向下层比较，这样将一个集合的局部调整为最小堆
	int i = start;
	int j = 2 * i + 1;								//通过公式2x+1求得x左子女位置
	E temp = heap[i];								//temp记录原来的的数据
	while (j <= m) {
		if (j < m && heap[j] > heap[j + 1]) {
			j = j + 1;								//j指向左右子女中较小的一个
		}
		if (heap[j] >= temp) {
			break;									//已经符合最小堆的结构，无需调整
		}
		else {										//否则调整，并更新i，j至下一层
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	heap[i] = temp;									//完成调整后的数据交换
}

template<class E>
void MinHeap<E>::siftUp(int start) {
	//私有函数：从节点start开始到节点0为止，自下向上比较，如果子女的值小于父节点的值
	//则相互交换，这样讲集合重新调整为最小堆(注意比较元素E的逻辑运算符重载)
	int j = start;
	int i = (j - 1) / 2;								//找左子女公式的逆运算公式
	E temp = heap[j];
	while (j > 0) {
		if (heap[i] <= temp) {
			break;
		}
		else {
			heap[j] = heap[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	heap[j] = temp;
}
class Rational
{
    public:
	Rational(int,int);
	Rational(int);
	Rational();

	bool operator =(const Rational&);

	friend void change(Rational&);
	friend bool operator ==(Rational&,Rational&);
	friend bool operator >=(Rational&,Rational&);
	friend bool operator <=(Rational&,Rational&);
	friend bool operator >(Rational&,Rational&);
    friend bool operator <(Rational&,Rational&);
	friend bool operator!=(Rational&,Rational&);
	friend 	int gcd(int,int);
private:
	bool check(int);
	int N;  //分子
	int D;  //分母
};
bool Rational::check(int the_D)
{
	if(the_D==0)
		return false;
	else
		return true;
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
void change(Rational& a)
{
	if(a.D<0)
	{
		a.D*=-1;
		a.N*=-1;
	}
}
Rational::Rational(int the_N,int the_D)
{
	int temp_gcd;
	bool flag;
	flag=check(the_D);
	if(flag==false)
	{
		exit(1);
	}
	temp_gcd=gcd(the_N,the_D);
    N=the_N/temp_gcd;
	D=the_D/temp_gcd;

}
bool operator ==(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.D==b.D && a.N==b.N)
		return true;
	else
		return false;
}
bool operator !=(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.D!=b.D|| a.N!=b.N)
		return true;
	else
		return false;
}
bool operator >=(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.N*b.D>=b.N*a.D)
		return true;
	else
		return false;
}
bool operator <=(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.N*b.D<=b.N*a.D)
		return true;
	else
		return false;
}
bool operator >(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.N*b.D>a.D*b.N)
		return true;
	else
		return false;
}
bool operator <(Rational& a,Rational& b)
{
	change(a);
	change(b);
	if(a.N*b.D<a.D*b.N)
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

/*
//Binary tree node abstract class
template <typename E> class BinNode {
public:
    virtual ~BinNode() {}   //base destructor
    virtual E&element()=0;
    virtual void setElement(const E&)=0;
    virtual BinNode* left() const=0;
    virtual void setLeft(BinNode*)=0;
    virtual BinNode*right() const=0;
    virtual void setRight(BinNode*)=0;
    virtual bool isLeaf()=0;
};

//Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E>{
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;

public:
    //Two constructors -- with and without initial values
    BSTNode() {lc=rc=NULL;}
    BSTNode(Key K,E e,BSTNode*l=NULL,BSTNode*r=NULL)
        {   k=K; it=e;lc=l;rc=r;        }
    ~BSTNode() {}

    E& element() {return it;}
    void setElement(const E& e) {it=e;}
    Key& key() {return k;}
    void setKey(const Key& K) {k=K;}

    inline BSTNode* left() const {return lc;}
    void setLeft(BinNode<E>* b) {lc=(BSTNode*)b;}
    inline BSTNode* right() const {return rc;}
    void setRight(BinNode<E>* b) {rc=(BSTNode*)b;}

    bool isLeaf() {return (lc==NULL) && (rc==NULL);}
};
*/
