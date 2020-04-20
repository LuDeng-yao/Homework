#include <iostream>
using namespace std;

#define n 8
#define m 9
int Max(int a,int b)
{
	return a>b?a:b;
}

int Lcs_Length(char *x, char *y,int c[][m+1],int i,int j) 
{
     if (i==0||j==0)
     {
		 c[i][j]=0;
     }
	 else if (c[i][j]>0)
	 {
		 return c[i][j];
	 }
	 else 
	 {
        if (x[i]==y[j])
        {
			c[i][j]=Lcs_Length(x,y,c,i-1,j-1)+1;
        } 
        else
        {
           c[i][j]=Max(Lcs_Length(x,y,c,i,j-1),Lcs_Length(x,y,c,i-1,j));
        }
	 }
	 return c[i][j];
}

int main()
{
//    char x[N+1] = {'\0','1','0','0','1','0','1','0','1'};  
//    char y[M+1] = {'\0','0','1','0','1','1','0','1','1','0'};
    cout<<"Input: "<<endl;
    char x[n+1]={'\0'};
    char y[m+1]={'\0'};
    for(int i=0;i<n;i++){
        cin>>x[i+1];
    }
    for(int j=0;j<m;j++){
        cin>>y[j+1];
    }
   int c[n+1][m+1]={0};
   cout<<Lcs_Length(x, y,c,n,m);
   return 0;
}