package testnew;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class AppGraphInOut {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new APPFrame();
	}
}

class APPFrame extends JFrame{
	JTextField in=new JTextField(10);
	JButton btn=new JButton("��ƽ��");
	JLabel out=new JLabel("������ʾ����ı�ǩ");
	
	public APPFrame() {
		setLayout( new FlowLayout());
		getContentPane().add(in);
		getContentPane().add(btn);
		getContentPane().add(out);
		btn.addActionListener(new BtnActionAdapter());
		setSize(400,100);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setVisible(true);
	}
	class BtnActionAdapter implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String s=in.getText();
			double d=Double.parseDouble(s);
			double sq=d*d;
			out.setText(d+"��ƽ���ǣ�"+sq);
		}
	}
}
