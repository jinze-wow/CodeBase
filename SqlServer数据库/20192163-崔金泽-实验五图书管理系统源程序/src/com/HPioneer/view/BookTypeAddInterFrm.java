package com.HPioneer.view;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.LineBorder;

import com.HPioneer.dao.BookTypeDao;
import com.HPioneer.model.BookType;
import com.HPioneer.util.DbUtil;
import com.HPioneer.util.StringUtil;
import com.mysql.jdbc.Connection;

public class BookTypeAddInterFrm extends JInternalFrame {
	private JTextField bookTypeNameTxt;
    private JTextArea bookTypeDescTxt;

    private DbUtil dbUtil = new DbUtil();
    private BookTypeDao bookTypeDao = new BookTypeDao();
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					BookTypeAddInterFrm frame = new BookTypeAddInterFrm();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public BookTypeAddInterFrm() {
		setIconifiable(true);
		setClosable(true);
		setTitle("图书类别添加");
		setBounds(100, 100, 450, 300);
		
		JLabel lblNewLabel = new JLabel("图书类别名称：");
		
		JLabel lblNewLabel_1 = new JLabel("图书类别描述：");
		
		bookTypeNameTxt = new JTextField();
		bookTypeNameTxt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		bookTypeNameTxt.setColumns(10);
		
	    bookTypeDescTxt = new JTextArea();
		
		JButton btnNewButton = new JButton("添加");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			    bookTypeAddActionPerformed(e);
			}
		});
		btnNewButton.setIcon(new ImageIcon(BookTypeAddInterFrm.class.getResource("/images/add.png")));
		
		JButton btnNewButton_1 = new JButton("重置");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				resetValueActionPerformed(e);
			}
		});
		btnNewButton_1.setIcon(new ImageIcon(BookTypeAddInterFrm.class.getResource("/images/reset.png")));
		GroupLayout groupLayout = new GroupLayout(getContentPane());
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
						.addGroup(groupLayout.createSequentialGroup()
							.addGap(68)
							.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
								.addComponent(lblNewLabel)
								.addComponent(lblNewLabel_1)))
						.addGroup(groupLayout.createSequentialGroup()
							.addGap(83)
							.addComponent(btnNewButton)))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(groupLayout.createParallelGroup(Alignment.TRAILING)
						.addGroup(groupLayout.createSequentialGroup()
							.addGap(34)
							.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
								.addComponent(bookTypeNameTxt, GroupLayout.DEFAULT_SIZE, 162, Short.MAX_VALUE)
								.addComponent(bookTypeDescTxt, GroupLayout.DEFAULT_SIZE, 162, Short.MAX_VALUE)))
						.addGroup(groupLayout.createSequentialGroup()
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(btnNewButton_1)))
					.addGap(78))
		);
		groupLayout.setVerticalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGap(51)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel)
						.addComponent(bookTypeNameTxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addGap(35)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel_1)
						.addComponent(bookTypeDescTxt, GroupLayout.PREFERRED_SIZE, 79, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED, 35, Short.MAX_VALUE)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton_1)
						.addComponent(btnNewButton))
					.addGap(26))
		);
		getContentPane().setLayout(groupLayout);
		
		//显示文本域边框
		bookTypeDescTxt.setBorder(new LineBorder(new java.awt.Color(127,157,185),1,false));

	}
	/**
	 * 图书类别添加事件处理
	 * @param e
	 */
    protected void bookTypeAddActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String bookTypeName = this.bookTypeNameTxt.getText();
	    String bookTypeDesc = this.bookTypeDescTxt.getText();
        if(StringUtil.isEmpty(bookTypeName)){
        	JOptionPane.showMessageDialog(null,"图书类别不能为空");
        }
        BookType bookType = new BookType(bookTypeName,bookTypeDesc);
        Connection con = null;
        try{
        	con=dbUtil.getCon();
        	int n = bookTypeDao.add(con, bookType);
        	if(n==1){
        		JOptionPane.showMessageDialog(null,"图书类别添加成功");	
        		resetValue();
        	}else{
        		JOptionPane.showMessageDialog(null,"图书类别添加失败");	
        	}
        }catch(Exception e1){
        	e1.printStackTrace();
        	JOptionPane.showMessageDialog(null,"图书类别添加失败");	      	
        }finally{
        	try{
        	dbUtil.closeCon(con);
        	}catch (Exception e1) {
				// TODO: handle exception
			}
        	
        }
    }

	/**
     * 重置事件处理
     * @param evt
     */
	private void resetValueActionPerformed(ActionEvent evt) {
		// TODO Auto-generated method stub
		this.resetValue();
	}

	/**
	 * 重置表单
	 */
	private void resetValue() {
		this.bookTypeNameTxt.setText("");
		this.bookTypeDescTxt.setText("");
	}
}
