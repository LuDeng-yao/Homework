/********************
 * 两个足够聪明的人玩轮流取石头的游戏，谁取到最后一个石头谁就赢了，他们一次只能取1个、3个、7个或8个石头
 * 写一程序判断n个石头时先取的人是输还是赢。

 * 输入格式:
 * 一个整数n，其值不超过10000000。

 * 输出格式:
 * 如果先取的人赢，请以单独一行输出1，否则输出0。
********************/
#include<iostream>
#include<stdio.h>
using namespace std;

void fun(int n){
    if (n >= 14) {
        float temp = float((n - 13) % 15) / 2;
        if (temp == 1 || temp == 2 || temp == 3 || temp == 4) {
           cout<<"0"<<endl;
        }
        else
            cout<<"1"<<endl;
    }
    else {
        float temp = float(n) / 2;
        if (temp == 1 || temp == 2 || temp == 3) {
            cout<<"0"<<endl;
        }
        else
            cout<<"1"<<endl;
    }
}

int main(){
    int n;
    while(cin>>n){
        fun(n);
    }
    return 0;
}