#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

int main(){
    srand((int)time(0));
    int m,n;
    m=rand()%30+20;
    n=rand()%30+20;
    ofstream fout("test.txt",ios::trunc);
    cout<<"新的测试数据"<<endl;
    cout<<m<<" "<<n<<endl;
    fout<<m<<" "<<n<<"\n";
    int k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            k=rand()%30+1;
            fout<<k<<",";
            cout<<k<<",";
        }
        k=rand()%30+1;
        fout<<k<<"\n";
        cout<<k<<endl;

    }
    fout.close();
    cout<<"新的测试数据已更新到test.txt"<<endl;
    system("pause");
    return 0;
}
