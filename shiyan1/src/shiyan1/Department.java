package shiyan1;

import java.util.*;

public class Department {

	private int departId;//���ű��
	String departName;//��������	
	private int departNum;//��������
	static List<Department> dep=new ArrayList<Department>();
	
	public int getDepartId() {
		return departId;
	}
	public void setDepartId(int departId) {
		this.departId = departId;
	}
	public int getDepartNum() {
		return departNum;
	}
	public void setDepartNum(int departNum) {
		this.departNum = departNum;
	}
	static String department;
	public static String getdepartName(int departId) { 		
		if(departId==1)
			department="Market Department";	
		else if(departId==2)	
			department="Development Department";	
		else if(departId==3)	
			department="Information Department";		
		else if(departId==4)	
			department="Production Department";	
		else if(departId==5)	
			department="Finance Development";
		else
			department="There is no this department. For any question please contact the adminstrator.";		
		return department;
	}
	
	static void getdepartNum(int departId) {
		for(int i=0;i<dep.size();i++)
		{
			if(dep.get(i).getDepartId()==departId)
			{
				System.out.println(dep.get(i).getDepartNum());
				break;
			}
		}
	}

	public static void showDepart(int departId) {
		//��ʾ������Ϣ
		System.out.println("Department Information: ");
		System.out.println("\tDepartment IDnumber: "+departId);
		System.out.println("\tDepartment name: "+getdepartName(departId));
		System.out.print("\tTotal number of Department: ");
		getdepartNum(departId);
		System.out.print("\tHead of the Department: employee");
		Employee.getdepartHead(departId);
	}
	public static void showMembers(int departId) {
		//��ʾ���Ű����ĳ�Ա��Ϣ������õ�Ա�����showEployee()����
		System.out.println("Member information of the department: ");
		System.out.println("\t\tName\t\t\tID\t\tGender");
		Employee.showdemembers(departId);
	}
	static int Num=0;
	public static void departNum(int departId)
	{
		for(int k=0;k<dep.size();k++)
		{
			Department departments=new Department();
			departments=dep.get(k);
			if(departments.departId==departId)
			{
				System.out.println(dep.get(k).getDepartNum());
				break;
			}
		}
	}
}
