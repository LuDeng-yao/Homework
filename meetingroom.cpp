/************************************
 * 假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。
 * 设计一个有效的 贪心算法进行安排。
 * （这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个 顶点，不相容活动间用边相连。
 * 使相邻顶点着有不同颜色的最小着色数，相应于要找的最小 会场数。）
 * 输入格式:
 * 第一行有 1 个正整数k，表示有 k个待安排的活动。 接下来的 k行中，每行有 2个正整数，分别表示 k个待安排的活动开始时间和结束时间。
 * 时间 以 0 点开始的分钟计。
 * 输出格式:
 * 输出最少会场数。
************************************/
#include<iostream>
#include<stdio.h>
using namespace std;

int k;//活动数量
int room;//需要的会场数量
void sort(int a[][2],int k){//按结束时间从大到小排
    for(int j=1;j<k;j++){
        int temp1=a[j][0];
        int temp2=a[j][1];
        int i=j-1;
        while(i>=0 && a[i][1]<temp2){
            a[i+1][0]=a[i][0];
            a[i+1][1]=a[i][1];
            i--;
        }
        a[i+1][0]=temp1;
        a[i+1][1]=temp2;
    }
}
void sort2(int a[][2],int num){//按开始时间从大到小排
    for(int j=1;j<num;j++){
        int temp1=a[j][0];
        int temp2=a[j][1];
        int i=j-1;
        while(i>=0 && a[i][0]<temp1){
            a[i+1][0]=a[i][0];
            a[i+1][1]=a[i][1];
            i--;
        }
        a[i+1][0]=temp1;
        a[i+1][0]=temp2;
    }
}
int main(){
    cin>>k;
    int meeting[k][2]={0};//记录活动开始、结束的时间
    for(int i=0;i<k;i++){
        cin>>meeting[i][0]>>meeting[i][1];
    }
    sort(meeting,k);
    room=1;
    int flag=0;
    int time[k];//记录每个会场的开始时间
    time[0]=meeting[0][0];
    for(int i=1;i<k;i++){
        flag=0;
        sort2(meeting,room);
        for(int j=0;j<room;j++){
            if(meeting[i][1]<=time[j]){
                flag=1;
                time[j]=meeting[i][0];
                break;
            }
        }
        if(flag==0){
            time[room]=meeting[i][0];
            room++;
        }
        flag=0;
    }
    cout<<room<<endl;
    return 0;
}