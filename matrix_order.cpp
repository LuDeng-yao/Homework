#include<iostream>
#include<stdio.h>
using namespace std;

int Max=111111111;

void Print(int(*S)[7], int i, int j){
    if (i == j){
        cout << "A";
        cout << i;
    }
    else{
        cout << "(";
        Print(S, i, S[i][j]);
        Print(S, S[i][j] + 1, j);
        cout << ")";
    }
}
//对于一个矩阵规模序列P为{5，10，3，12，5，50，6}
void MtrixChainOrder(int P[], int(*M)[7], int(*S)[7]){
    int i, l, j, k, q;
    for (i = 1; i < 7; i++){
        //即只有一个矩阵时相乘次数为0，Ai~Ai
        M[i][i] = 0;
    }
    //寻找最佳的相乘次数，2个矩阵，3个矩阵...一直到n个矩阵，l控制矩阵长度
    for (l = 2; l < 7; l++){
        //i控制矩阵的其实位置
        for (i = 1; i < 7 - l + 1; i++){
            //j控制矩阵的结束位置
            j = i + l - 1;
            M[i][j] = 111111111;
            for (k = i; k < j; k++){
                q = M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (q < M[i][j]){
                    //将小的赋值次数赋值给M[i,j]
                    M[i][j] = q;
                    //S记录Ai与Aj之间最佳分配位置
                    S[i][j] = k;
                }
            }
        }
    }
    Print(S,1,6);
}

int main(){
    int p[7];
    int M[7][7];
    int S[7][7];
    cout<<"Please input the dimensions: "<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>p[i];
    }
    MtrixChainOrder(p,M,S);
    return 0;
}