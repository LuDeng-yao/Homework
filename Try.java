package testnew;

import java.util.*;

public class Try {
    public static void main(String[] args) {

        for(int i =0;i<10;i++){ 
            student ss=new student(); 
            Num n = new Num();
            n.setNum(i);
            Num.list.add(n);
            ss.setId(i);
            int k=i+8;
            ss.setGrade(k);
            student.stu.add(ss);
            
        }
        System.out.println("集合长度为"+student.stu.size());

        for(int j=0;j<student.stu.size();j++){

        	System.out.println("每个实体对象值为"+student.stu.get(j).getGrade());
            
        }
        
    }
}

class student{
	private int id;
	private int grade;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getGrade() {
		return grade;
	}
	public void setGrade(int grade) {
		this.grade = grade;
	}
    static List<student> stu=new ArrayList<student>();
    public static void add(int j)
    {
    	stu.get(j).setGrade(stu.get(j).getGrade()+10);
    }
}
class Num{
    
    private int num;
    public int getNum() {
        return num;
    }
    public void setNum(int num) {
        this.num = num;
    }
    static List<Num> list = new ArrayList<Num>();
}
