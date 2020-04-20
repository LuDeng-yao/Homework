#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> C;//两序列的并集
    int n,data1,data2;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>data1;
        C.push_back(data1);
    }
    for(int i=0; i<n; i++)
    {
        cin>>data2;
        C.push_back(data2);
    }
    sort(C.begin(),C.end());  //升序排序 ，取消冒泡 
    cout<<C[n-1];
}
