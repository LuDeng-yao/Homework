package testnew;

import java.util.Scanner;

public class Selectway {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int x;
		int y;
		int z;
		System.out.println("Please input three number:");
		x = in.nextInt();
		y = in.nextInt();
		z = in.nextInt();
		int max=y;
		if(x>y)
		{
			max=x;
		}
		else if(z>x)
		{
			max=z;
		}
		System.out.println(max);
	}

}
