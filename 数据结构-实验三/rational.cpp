/*//rational class
class Rational{
friend bool operator<(const Rational&, const Rational&) {}
friend bool operator<=(const Rational&, const Rational&) {}
friend bool operator>(const Rational&, const Rational&) {}
friend bool operator>=(const Rational&, const Rational&) {}
friend bool operator==(const Rational&, const Rational&) {}
friend bool operator!=(const Rational&, const Rational&) {}

public:
   int N; //����
   int D; //��ĸ�� Ҫ�����0

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

//��������Լ
int gcd(int n,int m)
{
    if(m==0)
		return n;
	else
		return gcd(m,n%m);
}

//������ͨ��
int lcm(int n,int m)
{
    return (n*m)/gcd(n,m);
}*/

#include<iostream>
#include<stdio.h>
#define defaultSize 10
using namespace std;

//��С��(heap)�ඨ��
template<class E>
class MinHeap {
public:
	MinHeap(int sz = DefaultSize);	//���캯���������ն�
	MinHeap(E arr[], int n);		//���캯����ͨ��һ�����鴴����
	~MinHeap() { delete[] heap; }	//��������
	bool insert(const E& x);		//��x���뵽��С����
	bool removeMin(E& x);			//ɾ���Ѷ�Ԫ��(min value)
	bool isEmpty() const;			//�ж϶��Ƿ��ǿ�
	bool isFull() const;			//�ж϶��Ƿ�����
	void makeEmpty();				//�ÿն�
	void output();					//����Ԫ�����
private:
	E* heap;						//�����С��Ԫ�ص�����
	int currentSize;				//��С���е�ǰԪ�صĸ���
	int maxHeapSize;				//��С�������Ԫ�ظ���
	void siftDown(int start, int m);//��start��m�»�����Ϊ��С��
	void siftUp(int start);			//��start��0�ϻ�����Ϊ��С��
};

//��������
template<class E>
MinHeap<E>::MinHeap(int sz) {
	//��ʽ1������С�ѣ���̬����
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new E[maxHeapSize];
	if (nullptr == heap) {
		std::cerr << "�ڴ����ʧ��" << std::endl;
		exit(EXIT_FAILURE);
	}
	currentSize = 0;
}

template<class E>
MinHeap<E>::MinHeap(E arr[], int n) {
	//��ʽ2������С�ѣ�����֪�����и������ݣ�Ȼ�����Ϊ��С�ѽṹ
	//������������֪�������ݡ����ݸ���
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new E[maxHeapSize];
	if (nullptr == heap) {
		std::cerr << "�ڴ����ʧ��" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i ++) {
		heap[i] = arr[i];							//����copy
	}
	currentSize = n;
	//������ȫ��������Ԫ�ص����й��ɣ��ҵ��������λ�ã�Ҳ�������ķ�֧�ڵ�
	int currentPos = (currentSize - 1) / 2;
	while (currentPos >= 0)	{						//�Ե������������γɶ�
		siftDown(currentPos, currentSize - 1);		//�ֲ�����
		currentPos--;								//��ǰ��һ����֧�ڵ�
	}
}

template<class E>
void MinHeap<E>::output() {
	//ѭ�����������Ԫ��
	for (int i = 0; i < currentSize; i ++) {
		std::cout << heap[i] << ' ';
	}
}

template<class E>
bool MinHeap<E>::isEmpty() const {
	//�ж�heap�Ƿ��ǿ�
	return (0 == currentSize) ? true : false;
}

template<class E>
bool MinHeap<E>::isFull() const {
	//�ж�heap�Ƿ��Ѿ���
	return (maxHeapSize == currentSize) ? true : false;
}

template<class E>
void MinHeap<E>::makeEmpty() {
	currentSize = 0;
}

template<class E>
bool MinHeap<E>::insert(const E& x) {
	//���к�������x���뵽��С����
	if (isFull()) {									//�ж϶��Ƿ��Ѿ���
		std::cerr << "Heap Fulled" << std::endl;
		return false;
	}
	heap[currentSize] = x;							//��xԪ�ز��뵽�������
	siftUp(currentSize);
	currentSize++;									//�Ե�ǰ��С����1
	return true;
}

template<class E>
bool MinHeap<E>::removeMin(E& x) {
	//ɾ���Ѷ�Ԫ�أ����÷���
	if (0 == currentSize) {
		std::cout << "Heap Emptyed" << std::endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);					//���������Զ���һ�ε���
	return true;
}

template<class E>
void MinHeap<E>::siftDown(int start, int m) {
	//˽�к������ӽڵ�start��ʼ��mΪֹ���������±Ƚϣ������ŮֵС�ڸ��ڵ��ֵ��
	//��ؼ���С���ϸ����������²�Ƚϣ�������һ�����ϵľֲ�����Ϊ��С��
	int i = start;
	int j = 2 * i + 1;								//ͨ����ʽ2x+1���x����Ůλ��
	E temp = heap[i];								//temp��¼ԭ���ĵ�����
	while (j <= m) {
		if (j < m && heap[j] > heap[j + 1]) {
			j = j + 1;								//jָ��������Ů�н�С��һ��
		}
		if (heap[j] >= temp) {
			break;									//�Ѿ�������С�ѵĽṹ���������
		}
		else {										//���������������i��j����һ��
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	heap[i] = temp;									//��ɵ���������ݽ���
}

template<class E>
void MinHeap<E>::siftUp(int start) {
	//˽�к������ӽڵ�start��ʼ���ڵ�0Ϊֹ���������ϱȽϣ������Ů��ֵС�ڸ��ڵ��ֵ
	//���໥�������������������µ���Ϊ��С��(ע��Ƚ�Ԫ��E���߼����������)
	int j = start;
	int i = (j - 1) / 2;								//������Ů��ʽ�������㹫ʽ
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
	int N;  //����
	int D;  //��ĸ
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
