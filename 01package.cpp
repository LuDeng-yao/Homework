/*****************************
 * 给定n(n<=100)种物品和一个背包。物品i的重量是wi，价值为vi，背包的容量为C(C<=1000)。
 * 问:应如何选择装入背包中的物品，使得装入背包中物品的总价值最大? 
 * 在选择装入背包的物品时，对每种物品i只有两个选择：装入或不装入。不能将物品i装入多次，也不能只装入部分物品i。

 * 输入格式:
 * 共有n+1行输入： 第一行为n值和c值，表示n件物品和背包容量c；
 *  接下来的n行，每行有两个数据，分别表示第i(1≤i≤n)件物品的重量和价值。

 * 输出格式:
 * 输出装入背包中物品的最大总价值。
 *****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int dp[105][1020] = {0};
int n,c;
int w[105],v[105];

void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=c;j++){
			if(j<w[i]){				
				dp[i+1][j] = dp[i][j];
			}
			else{
				dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
			}
		}
	}
}

int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	solve();
	cout<<dp[n][c]<<endl;
	return 0;
}