package shiyan1;

import java.util.*;
import shiyan1.Employee;
import shiyan1.Department;
import shiyan1.Performance;

public class Management {
	static int uName=0;
	static int empid=0;
	static int deNum=0;
	static int deId=0;
	static int sa=0;
	static int al=0;
	static int bo=0;
	static int roId=0;
	static int am=0;
	static int gen=0;
		
	public static void init() {
		
		for(int i=1;i<=100;i++){
			Employee employees=new Employee();
			Department departments=new Department();
			Performance performances=new Performance();
			uName=i;
			empid=i;
			deNum++;
			deId=(i-1)/20+1;
			sa=(int)(Math.random()*4000+3500);
			al=(int)(Math.random()*800+300);
			bo=(int)(Math.random()*3000+1000);
			if(i%20==1)
			{
				roId=deId;
				sa=sa+(int)(Math.random()*300+2000);
				al=al+(int)(Math.random()*80+100);
				bo=bo+(int)(Math.random()*30+100);
			}
			am=sa+al+bo;
			gen=(int)(Math.random()*2+1);
			employees.setDepartId(deId);
			employees.setEmpNo(empid);
			employees.setGender(gen);
			employees.setRoleId(roId);
			employees.setUserName(uName);
			performances.setAllowance(al);
			performances.setAmount(am);
			performances.setBonus(bo);
			performances.setEmpNo(empid);
			performances.setSalary(sa);

			if(deNum==20)
			{
				departments.setDepartId(deId);
				departments.setDepartNum(deNum);
				Department.dep.add(departments);
				deNum=0;
			}
			Employee.emp.add(employees);
			Performance.per.add(performances);
			roId=0;
		}
	}
		
	static int Id;
	@SuppressWarnings("resource")
	public static void menu() {
		Scanner in=new Scanner(System.in);
		System.out.println("***************WELCOME***************");
		int flag=1;
		while(flag==1) 
		{
			System.out.println("Menu:");
			System.out.println("1\tQuery department information of a department");
			System.out.println("2\tTotal performance ranking");
			System.out.println("3\tRank the performance of members of a department");
			System.out.println("4\tQuery employee performance by employee ID number");
			System.out.println("5\tQuery employee information by employee ID number");
			System.out.println("6\tExit system");
			int i=in.nextInt();
			switch (i) {
				case 1: {//显示一个指定部门的员工信息
					System.out.println("Please enter the corresponding number of the Department you want to query: ");
					System.out.println("Here are: ");
					System.out.println("1\tmarket Department\t\t2\tdevelopment Department\n3\tinformation Department\t\t4\tproduction Department\n5\tfinance Department");
					int departId=in.nextInt();
					Department.showDepart(departId);
					Department.showMembers(departId);
					break;
				}
				case 2: {//根据总业绩排序
					System.out.println("Rank the total performance of all members:");
					Performance.sortperformance(0);
					break;
				}
				case 3: {//对某个部门员工进行业绩排序
					System.out.println("Please enter the number of departments where you want to see the employee performance ranking: ");
					System.out.println("1\tmarket Department\t\t2\tdevelopment Department\n3\tinformation Department\t\t4\tproduction Department\n5\tfinance Department");
					int deperId=0;
					deperId=in.nextInt();
					Performance.sortperformance(deperId);
					break;
				}
				case 4: {//通过员工编号查询业绩
					System.out.println("The ID number is probably between 1 and 100");
					Id=in.nextInt();
					if(Id==0)
						System.out.println("There is no such employee here.");
					else
						Performance.showPerformance(Id);
					break;
				}
				case 5:{//通过员工编号显示员工信息
					System.out.println("Please input the employee number: ");
					int id=in.nextInt();
					Employee.showemployeeinfo(id);
					break;
				}
				case 6: {//退出系统
					System.out.println("*****************Bye~*****************");
					flag=0;
					break;
				}
				default:{
					System.out.println("Input error.");
					System.out.println("****************Again~****************\n");
					continue;
				}
			}
		}
	}
	public static void main(String[] args){
		init();
		menu();
	}
}

