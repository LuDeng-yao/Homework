package testnew;

import java.util.Scanner;

public class Arraytestmn {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int len=50;
		int s[][];
		int a=0;
		int b=0;
		s=new int[len][len];
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<2;j++)
			{
				s[i][j]=in.nextInt();
				if(s[i][j]>s[a][b])
				{
					a=i;
					b=j;
				}
			}
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<2;j++)
			{
				System.out.print(s[i][j]);
				System.out.print('\t');
			}
		}
		System.out.println('\n'+"MAX: "+s[a][b]);
	}

}
