package testnew;

import java.util.Scanner;

public class Teststring {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		String s=new String("sentence: ");
		String s2=new String("friendship ");
		String s3,s4,s5;
		s3="is ";
		s4="power.";
		s5=in.nextLine();
		System.out.println(s+s2+s3+s4+12+(23+34)+s5);
		System.out.println(s5.equals("bye"));
		System.out.println("power.".compareTo(s4));
		System.out.println(s3.length());
		System.out.println(s.charAt(2));
		for(int i=0;i<s2.length();i++)
		{
			System.out.println(s2.charAt(i));
		}
		System.out.println(s2.substring(3, 6));
		System.out.println(s.indexOf('c'));
		//不可修改字符串原值
		String s6=s4.toUpperCase();
		System.out.println(s6);
	}

}
