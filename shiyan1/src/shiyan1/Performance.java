package shiyan1;

import java.util.*;

public class Performance {
	private int salary;//工资
	private int allowance;//津贴
	private int bonus;//奖金
	private int amount;//薪酬总额
	private int empNo;
	static List<Performance> per=new ArrayList<Performance>();
	
	public int getSalary() {
		return salary;
	}
	public void setSalary(int salary) {
		this.salary = salary;
	}
	public int getAllowance() {
		return allowance;
	}
	public void setAllowance(int allowance) {
		this.allowance = allowance;
	}
	public int getBonus() {
		return bonus;
	}
	public void setBonus(int bonus) {
		this.bonus = bonus;
	}
	public int getAmount() {
		return amount;
	}
	public void setAmount(int amount) {
		this.amount = amount;
	}
	public int getEmpNo() {
		return empNo;
	}
	public void setEmpNo(int empNo) {
		this.empNo = empNo;
	}


	static Comparator <Performance> comparator =new Comparator <Performance>() {
		public int compare(Performance p1, Performance p2) {
			//先排performance
			if(p1.getAmount()!=p2.getAmount()) {
				return p2.getAmount()-p1.getAmount();
			}
			else {
				return p1.getEmpNo()-p2.getEmpNo();
			}
		}
	};

	public static void sortperformance(int deperid) {
		Collections.sort(per, comparator);
		if(deperid==0) {
			for(int j=0;j<Performance.per.size();j++)
			{
				Performance performances=new Performance();
				performances=Performance.per.get(j);
				int Id=performances.getEmpNo();
				showPerformance(Id);
			}
		}
		else if(deperid>=1&&deperid<=5) {
			for(int j=0;j<Performance.per.size();j++)
			{
				Performance performances=new Performance();
				performances=Performance.per.get(j);
				int Id=performances.getEmpNo();
				if(Employee.getemauth(Id)==deperid) {
					showPerformance(Id);
				}
			}
		}
		else
		{
			System.out.println("Sorry, there is no such department or department information missing.");
		}
	}

	public static void showPerformance(int empNo) {
		Performance performances=new Performance();
		for(int i=0;i<per.size();i++) {
			performances=Performance.per.get(i);
			if(performances.getEmpNo()==empNo) {
				System.out.println("Employee: ");
				System.out.println("\t\tEmployee id: "+performances.getEmpNo());
				System.out.println("Performance: ");
				System.out.println("\t\tsalary: "+performances.getSalary()+"\t\tallowance: "+performances.getAllowance()+"\t\tbonus: "+performances.getBonus()+"\n");
				System.out.println("\t\tTotal: "+performances.getAmount());
				break;
			}
		}
	}
}
