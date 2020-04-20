#include <iostream>
#include<stdio.h>
#include<math.h>
#define UNVISITED 0
#define VISITED 1
#define defaultSize 100


using namespace std;

/*
//compute shortest path distance from "s".
//return these distances in "D".
int minVertex(Graph*G,int*D){
    int i,v=-1;
    for(i=0;i<G->n();i++)
        if(G->getMark(i)==UNVISITED)    {v=i;break;}
    for(i++;i<G->n();i++)
        if((G->getMark(i)==UNVISITED)&&(D[i]<D[v]))
            v=i;
    return v;
}
void Dijkstra(Graph* G,int* D,int s){
    int i,v,w;
    for(i=0;i<G->n();i++){
        v=minVertex(G,D);
        if(D[v]==INFINITY) return;
        G->setMark(v,VISITED);
        for(w=G->first(v);w<G->n();w=G->next(v,w))
            if(D[w]>(D[v]+G->weight(v,w)))
                D[w]=D[v]+G->weight(v,w);
    }
}*/
