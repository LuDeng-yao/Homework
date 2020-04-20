package testnew;

import java.util.Scanner;

public class Arraytest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int x;
		int numbers[] = new int[100];
		double sum = 0;
		int cnt = 0;
		x = in.nextInt();
		while(x!=-1)
		{
			numbers[cnt]=x;
			sum+=x;
			cnt++;
			x=in.nextInt();
		}
		if(cnt>0)
		{
			double average=sum/cnt;
			System.out.println("average: "+average);
			for(int i=0;i<cnt;i++)
			{
				if(numbers[i]>average)
				{
					System.out.println(numbers[i]);
				}
			}
		}
	}

}
