/*******************************************
 * 一座长度为n的桥，起点的一端坐标为0，且在整数坐标i处有a[i]个石头【0<=a[i]<=4】
 *  一只青蛙从坐标0处开始起跳，一步可以跳的距离为1或2或3【即每一步都会落在整数点处】
 * 青蛙落在i处会踩着该点的所有石头，求青蛙跳出这座桥最少踩多少个石头？并且输出依次跳 过的坐标点路线
 * 如果存在多种路线，输出字典序最小的那一条。
 * 输入格式:
 * 第一行整数n(<150000)，接着下一行会有n+1个由空格隔开的整数,即桥上各个坐标处石头数量。
 * 输出格式:
 * 第一行为踩着最少石头个数，第二行为依次跳过的坐标点【字典序最小的】。
*******************************************/

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 150005;
int n;
int v[MAX_N];
int fa[MAX_N];

void show(int i){
    if(i) 
        cout << " ";
    cout << i;
    if(i > n-3) 
        return;
    else 
        show(fa[i]);
}

int main(){
    cin >> n;
    memset(v, 0, sizeof(v));
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }

    for(int i = n-3; i >= 0; i--){
        int tmp = i+3;
        if(v[i+2] <= v[i+3]) tmp = i+2;
        if(v[tmp] >= v[i+1]) tmp = i+1;
        v[i] = v[i] + v[tmp];
        fa[i] = tmp;
    }
    cout << v[0] << endl;
    show(0);
    return 0;
}

//这应该是没有考虑字典序输出
// #include <iostream>
// #include <algorithm>
// using namespace std;

// void FCTB(int a[],int n){
// 	if(n<=3){
// 		cout<<"0"<<endl;
// 	}
//     else{
//         int b[n];
//         int len=0,temp=0;
//     	for(int i=n-4;i>=0;i--){
//     	    temp=min(min(a[i]+a[i+1],a[i]+a[i+2]),a[i]+a[i+3]);
//             if(temp==a[i]+a[i+1]){
//                 b[len++]=i+1;
//             }
//             else if(temp==a[i]+a[i+2]){
//                 b[len++]=i+2;
//             }
//             else{
//                 b[len++]=i+3;
//             }
//             a[i]=temp;
//         }
//         b[len++]=0;
// 		cout<<a[0]<<endl;
//         for(int j=len-1;j>=1;j--){
//             if(b[j]!=b[j-1])
//                 cout<<b[j]<<" ";
//         }
//         cout<<b[0]<<endl;
// 	}
// } 

// int main(){
// 	int n;
// 	cin>>n;
// 	int *a = new int [n+1];
// 	for(int i = 0;i<n;i++){
// 		cin>>a[i];
// 	}
// 	FCTB(a,n+1);
// 	return 0;	
// }