package shiyan1;

import java.util.*;

public class Employee {
	
	private int userName;//员工姓名
	private int gender;//员工性别
	private int roleId;//员工职位，0=普通职员，else,roleId=departId
	private int empNo;//员工编号
	private int departId;	//员工所在部门编号
	static List<Employee> emp=new ArrayList<Employee>();
	
	public int getUserName() {
		return userName;
	}
	public void setUserName(int userName) {
		this.userName = userName;
	}
	public int getGender() {
		return gender;
	}
	public void setGender(int gender) {
		this.gender = gender;
	}
	public int getRoleId() {
		return roleId;
	}
	public void setRoleId(int roleId) {
		this.roleId = roleId;
	}
	public int getEmpNo() {
		return empNo;
	}
	public void setEmpNo(int empNo) {
		this.empNo = empNo;
	}
	public int getDepartId() {
		return departId;
	}
	public void setDepartId(int departId) {
		this.departId = departId;
	}

	static void getdepartHead(int departId)
	{
		for(int i=0;i<emp.size();i++)
		{
			if(emp.get(i).departId==departId)
			{
				System.out.println(emp.get(i).getUserName());
				break;
			}
		}
	}
	static String getsgender(int gen) {
		String sgender=null;
		if(gen==1)
			sgender="Male";
		else if(gen==2)
			sgender="Female";
		else
			sgender="Unknown";
		return sgender;
	}
	static void showdemembers(int deId) {
		for(int i=0;i<emp.size();i++)
		{
			Employee employees=new Employee();
			employees=Employee.emp.get(i);
			if(employees.getDepartId()==deId)
				System.out.println("\t\temployee"+employees.getUserName()+"\t\t"+employees.getEmpNo()+"\t\t"+getsgender(employees.getGender()));
		}
	}
	public static int getemauth(int empNo) {
		for(int i=0;i<emp.size();i++)
		{
			Employee employees=new Employee();
			employees=Employee.emp.get(i);
			if(employees.getEmpNo()==empNo)
				return employees.getDepartId();
		}
		return 0;
	}
	public static void showemployeeinfo(int id){
		Employee employees=new Employee();
		for(int i=0;i<emp.size();i++) {
			employees=Employee.emp.get(i);
			if(employees.getEmpNo()==id)
				break;
		}
		String position=null;
		if(employees.getRoleId()==0)
			position="Staff";
		else if(employees.getRoleId()>=1 && employees.getRoleId()<=5)
			position="Manager";
		
		String sex=null;
		if(employees.getGender()==1)
			sex="Male";
		else if(employees.getGender()==2)
			sex="Female";
		int deid=employees.getDepartId();
		System.out.println("*********************************");
		System.out.println("Current Employee Information");
		System.out.println("\tEmployee number: "+employees.getEmpNo());
		System.out.println("\tName: employee"+employees.getUserName());
		System.out.println("\tGender: "+sex);
		System.out.println("Department: ");
		Department.showDepart(deid);
		System.out.println("Position: "+position);
		System.out.println("Salary situation: ");
		Performance.showPerformance(employees.getEmpNo());
		System.out.println("*********************************");
	}
	public int getId(int userName)
	{
		for(int i=0;i<emp.size();i++)
		{
			Employee employees=new Employee();
			employees=emp.get(i);
			if(employees.getUserName()==userName)
			{
				empNo=employees.getEmpNo();
				break;
			}
		}
		return empNo;
	}
}
