/***********************
 *  There is a horse racing between QW and TJ. SB is to be the judge. QW and TJ both have horses. 
 * Each horse has an ability that is different from any other one. They arrange their horses in a fixed order. 
 * The first horse of QW's will compete to the first of TJ's, the second to the second, and so on. 
 * Horse with higher ability will beat horse with lower ability. 
 * During the n rounds of racings, the one who win most of them will win finally. The loser will lost his horses. 
 * Of course, draw game is probably to happen in which situation SB will get all the horses. 
 * You should tell SB if he has chance to get the horses.
 * Input:
    The first line contains an integer n. 1<=n<=100.
    The second line contains n integers representing the ability of QW's horses.
    The third line also contains n integers representing the ability of TJ's horses.
 * Output:
    If draw game is possible to happen, print "YES", else print "NO".
***********************/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int compete(int qw[100],int tj[100]){
    int win = 0;
    int fail = 0;  
    int ib = 0, jb = 0;  
    int ie = n - 1, je = n - 1;
    while (ib <= ie)  {   
        if(tj[ib]>qw[je]){
            ib++;
            je--;
            win++;
        }
        else if(tj[ie]<qw[jb]){
            ie--;
            jb++;
            fail++;
        }
        else if(tj[ib]<qw[jb]){
            fail++;
            ib++;
            je--;
        }
        else if(tj[ie]<qw[je]){
            fail++;
            ib++;
            je--;
        }
        else if(tj[ib]>qw[jb]){
            win++;
            ib++;
            jb++;
        }
        else if(tj[ie]>qw[je]){
            win++;
            ie--;
            je--;
        }
    } 
    int res=win-fail;
    return res;
}
int main()
{
    while(cin>>n){
        int QW[100],TJ[100];
        for(int i=0;i<n;i++)
            cin>>QW[i];
        for(int j=0;j<n;j++)  
            cin>>TJ[j];
        sort(QW,QW+n);
        sort(TJ,TJ+n);  
        int a=compete(QW,TJ);
        int b=compete(TJ,QW);
        if(n%2==1){
            cout<<"NO"<<endl;
        }
        else if(a*b>=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
