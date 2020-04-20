/*#include <iostream>
#include<stdio.h>
#include<math.h>
#define UNVISITED 0
#define VISITED 1
#define defaultSize 100
using namespace std;
*/
//Graph abstract class.This ADT assumes that the number of vertices is fixed when the graph is created.
class Graph{
private:
    void operator = (const Graph&) {}   //protect assignment
    Graph (const Graph&) {}     //protect copy constructor

public:
    Graph() {}  //default constructor
    virtual ~Graph() {}     //base destructor

    virtual void Init(int n)=0;
    virtual int n()=0;  //the number of vertices and edges
    virtual int e()=0;
    virtual int first(int v)=0;     //return v's first neighbor
    virtual int next(int v,int w)=0;
    //set the weight for an edge
    //i,j: the vertices
    //wgt: Edge weight
    virtual void setEdge(int v1,int v2,int wght)=0;
    virtual void delEdge(int v1,int v2)=0;
    //determine if an edge is in the graph
    virtual bool isEdge(int i,int j)=0;
    virtual int weight(int v1,int v2)=0;
    //get and set the mark value for a vertex
    virtual int getMark(int v)=0;
    virtual void setMark(int v,int val)=0;
};

//Implementation for the adjacency matrix representation
class Graphm: public Graph{
private:
    int numVertex, numEdge;
    int **matrix;   //pointer to adjacency matrix
    int *mark;      //pointer to mark array
public:
    Graphm(int numVert)     {Init (numVert); }
    ~Graphm(){
    delete [] mark;
    for (int i=0;i<numVertex;i++)
        delete [] matrix[i];
    delete [] matrix;
    }
    void Init(int n){
        int i;
        numVertex=n;
        numEdge=0;
        mark=new int[n];
        for(i=0;i<numVertex;i++)
            mark[i]=UNVISITED;
        matrix=(int**) new int*[numVertex];
        for(i=0;i<numVertex;i++)
            matrix[i]=new int[numVertex];
        for(i=0;i<numVertex;i++)
            for(int j=0;j<numVertex;j++)
                matrix[i][j]=0;
    }
    int n() {return numVertex;}
    int e() {return numEdge;}
    int first (int v){
        for(int i=0;i<numVertex;i++)
            if(matrix[v][i]!=0) return i;
        return numVertex;
    }
    int next(int v,int w){
        for(int i=w+1;i<numVertex;i++)
            if(matrix[v][i]!=0)
                return i;
        return numVertex;
    }
    void setEdge(int v1,int v2,int wt){
        if(wt<=0)
            cout<<"Illegal weight value"<<endl;
        else
       {
           if(matrix[v1][v2]==0)   numEdge++;
           matrix[v1][v2]=wt;
       }
    }
    void delEdge(int v1,int v2){
        if(matrix[v1][v2]!=0)   numEdge--;
        matrix[v1][v2]=0;
    }
    bool isEdge(int i,int j)
    {return matrix[i][j]!=0;}
    int weight(int v1,int v2)   {return matrix[v1][v2];}
    int getMark(int v)  {return mark[v];}
    void setMark(int v,int val)     {mark[v]=val;}
};

/*void graphTraverse(Graph* G){
    int v;
    for(v=0;v<G->n();v++)
        G->setMark(v,UNVISITED);
    for(v=0;v<G->n();v++)
        if(G->getMark(v)==UNVISITED)
            dotraverse(G,v);
}*/

void DFS(Graph*G,int v){
    PreVisit(G,v);
    G->setMark(v,VISITED);
    for(int w=G->first(v);w<G->n();w=G->next(v,w))
        if(G->getMark(w)==UNVISITED)
            DFS(G,w);
    PostVisit(G,v);
}

void BFS(Graph* G,int start,Queue<int>* Q){
    int v,w;
    Q->enqueue(start);
    G->setMark(start,VISITED);
    while(Q->length()!=0) {
        v=Q->dequeue();
        PreVisit(G,v);
        for(w=G->first(v);w<G->n();w=G->next(v,w))
        if(G->getMark(w)==UNVISITED) {
            G->setMark(w,VISITED);
            Q->enqueue(w);
        }
    }
}

class DijkElem{
public:
    int vertex,diatance;
    DijkElem() {vertex=-1;distance=-1;}
    DijkElem(int v,int d) {vertex=v;distance=d;}
};
class minIntCompare {
public:
    static bool prior(int x, int y) { return x<y; }
};
class maxIntCompare{
public:
    static bool prior(int x,int y) {return x>y;}
};
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

void Dijkstra(Graph*G,int*D,int s) {
    int i,v,w;
    DijkElem temp;
    DijkElem E[G->e()];
    temp.distance=0; temp.vertex=s;
    E[0]=temp;
    heap<DijkElem,DDComp> H(E,1,G->e());
    for(i=0;i<G->n();i++){
        do{
            if(H.size()==0) return;
            temp=H.removefirst();
            v=temp.vertex;
        }while(G->getMark(v)==VISITED);
        G->setMark(v,VISITED);
        if(D[v]==INFINITY) return;
        for(w=G->first(v);w<G->n();w=G->next(v,w))
            if(D[w]>(D[v]+G->weight(v,w))) {
                D[w]=D[v]+G->weight(v,w);
                temp.distance=D[w]; temp.vertex=w;
                H.insert(temp);
            }
    }
}

int main()
{
    return 0;
}
